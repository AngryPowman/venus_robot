#include <ostream>
#include "http_request.h"
#include "http_client_session.h"
#include "http_header_stream.h"

HTTPClientSession::HTTPClientSession() :
    HTTPSession(_io_service),
    _port(HTTPSession::HTTP_PORT),
    _keepAliveTimeout(DEFAULT_KEEP_ALIVE_TIMEOUT, 0),
    _reconnect(false),
    _mustReconnect(false),
    _expectResponseBody(false)
{
}


HTTPClientSession::HTTPClientSession(const InetAddress& address) :
    HTTPSession(_io_service),
    _host(address.host()),
    _port(address.port()),
    _keepAliveTimeout(DEFAULT_KEEP_ALIVE_TIMEOUT, 0),
    _reconnect(false),
    _mustReconnect(false),
    _expectResponseBody(false)
{
}


HTTPClientSession::HTTPClientSession(const std::string& host, uint16 port) :
    HTTPSession(_io_service),
    _host(host),
    _port(port),
    _keepAliveTimeout(DEFAULT_KEEP_ALIVE_TIMEOUT, 0),
    _reconnect(false),
    _mustReconnect(false),
    _expectResponseBody(false)
{
}


HTTPClientSession::~HTTPClientSession()
{
}


void HTTPClientSession::setHost(const std::string& host)
{
    if (!connected())
        _host = host;
}


void HTTPClientSession::setPort(uint16 port)
{
    if (!connected())
        _port = port;
}

std::ostream& HTTPClientSession::sendRequest(HTTPRequest& request)
{
    _pResponseStream = 0;

    //bool keepAlive = getKeepAlive();
    if (connected() || mustReconnect())
    {
        close();
        _mustReconnect = false;
    }

    if (!connected())
        reconnect();

    //if (!keepAlive)
    //    request.setKeepAlive(false);

    if (!request.has(HTTPRequest::HOST))
        request.setHost(_host, _port);

    //_reconnect = keepAlive;

    HTTPHeaderOutputStream stream(*this);
    request.write(os);

    return *_pRequestStream;
}


std::istream& HTTPClientSession::receiveResponse(HTTPResponse& response)
{
    /*_pRequestStream = 0;

    do
    {
        response.clear();
        HTTPHeaderInputStream his(*this);
        try
        {
            response.read(his);
        }
        catch (MessageException&)
        {
            close();
            if (networkException())
                networkException()->rethrow();
            else
                throw;
        }
        catch (Exception&)
        {
            close();
            throw;
        }
    }
    while (response.getStatus() == HTTPResponse::HTTP_CONTINUE);

    _mustReconnect = getKeepAlive() && !response.getKeepAlive();

    if (!_expectResponseBody || response.getStatus() < 200 || response.getStatus() == HTTPResponse::HTTP_NO_CONTENT || response.getStatus() == HTTPResponse::HTTP_NOT_MODIFIED)
        _pResponseStream = new HTTPFixedLengthInputStream(*this, 0);
    else if (response.getChunkedTransferEncoding())
        _pResponseStream = new HTTPChunkedInputStream(*this);
    else if (response.hasContentLength())
#if defined(POCO_HAVE_INT64)
        _pResponseStream = new HTTPFixedLengthInputStream(*this, response.getContentLength64());
#else
        _pResponseStream = new HTTPFixedLengthInputStream(*this, response.getContentLength());
#endif
    else
        _pResponseStream = new HTTPInputStream(*this);

    return *_pResponseStream;*/

    return *_pResponseStream;
}


void HTTPClientSession::reset()
{
    close();
}

int HTTPClientSession::write(const byte* buffer, std::streamsize length)
{
    int rc = HTTPSession::write(buffer, length);
    _reconnect = false;
    return rc;
}


void HTTPClientSession::reconnect()
{
    InetAddress addr(_host, _port);
    connect(addr);
}

bool HTTPClientSession::mustReconnect() const
{
    if (!_mustReconnect)
    {
        Venus::Timestamp now;
        return _keepAliveTimeout <= now - _lastRequest;
    }
    else return true;
}