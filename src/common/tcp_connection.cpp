#include "stdafx.h"
#include "byte_buffer.h"
#include "tcp_connection.h"
#include "network_common.h"
#include "inet_address.h"
#include "packet.h"
#include "protobuf.h"

const static int DEFAULT_CIRCULAR_BUFFER_SIZE = 512;
TcpConnection::TcpConnection(IOService& io_service)
    : _io_service(io_service),
    _strand(io_service.service()),
    _socket(io_service.service()),
    _inetAddress(0)
{
}

TcpConnection::~TcpConnection()
{
    if (isOpen())
        _socket.close();


    _buffer.clear();
    std::cout << "connection destroyed." << std::endl;
}

void TcpConnection::setInetAddress(const InetAddress& inetAddress)
{
    _inetAddress = inetAddress;
}

void TcpConnection::connect()
{
    connect(_inetAddress);
}

void TcpConnection::connect(const InetAddress& inetAddress)
{
    setInetAddress(inetAddress);
    if (isOpen())
        shutdown();

    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::address::from_string(_inetAddress.host()), _inetAddress.port());

    _socket.async_connect(
        endpoint,
        boost::bind(&TcpConnection::handleConnected, shared_from_this(), boost::asio::placeholders::error));
}

void TcpConnection::disconnect()
{

}

void TcpConnection::write(const byte* data, size_t size)
{
    if (data == nullptr || size == 0)
    {
        std::cout << "empty data." << std::endl;
        return;
    }

    boost::asio::async_write(
        _socket,
        boost::asio::buffer(data, size),
        _strand.wrap(
            boost::bind(
                &TcpConnection::handleWrite, 
                shared_from_this(), 
                boost::asio::placeholders::error, 
                boost::asio::placeholders::bytes_transferred
            )
        )
    );
}

void TcpConnection::write(const uint32& opcode, const byte* message_data, size_t message_size)
{
    if (message_data == nullptr || message_size == 0)
    {
        std::cout << "empty data." << std::endl;
        return;
    }

    ByteBuffer buffer;
    buffer << ServerPacket::HEADER_LENGTH + message_size;
    buffer << opcode;
    buffer.append(message_data, message_size);

    write(buffer.buffer(), buffer.size());
}

void TcpConnection::read()
{
    _socket.async_read_some(
        boost::asio::buffer(_recvBuffer),
        _strand.wrap(
            boost::bind(
                &TcpConnection::handleRead, 
                shared_from_this(), 
                boost::asio::placeholders::error, 
                boost::asio::placeholders::bytes_transferred
            )
        )
    );
}

void TcpConnection::shutdown()
{
    _socket.shutdown(boost::asio::socket_base::shutdown_both);
}

tcp::socket& TcpConnection::socket()
{
    return _socket;
}

bool TcpConnection::isOpen()
{
    return _socket.is_open();
}

void TcpConnection::setWriteCompletedCallback(const WriteCompletedCallback& cb)
{
    _writeCompletedCallback = cb;
}

void TcpConnection::setReadCompletedCallback(const ReadCompletedCallback& cb)
{
    _readComplectedCallback = cb;
}

void TcpConnection::setConnectionClosedCallback(const ConnectionClosedCallback& cb)
{
    _connectionClosedCallback = cb;
}

void TcpConnection::setConnectedCallback(const ConnectedCallback& cb)
{
    _connectedCallback = cb;
}

void TcpConnection::handleConnected(const boost::system::error_code& error)
{
    if(!error)
    {
        std::cout << "connection has been connected." << std::endl;

        read();
        if (_connectedCallback)
            _connectedCallback(shared_from_this());
    }
    else
    {
        std::cout << "connection error occured. error = " << error.message() << std::endl;
    }
}

void TcpConnection::handleWrite(
    const boost::system::error_code& error, // Result of operation.
    std::size_t bytes_transferred           // Number of bytes sent.
)
{
    if (error)
    {
        onError(error);
    }
    else
    {
        std::cout << "bytes_transferred = " << bytes_transferred << std::endl;
        if (_writeCompletedCallback)
        {
            _writeCompletedCallback(shared_from_this(), bytes_transferred);
        }
        else
        {
            std::cout << "write complected." << std::endl;
        }
    }
}

