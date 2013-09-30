#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include "common.h"
#include "network_common.h"

typedef std::function<void (const std::string& connection)> HttpResponseCallback;

class TcpConnection;
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
    void callback(const TcpConnectionPtr& connection, uint32_t opcode, const byte* data, uint32_t bytes_transferred);

private:
    TcpConnection* _connection;
};

#endif