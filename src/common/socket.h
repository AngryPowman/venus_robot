#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <boost/array.hpp>
#include "common.h"
#include "io_service.h"
#include "network_common.h"

using namespace boost::asio::ip;

class Socket
    : private boost::noncopyable, public std::enable_shared_from_this<Socket>
{
    //raw callback types
    typedef std::function<void (const SocketPtr& socket, uint32_t bytes_transferred)> SendCallback;
    typedef std::function<void (const SocketPtr& socket, const byte* data, uint32_t bytes_transferred)> ReceiveCallback;
    typedef std::function<void (const SocketPtr& socket)> ConnectedCallback;
    typedef std::function<void (const SocketPtr& connection)> CloseCallback;

public:
    Socket(IOService& service);
    ~Socket();

public:
    __forceinline int handle()  //return native socket handle
    {
        return _socket.native_handle();
    }

    void connect(const std::string& ip, uint16 port);
    void close();
    void shutdown();
    void send(const byte* data, size_t size);
    void receive();
    bool is_open() const;
    tcp::socket& socket();

public:
    inline void set_send_callback(const SendCallback& callback)
    { _send_callback = callback; }

    inline void set_receive_callback(const ReceiveCallback& callback)
    { _receive_callback = callback; }

    inline void set_connected_callback(const ConnectedCallback& callback)
    { _connected_callback = callback; }

    inline void set_close_callback(const CloseCallback& callback)
    { _close_callback = callback; }

private:
    void on_error(const boost::system::error_code& error);
    void handle_connected(const boost::system::error_code& error);
    void handle_write(const boost::system::error_code& error, std::size_t bytes_transferred);
    void handle_read(const boost::system::error_code& error, std::size_t bytes_transferred);
    void handle_close();

private:
    SendCallback _send_callback;
    ReceiveCallback _receive_callback;
    ConnectedCallback _connected_callback;
    CloseCallback _close_callback;

private:
    IOService& _io_service;
    tcp::socket _socket;
    boost::asio::strand _strand;
    boost::array<byte, MAX_RECV_LEN> _recv_buffer;
};

#endif