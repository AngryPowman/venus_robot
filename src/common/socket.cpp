#include "socket.h"

void Socket::connect(const std::string& host, uint16 port)
{
    if (is_open())
        shutdown();

    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::address::from_string(host), port);

    _socket.async_connect(
        endpoint,
        boost::bind(&Socket::handle_connected, shared_from_this(), boost::asio::placeholders::error));
}

void Socket::close()
{
    _socket.close();
}

void Socket::send(const byte* data, size_t size)
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
        &Socket::handle_write, 
        shared_from_this(), 
        boost::asio::placeholders::error, 
        boost::asio::placeholders::bytes_transferred
        )
        )
        );
}

void Socket::receive()
{
    _socket.async_read_some(
        boost::asio::buffer(_recv_buffer),
        _strand.wrap(
        boost::bind(
        &Socket::handle_read, 
        shared_from_this(), 
        boost::asio::placeholders::error, 
        boost::asio::placeholders::bytes_transferred
        )
        )
        );
}

void Socket::shutdown()
{
    _socket.shutdown(boost::asio::socket_base::shutdown_both);
}

tcp::socket& Socket::socket()
{
    return _socket;
}

bool Socket::is_open() const
{
    return _socket.is_open();
}
