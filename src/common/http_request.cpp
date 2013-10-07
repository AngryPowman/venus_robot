#include "common.h"
#include "http_request.h"
#include "ascii.h"

const std::string HTTPRequest::HTTP_GET            = "GET";
const std::string HTTPRequest::HTTP_HEAD           = "HEAD";
const std::string HTTPRequest::HTTP_PUT            = "PUT";
const std::string HTTPRequest::HTTP_POST           = "POST";
const std::string HTTPRequest::HTTP_OPTIONS        = "OPTIONS";
const std::string HTTPRequest::HTTP_DELETE         = "DELETE";
const std::string HTTPRequest::HTTP_TRACE          = "TRACE";
const std::string HTTPRequest::HTTP_CONNECT        = "CONNECT";
const std::string HTTPRequest::HOST                = "Host";
const std::string HTTPRequest::COOKIE              = "Cookie";
const std::string HTTPRequest::AUTHORIZATION       = "Authorization";
const std::string HTTPRequest::PROXY_AUTHORIZATION = "Proxy-Authorization";
const std::string HTTPRequest::UPGRADE             = "Upgrade";


HTTPRequest::HTTPRequest():
    _method(HTTP_GET),
    _uri("/")
{
}


HTTPRequest::HTTPRequest(const std::string& version):
    HttpMessageHeader(version),
    _method(HTTP_GET),
    _uri("/")
{
}


HTTPRequest::HTTPRequest(const std::string& method, const std::string& uri):
    _method(method),
    _uri(uri)
{
}


HTTPRequest::HTTPRequest(const std::string& method, const std::string& uri, const std::string& version):
    HttpMessageHeader(version),
    _method(method),
    _uri(uri)
{
}


HTTPRequest::~HTTPRequest()
{
}


void HTTPRequest::setMethod(const std::string& method)
{
    _method = method;
}


void HTTPRequest::setURI(const std::string& uri)
{
    _uri = uri;
}


void HTTPRequest::setHost(const std::string& host)
{
    set(HOST, host);
}


void HTTPRequest::setHost(const std::string& host, uint16 port)
{
    std::string value;
    if (host.find(':') != std::string::npos)
    {
        // IPv6 address
        value.append("[");
        value.append(host);
        value.append("]");
    }
    else
    {
        value.append(host);
    }    

    if (port != 80 && port != 443)
    {
        value.append(":");

        char port_value[16] = {0};
#ifdef _WIN32
        sprintf_s(port_value, 16, "%d", port);
#else
        sprintf(port_value, "%d", port);
#endif
        value.append(port_value);
    }
    setHost(value);
}


const std::string& HTTPRequest::getHost() const
{
    return get(HOST);
}

void HTTPRequest::setCookies(const NameValueCollection& cookies)
{
    std::string cookie;
    cookie.reserve(64);
    for (NameValueCollection::ConstIterator it = cookies.begin(); it != cookies.end(); ++it)
    {
        if (it != cookies.begin())
            cookie.append("; ");
        cookie.append(it->first);
        cookie.append("=");
        cookie.append(it->second);
    }
    add(COOKIE, cookie);
}


void HTTPRequest::getCookies(NameValueCollection& cookies) const
{
    NameValueCollection::ConstIterator it = find(COOKIE);
    while (it != end() && (it->first).compare(COOKIE) == 0)
    {
        splitParameters(it->second.begin(), it->second.end(), cookies);
        ++it;
    }
}

void HTTPRequest::write(std::ostream& ostr) const
{
    ostr << _method << " " << _uri << " " << getVersion() << "\r\n";
    MessageHeader::write(ostr);
    ostr << "\r\n";
}


void HTTPRequest::read(std::istream& istr)
{
    static const int eof = std::char_traits<char>::eof();

    std::string method;
    std::string uri;
    std::string version;
    method.reserve(16);
    uri.reserve(64);
    version.reserve(16);
    int ch = istr.get();
    if (ch == eof) throw ("ch == eof");
    while (Venus::Ascii::isSpace(ch)) ch = istr.get();
    if (ch == eof) throw ("No HTTP request header");
    while (!Venus::Ascii::isSpace(ch) && ch != eof && method.length() < MAX_METHOD_LENGTH) { method += (char) ch; ch = istr.get(); }
    if (!Venus::Ascii::isSpace(ch)) throw ("HTTP request method invalid or too long");
    while (Venus::Ascii::isSpace(ch)) ch = istr.get();
    while (!Venus::Ascii::isSpace(ch) && ch != eof && uri.length() < MAX_URI_LENGTH) { uri += (char) ch; ch = istr.get(); }
    if (!Venus::Ascii::isSpace(ch)) throw ("HTTP request URI invalid or too long");
    while (Venus::Ascii::isSpace(ch)) ch = istr.get();
    while (!Venus::Ascii::isSpace(ch) && ch != eof && version.length() < MAX_VERSION_LENGTH) { version += (char) ch; ch = istr.get(); }
    if (!Venus::Ascii::isSpace(ch)) throw ("Invalid HTTP version string");
    while (ch != '\n' && ch != eof) { ch = istr.get(); }
    MessageHeader::read(istr);
    ch = istr.get();
    while (ch != '\n' && ch != eof) { ch = istr.get(); }
    setMethod(method);
    setURI(uri);
    setVersion(version);
}