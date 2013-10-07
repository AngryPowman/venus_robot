#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include "http_request.h"
#include "http_message_header.h"

class HTTPRequest
    : public HttpMessageHeader
{
public:
    HTTPRequest();
    /// Creates a GET / HTTP/1.0 HTTP request.

    HTTPRequest(const std::string& version);
    /// Creates a GET / HTTP/1.x request with
    /// the given version (HTTP/1.0 or HTTP/1.1).

    HTTPRequest(const std::string& method, const std::string& uri);
    /// Creates a HTTP/1.0 request with the given method and URI.

    HTTPRequest(const std::string& method, const std::string& uri, const std::string& version);
    /// Creates a HTTP request with the given method, URI and version.

    virtual ~HTTPRequest();
    /// Destroys the HTTPRequest.

    void setMethod(const std::string& method);
    /// Sets the method.

    const std::string& getMethod() const;
    /// Returns the method.

    void setURI(const std::string& uri);
    /// Sets the request URI.

    const std::string& getURI() const;
    /// Returns the request URI.

    void setHost(const std::string& host);
    /// Sets the value of the Host header field.

    void setHost(const std::string& host, uint16 port);
    /// Sets the value of the Host header field.
    ///
    /// If the given port number is a non-standard
    /// port number (other than 80 or 443), it is
    /// included in the Host header field.

    const std::string& getHost() const;
    /// Returns the value of the Host header field.
    ///
    /// Throws a NotFoundException if the request
    /// does not have a Host header field.

    void setCookies(const NameValueCollection& cookies);
    /// Adds a Cookie header with the names and
    /// values from cookies.

    void getCookies(NameValueCollection& cookies) const;
    /// Fills cookies with the cookies extracted
    /// from the Cookie headers in the request.

    void write(std::ostream& ostr) const;
    /// Writes the HTTP request to the given
    /// output stream.

    void read(std::istream& istr);
    /// Reads the HTTP request from the
    /// given input stream.

    static const std::string HTTP_GET;
    static const std::string HTTP_HEAD;
    static const std::string HTTP_PUT;
    static const std::string HTTP_POST;
    static const std::string HTTP_OPTIONS;
    static const std::string HTTP_DELETE;
    static const std::string HTTP_TRACE;
    static const std::string HTTP_CONNECT;

    static const std::string HOST;
    static const std::string COOKIE;
    static const std::string AUTHORIZATION;
    static const std::string PROXY_AUTHORIZATION;
    static const std::string UPGRADE;

private:
    enum Limits
    {
        MAX_METHOD_LENGTH  = 32,
        MAX_URI_LENGTH     = 4096,
        MAX_VERSION_LENGTH = 8
    };

    std::string _method;
    std::string _uri;

    HTTPRequest(const HTTPRequest&);
    HTTPRequest& operator = (const HTTPRequest&);
};


//
// inlines
//
inline const std::string& HTTPRequest::getMethod() const
{
    return _method;
}

inline const std::string& HTTPRequest::getURI() const
{
    return _uri;
}

#endif
