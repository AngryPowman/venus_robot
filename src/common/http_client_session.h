#ifndef __HTTP_CLIENT_SESSION_H__
#define __HTTP_CLIENT_SESSION_H__

#include "common.h"
#include <istream>
#include <ostream>
#include "http_session.h"

class HTTPRequest;
class HTTPResponse;

class HTTPClientSession 
    : public HTTPSession
{
public:
    HTTPClientSession();
    //explicit HTTPClientSession(const Socket& socket);
    explicit HTTPClientSession(const InetAddress& address);

    HTTPClientSession(const std::string& host, uint16 port = HTTPSession::HTTP_PORT);
    /// Creates a HTTPClientSession using the given host and port.

    virtual ~HTTPClientSession();
    /// Destroys the HTTPClientSession and closes
    /// the underlying socket.

    void setHost(const std::string& host);
    const std::string& getHost() const;
    void setPort(uint16 port);
    uint16 getPort() const;

    virtual std::ostream& sendRequest(HTTPRequest& request);
    virtual std::istream& receiveResponse(HTTPResponse& response);
    void reset();

protected:
    enum
    {
        DEFAULT_KEEP_ALIVE_TIMEOUT = 8
    };

    void reconnect();
    /// Connects the underlying socket to the HTTP server.

    int write(const byte* buffer, std::streamsize length);
    /// Tries to re-connect if keep-alive is on.

    virtual bool mustReconnect() const;
    /// Checks if we can reuse a persistent connection.

private:
    std::string     _host;
    uint16          _port;
    //std::string     _proxyHost;
    //uint16          _proxyPort;
    //std::string     _proxyUsername;
    //std::string     _proxyPassword;
    Venus::Timespan  _keepAliveTimeout;
    Venus::Timestamp _lastRequest;
    bool            _reconnect;
    bool            _mustReconnect;
    bool            _expectResponseBody;
    IOService       _io_service;
    std::shared_ptr<std::ostream> _pRequestStream;
    std::shared_ptr<std::istream> _pResponseStream;
};


//
// inlines
//
inline const std::string& HTTPClientSession::getHost() const
{
    return _host;
}


inline uint16 HTTPClientSession::getPort() const
{
    return _port;
}

/*
inline const std::string& HTTPClientSession::getProxyHost() const
{
    return _proxyHost;
}


inline Poco::UInt16 HTTPClientSession::getProxyPort() const
{
    return _proxyPort;
}


inline const std::string& HTTPClientSession::getProxyUsername() const
{
    return _proxyUsername;
}


inline const std::string& HTTPClientSession::getProxyPassword() const
{
    return _proxyPassword;
}


inline const Poco::Timespan& HTTPClientSession::getKeepAliveTimeout() const
{
    return _keepAliveTimeout;
}*/

#endif // __HTTP_CLIENT_SESSION_H__