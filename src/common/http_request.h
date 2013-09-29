#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include "common.h"
#include <boost/noncopyable.hpp>

class TcpConnection;
class HttpRequest
    : public boost::noncopyable
{
public:
    HttpRequest(const std::string& url);

public:
    void setMethod(const std::string& method);
    void setHeader(const std::string& header, const std::string& value);

public:
    TcpConnection* _connection;
};

#endif