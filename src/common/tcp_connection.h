#ifndef TCP_CONNECTION_H_
#define TCP_CONNECTION_H_

#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/circular_buffer.hpp>  

#include "byte_buffer.h"
#include "packet.h"
#include "network_common.h"
#include "socket.h"

using namespace boost::asio::ip;

struct ServerPacket;
class Socket;
class TcpConnection
    : private boost::noncopyable, public std::enable_shared_from_this<TcpConnection>
{
public:
    TcpConnection(IOService& io_service);
    virtual ~TcpConnection();

public:
    __forceinline int handle()  //return native socket handle
    {
        return _socket->handle();
    }
    void setInetAddress(const InetAddress& inetAddress);
    void connect();
    void connect(const InetAddress& inetAddress);
    void shutdown();
    void close();
    void write(const byte* data, size_t size);
    void write(const uint32& opcode, const byte* data, size_t size);
    void read();
    tcp::socket& socket();
    bool is_open();

public:
    void setWriteCompletedCallback(const WriteCompletedCallback& cb);
    void setReadCompletedCallback(const ReadCompletedCallback& cb);
    void setConnectionClosedCallback(const ConnectionClosedCallback& cb);
    void setConnectedCallback(const ConnectionConnectedCallback& cb);

private:
    void on_connected();
    void on_write(size_t bytes_transferred);
    void on_read(const byte* data, size_t bytes_transferred);
    void on_close();

private:
    bool append_buffer_fragment(const ByteBufferPtr& buffer);
    void reset()
    {
        _buffer.clear();
    }

private:
    Socket* _socket;

    ByteBuffer _buffer;
    WriteCompletedCallback _writeCompletedCallback;
    ReadCompletedCallback _readComplectedCallback;
    ConnectionClosedCallback _connectionClosedCallback;
    ConnectionConnectedCallback _connectedCallback;
    InetAddress _inetAddress;
};

#endif