void TcpConnection::handleRead(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    if (error)
        return onError(error);

    if (bytes_transferred == 0)
    {
        std::cout << "oops, connection lost :(" << std::endl;
        return;
    }
    
    this->read();

    size_t bodyLen = 0;

    //ByteBufferPtr read_buffer(new ByteBuffer(_recvBuffer.data(), bytes_transferred));
    ByteBuffer read_buffer(_recvBuffer.data(), bytes_transferred);
    _buffer.append(read_buffer);

    std::vector<ServerPacketPtr> packetList;

    _buffer.set_rpos(0);
    while (_buffer.size() >= sizeof(ServerPacket))
    {
        size_t packet_len = 0;
        uint32 opcode = 0;

        _buffer >> packet_len;
        _buffer >> opcode;

        //数据包长度大于最大接收长度视为非法，干掉
        if (packet_len >= MAX_RECV_LEN || read_buffer.size() >= MAX_RECV_LEN || bytes_transferred != packet_len)
        {
            std::cout << "Warning: Read packet header length " << packet_len << " bytes (which is too large) on peer socket. (Invalid Packet?)" << std::endl;
            shutdown();
            return;
        }

        if (_buffer.size() < packet_len)
        {
            return;
        }
        else if (_buffer.size() >= packet_len)
        {
            //取得body长度
            bodyLen = packet_len - ServerPacket::HEADER_LENGTH;

            ServerPacketPtr packet(new ServerPacket());
            packet->len = packet_len;
            packet->opcode = opcode;

            packet->message = new byte[bodyLen];
            _buffer.read(packet->message, bodyLen);

            packetList.push_back(packet);
            _buffer.erase(0, packet_len);
            _buffer.set_rpos(0);
            _buffer.set_wpos(0);
        }
    }

    for (size_t i = 0; i < packetList.size(); ++i)
    {
        const ServerPacketPtr& packet = packetList[i];
        const uint32_t& opcode = packet->opcode;

        if (packet->message != NULL && _readComplectedCallback)
        {
            _readComplectedCallback(shared_from_this(), opcode, packet->message, bytes_transferred);
        }
        else
        {
            std::cout << "Warnning : empty proto message or not set read callback instance." << std::endl;
        }
    }

    packetList.clear();

}

void TcpConnection::onError(const boost::system::error_code& error)
{
    std::cout << "An error occured, code = " << error.value() << ", message = " << error.message() << std::endl;
    
    shutdown();
    switch (error.value())
    {
        case boost::asio::error::bad_descriptor:
        case boost::asio::error::eof:
        case boost::asio::error::operation_aborted:
        case boost::asio::error::connection_reset:
        {
            if (_connectionClosedCallback)
            {
                _connectionClosedCallback(shared_from_this());
            }
            break;
        }
    }
}
/*
bool TcpConnection::append_buffer_fragment(const ByteBufferPtr& buffer)
{
    _buffer.append(*buffer);
    while (_buffer.size() >= sizeof(ServerPacket))
    {
        size_t packet_len = 0;
        _buffer >> packet_len;

        //数据包长度大于最大接收长度视为非法，干掉
        if (packet_len >= MAX_RECV_LEN || buffer->size() >= MAX_RECV_LEN)
        {
            std::cout << "Warning: Read packet header length " << packet_len << " bytes (which is too large) on peer socket. (Invalid Packet?)" << std::endl;
            shutdown();
            return false;
        }

        if (_buffer.size() < packet_len)
        {
            return false;
        }
        else if (_buffer.size() >= packet_len)
        {
            ServerPacket* packet = (ServerPacket*)reinterpret_cast<const ServerPacket*>(_buffer.buffer());

            //跳过数据头的8字节
            _buffer.set_rpos(ServerPacket::HEADER_LENGTH);

            //取得body长度
            size_t bodyLen = packet_len - ServerPacket::HEADER_LENGTH;
            packet->message = new byte[bodyLen];
            _buffer.read(packet->message, bodyLen);

            _prepare_packet_list.push_back(*packet);
            //_buffer.erase(0, packet_len);
            _buffer.clear();
        }
        else
        {
            ServerPacket* packet = (ServerPacket*)reinterpret_cast<const ServerPacket*>(_buffer.buffer());

            //跳过数据头的8字节
            _buffer.set_rpos(ServerPacket::HEADER_LENGTH);

            //取得body长度
            size_t bodyLen = packet_len - ServerPacket::HEADER_LENGTH;
            packet->message = new byte[bodyLen];
            _buffer.read(packet->message, bodyLen);

            _prepare_packet_list.push_back(*packet);
            _buffer.erase(0, buffer->size());
            _buffer.set_rpos(0);
            _buffer.set_wpos(0);
        }
    }

    return (_prepare_packet_list.size() > 0);
}*/