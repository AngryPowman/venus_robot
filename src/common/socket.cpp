#include "socket.h"

#define HANDLE_ERROR_PROCESS(x) if (x) { on_error(x); }

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


void Socket::on_error(const boost::system::error_code& error)
{
    std::cout << "Socket Error : oops, connection lost :(" << std::endl;
    std::cout << "Socket Error : " << error.message() << std::endl;

    shutdown();
    switch (error.value())
    {
    case boost::asio::error::bad_descriptor:
    case boost::asio::error::eof:
    case boost::asio::error::operation_aborted:
    case boost::asio::error::connection_reset:
        {
            if (_close_callback)
            {
                _close_callback(shared_from_this());
            }
            break;
        }
    }

    this->close();
}

void Socket::handle_connected(const boost::system::error_code& error)
{
    HANDLE_ERROR_PROCESS(error);

    if (_connected_callback)
        _connected_callback(shared_from_this());
}

void Socket::handle_write(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    HANDLE_ERROR_PROCESS(error);

    if (_send_callback)
        _send_callback(shared_from_this(), bytes_transferred);
}

void Socket::handle_read(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    HANDLE_ERROR_PROCESS(error);

    if (bytes_transferred == 0)
    {
        handle_close();
        return;
    }

    if (_receive_callback)
        _receive_callback(shared_from_this(), _recv_buffer.data(), bytes_transferred);
}

void Socket::handle_close()
{
    if (_close_callback)
        _close_callback(shared_from_this());
}