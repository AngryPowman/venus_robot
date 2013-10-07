#include <string>
#include "http_message_header.h"

const std::string HttpMessageHeader::HTTP_1_0                   = "HTTP/1.0";
const std::string HttpMessageHeader::HTTP_1_1                   = "HTTP/1.1";
const std::string HttpMessageHeader::IDENTITY_TRANSFER_ENCODING = "identity";
const std::string HttpMessageHeader::CHUNKED_TRANSFER_ENCODING  = "chunked";
const int         HttpMessageHeader::UNKNOWN_CONTENT_LENGTH     = -1;
const std::string HttpMessageHeader::UNKNOWN_CONTENT_TYPE       = "";
const std::string HttpMessageHeader::CONTENT_LENGTH             = "Content-Length";
const std::string HttpMessageHeader::CONTENT_TYPE               = "Content-Type";
const std::string HttpMessageHeader::TRANSFER_ENCODING          = "Transfer-Encoding";
const std::string HttpMessageHeader::CONNECTION                 = "Connection";
const std::string HttpMessageHeader::CONNECTION_KEEP_ALIVE      = "Keep-Alive";
const std::string HttpMessageHeader::CONNECTION_CLOSE           = "Close";
const std::string HttpMessageHeader::EMPTY;


HttpMessageHeader::HttpMessageHeader():
    _version(HTTP_1_0)
{
}


HttpMessageHeader::HttpMessageHeader(const std::string& version):
    _version(version)
{
}


HttpMessageHeader::~HttpMessageHeader()
{
}


void HttpMessageHeader::setVersion(const std::string& version)
{
    _version = version;
}


void HttpMessageHeader::setContentLength(std::streamsize length)
{
    char length_value[16] = {0};
#ifdef _WIN32
    sprintf_s(length_value, 16, "%d", length);
#else
    sprintf(length_value, "%d", length);
#endif

    if (length != UNKNOWN_CONTENT_LENGTH)
        set(CONTENT_LENGTH, length_value);
    else
        erase(CONTENT_LENGTH);
}


std::streamsize HttpMessageHeader::getContentLength() const
{
    const std::string& contentLength = get(CONTENT_LENGTH, EMPTY);
    if (!contentLength.empty())
    {
        return static_cast<std::streamsize>(atol(contentLength.c_str()));
    }
    else return UNKNOWN_CONTENT_LENGTH;
}

void HttpMessageHeader::setTransferEncoding(const std::string& transferEncoding)
{
    if (transferEncoding.compare(IDENTITY_TRANSFER_ENCODING) == 0)
        erase(TRANSFER_ENCODING);
    else
        set(TRANSFER_ENCODING, transferEncoding);
}


const std::string& HttpMessageHeader::getTransferEncoding() const
{
    return get(TRANSFER_ENCODING, IDENTITY_TRANSFER_ENCODING);
}


void HttpMessageHeader::setChunkedTransferEncoding(bool flag)
{
    if (flag)
        setTransferEncoding(CHUNKED_TRANSFER_ENCODING);
    else
        setTransferEncoding(IDENTITY_TRANSFER_ENCODING);
}


bool HttpMessageHeader::getChunkedTransferEncoding() const
{
    return getTransferEncoding().compare(CHUNKED_TRANSFER_ENCODING) == 0;
}


void HttpMessageHeader::setContentType(const std::string& mediaType)
{
    if (mediaType.empty())
        erase(CONTENT_TYPE);
    else
        set(CONTENT_TYPE, mediaType);
}

const std::string& HttpMessageHeader::getContentType() const
{
    return get(CONTENT_TYPE, UNKNOWN_CONTENT_TYPE);
}


void HttpMessageHeader::setKeepAlive(bool keepAlive)
{
    if (keepAlive)
        set(CONNECTION, CONNECTION_KEEP_ALIVE);
    else
        set(CONNECTION, CONNECTION_CLOSE);
}


bool HttpMessageHeader::getKeepAlive() const
{
    const std::string& connection = get(CONNECTION, EMPTY);
    if (!connection.empty())
        return connection.compare(CONNECTION_CLOSE) != 0;
    else
        return getVersion() == HTTP_1_1;
}