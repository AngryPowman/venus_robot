#ifndef __HTTP_SESSION_H__
#define __HTTP_SESSION_H__

#include "any.h"
#include "time_span.h"
#include "io_service.h"
#include "inet_address.h"
#include "socket.h"
#include <ios>
#include <boost/noncopyable.hpp>

class HTTPSession
    : boost::noncopyable
{
public:
    void setKeepAlive(bool keepAlive);
    bool getKeepAlive() const;
    void setTimeout(const Venus::Timespan& timeout);

    Venus::Timespan getTimeout() const;
    bool connected() const;

    virtual void abort();

    enum
    {
        HTTP_PORT = 80
    };

    Socket& socket();

protected:
    HTTPSession(IOService& service);
    HTTPSession(IOService& service, bool keepAlive);

    virtual ~HTTPSession();

    virtual int read(byte* buffer, std::streamsize length);
    virtual int write(const byte* buffer, std::streamsize length);
    int receive(byte* buffer, int length);
    int buffered() const;
    virtual bool connect(const InetAddress& address);
    void close();

private:
    enum
    {
        HTTP_DEFAULT_TIMEOUT = 60000000
    };

    Socket           _socket;
    char*            _pBuffer;
    char*            _pCurrent;
    char*            _pEnd;
    bool             _keepAlive;
    Venus::Timespan   _timeout;
};


//
// inlines
//
inline bool HTTPSession::getKeepAlive() const
{
    return _keepAlive;
}


inline Venus::Timespan HTTPSession::getTimeout() const
{
    return _timeout;
}


inline Socket& HTTPSession::socket()
{
    return _socket;
}

/*
inline const Poco::Exception* HTTPSession::networkException() const
{
    return _pException;
}*/


inline int HTTPSession::buffered() const
{
    return static_cast<int>(_pEnd - _pCurrent);
}


/*inline const Venus::Any& HTTPSession::sessionData() const
{
    return _data;
}*/

#endif // __HTTP_SESSION_H__