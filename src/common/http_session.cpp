#include <cstring>
#include "http_session.h"

//using Poco::TimeoutException;

HTTPSession::HTTPSession(IOService& service) : 
    _socket(service),
    _pBuffer(0),
    _pCurrent(0),
    _pEnd(0),
    _keepAlive(false),
    _timeout(HTTP_DEFAULT_TIMEOUT)
{
}

HTTPSession::HTTPSession(IOService& service, bool keepAlive):
    _socket(service),
    _pBuffer(0),
    _pCurrent(0),
    _pEnd(0),
    _keepAlive(keepAlive),
    _timeout(HTTP_DEFAULT_TIMEOUT)
{
}


HTTPSession::~HTTPSession()
{
    try
    {
        close();
    }
    catch (...)
    {
    }
}


void HTTPSession::setKeepAlive(bool keepAlive)
{
    _keepAlive = keepAlive;
}


void HTTPSession::setTimeout(const Venus::Timespan& timeout)
{
    _timeout = timeout;
}

int HTTPSession::read(byte* buffer, std::streamsize length)
{
    if (_pCurrent < _pEnd)
    {
        int n = (int) (_pEnd - _pCurrent);
        if (n > length) n = (int) length;
        std::memcpy(buffer, _pCurrent, n);
        _pCurrent += n;
        return n;
    }
    else return receive(buffer, (int) length);
}


int HTTPSession::write(const byte* buffer, std::streamsize length)
{
    return _socket.send(buffer, (int) length);
}

int HTTPSession::receive(byte* buffer, int length)
{
    return _socket.receive(buffer, length);
}


bool HTTPSession::connected() const
{
    return _socket.is_open();
}

bool HTTPSession::connect(const InetAddress& address)
{
    return _socket.connect(address.host(), address.port());
}


void HTTPSession::abort()
{
    _socket.shutdown();
    close();
}


void HTTPSession::close()
{
    _socket.close();
}