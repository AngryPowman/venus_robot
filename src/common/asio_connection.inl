#include "asio_connection.h"

#include "stdafx.h"
#include "byte_buffer.h"
#include "tcp_connection.h"
#include "network_common.h"
#include "inet_address.h"
#include "packet.h"
#include "asio_connection.h"

AsioConnection::AsioConnection(IOService& io_service)
    : AsioConnection(io_service),
    _inetAddress(0)
{
}

AsioConnection::~AsioConnection()
{

}

void AsioConnection::setInetAddress(const InetAddress& inetAddress)
{
    _inetAddress = inetAddress;
}

void AsioConnection::connect()
{
    connect(_inetAddress);
}

void AsioConnection::connect(const InetAddress& inetAddress)
{
    setInetAddress(inetAddress);
    if (isOpen())
        shutdown();

    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::address::from_string(_inetAddress.host()), _inetAddress.port());

    _socket.async_connect(
        endpoint,
        boost::bind(&AsioConnection::handleConnected, shared_from_this(), boost::asio::placeholders::error));
}

void AsioConnection::disconnect()
{

}

void AsioConnection::write(const byte* data, size_t size)
{
    if (!data)
    {
        std::cout << "empty data." << std::endl;
        return;
    }

    boost::asio::async_write(
        _socket,
        boost::asio::buffer(data, size),
        _strand.wrap(
        boost::bind(
        &AsioConnection::handleWrite, 
        shared_from_this(), 
        boost::asio::placeholders::error, 
        boost::asio::placeholders::bytes_transferred
        )
        )
        );
}

void AsioConnection::read()
{
    _socket.async_read_some(
        boost::asio::buffer(_recvBuffer),
        _strand.wrap(
        boost::bind(
        &AsioConnection::handleRead, 
        shared_from_this(), 
        boost::asio::placeholders::error, 
        boost::asio::placeholders::bytes_transferred
        )
        )
        );
}

void AsioConnection::shutdown()
{
    _socket.shutdown(boost::asio::socket_base::shutdown_both);
}

tcp::socket& AsioConnection::socket()
{
    return _socket;
}

bool AsioConnection::isOpen()
{
    return _socket.is_open();
}


void AsioConnection::handleConnected(const boost::system::error_code& error)
{
    if(!error)
    {
        std::cout << "connection has been connected." << std::endl;
        //        if (_connectedCallback)
        //            _connectedCallback(shared_from_this());
    }
    else
    {
        std::cout << "connection error occured. error = " << error.message() << std::endl;
    }
}

void AsioConnection::handleWrite(
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
        //if (_writeCompletedCallback)
        //    _writeCompletedCallback(shared_from_this(), bytes_transferred);

        std::cout << "write complected." << std::endl;
    }
}

void AsioConnection::handleRead(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    if (error)
        return onError(error);

    if (bytes_transferred == 0)
    {
        std::cout << "oops, connection lost :(" << std::endl;
        return;
    }

    this->read();
    ByteBufferPtr read_buffer(new ByteBuffer(_recvBuffer.data(), bytes_transferred));
    if (append_buffer_fragment(read_buffer))
    {
        for (size_t i = 0; i < _prepare_packet_list.size(); ++i)
        {
            const uint32_t& opcode = _prepare_packet_list[i].opcode;
            const google::protobuf::Message* message = _prepare_packet_list[i].protoMessage();

            std::cout << "Network Message : [opcode = " <<  opcode << "]" << std::endl;

            //if (message != NULL && _readComplectedCallback)
            //    _readComplectedCallback(shared_from_this(), opcode, *message, bytes_transferred);

            std::cout << "Warnning : empty proto message!" << std::endl;
        }
    }
}

void AsioConnection::onError(const boost::system::error_code& error)
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
            //if (_connectionClosedCallback)
            //   _connectionClosedCallback(shared_from_this());

            break;
        }
    }
}

bool AsioConnection::append_buffer_fragment(const ByteBufferPtr& buffer)
{
    _buffer.append(*buffer);
    while (_buffer.size() >= sizeof(ServerPacket))
    {
        size_t packet_len = 0;
        _buffer >> packet_len;

        //���ݰ����ȴ��������ճ�����Ϊ�Ƿ����ɵ�
        if (packet_len >= MAX_RECV_LEN)
        {
            std::cout << "Warning: Read packet header length " << packet_len << " bytes (which is too large) on peer socket. (Invalid Packet?)" << std::endl;
            shutdown();
            return false;
        }

        if (_buffer.size() < packet_len)
        {
            return false;
        }
        else if (_buffer.size() == packet_len)
        {
            ServerPacket* packet = 
                (ServerPacket*)(reinterpret_cast<const ServerPacket*>(_buffer.buffer()));

            _prepare_packet_list.push_back(*packet);
            _buffer.clear();
        }
        else
        {
            ServerPacket* packet = 
                (ServerPacket*)(reinterpret_cast<const ServerPacket*>(_buffer.buffer()));

            _prepare_packet_list.push_back(*packet);
            _buffer.erase(0, packet_len);
            _buffer.set_rpos(0);
        }
    }

    return (_prepare_packet_list.size() > 0);
}