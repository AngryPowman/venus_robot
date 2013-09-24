#ifndef __ASIO_CONNECTION_H__
#define __ASIO_CONNECTION_H__

#include "network_common.h"
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>

using namespace boost::asio::ip;

template <typename ConnectionType, typename ServiceType>
class AsioConnection
    : private boost::noncopyable, public std::enable_shared_from_this<ConnectionType>
{
public:
    AsioConnection(ServiceType& service)
        : _strand(service.service()),
        _socket(service.service())
    {
    }

    virtual ~AsioConnection()
    {
        if (isOpen())
            _socket.close();

        std::cout << "connection destroyed." << std::endl;
    }

    __forceinline int handle()  //return native socket handle
    {
        return _socket.native_handle();
    }

    void setInetAddress(const InetAddress& inetAddress);
    void connect();
    void connect(const InetAddress& inetAddress);
    void disconnect();
    void write(const byte* data, size_t size);
    void read();
    void shutdown();
    tcp::socket& socket();
    bool isOpen();

public:
    //enum CALLBACK_TYPE { CB_WRITE_COMPLETED, CB_READ_COMPLETED, CB_CONNECTION_CLOSED, CB_CONNECTED };
    void setWriteCompletedCallback(const WriteCompletedCallback& cb)
    {
        _writeCompletedCallback = cb;
    }

    void setReadCompletedCallback(const ReadCompletedCallback& cb)
    {
        _readComplectedCallback = cb;
    }

    void setConnectionClosedCallback(const ConnectionClosedCallback& cb)
    {
        _connectionClosedCallback = cb;
    }

    void setConnectedCallback(const ConnectedCallback& cb)
    {
        _connectedCallback = cb;
    }
    //template <typename T, typename... Args>
    //void execute_callback(std::function<Args>& cb);

private:
    tcp::socket _socket;
    IOService& _io_service;
    boost::asio::strand _strand;

private:
    WriteCompletedCallback _writeCompletedCallback;
    ReadCompletedCallback _readComplectedCallback;
    ConnectionClosedCallback _connectionClosedCallback;
    ConnectedCallback _connectedCallback;
};



#endif