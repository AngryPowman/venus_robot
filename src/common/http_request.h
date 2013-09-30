#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include "common.h"
#include "network_common.h"

typedef std::function<void (const std::string& connection)> HttpResponseCallback;

class Socket;
class HttpRequest
    : public boost::noncopyable
{
public:
    HttpRequest(const std::string& url);

public:
    void setMethod(const std::string& method);
    void setHeader(const std::string& header, const std::string& value);
    void open();

public:
    void setHttpResponseCallback(const HttpResponseCallback& cb);

private:
    void callback(const byte* data, uint32 bytes_transferred);

private:
    Socket* _socket;
};

#endif