#ifndef __HTTP_MESSAGE_HEADER_H__
#define __HTTP_MESSAGE_HEADER_H__

#include <boost/noncopyable.hpp>
#include "message_header.h"

class HttpMessageHeader
    : public MessageHeader, public boost::noncopyable
{
public:
    void setVersion(const std::string& version);
    const std::string& getVersion() const;
    void setContentLength(std::streamsize length);
    std::streamsize getContentLength() const;

    bool hasContentLength() const;
    void setTransferEncoding(const std::string& transferEncoding);
    const std::string& getTransferEncoding() const;
    void setChunkedTransferEncoding(bool flag);
    bool getChunkedTransferEncoding() const;
    void setContentType(const std::string& mediaType);
    const std::string& getContentType() const;
    void setKeepAlive(bool keepAlive);
    bool getKeepAlive() const;

    static const std::string HTTP_1_0;
    static const std::string HTTP_1_1;

    static const std::string IDENTITY_TRANSFER_ENCODING;
    static const std::string CHUNKED_TRANSFER_ENCODING;

    static const int         UNKNOWN_CONTENT_LENGTH;
    static const std::string UNKNOWN_CONTENT_TYPE;

    static const std::string CONTENT_LENGTH;
    static const std::string CONTENT_TYPE;
    static const std::string TRANSFER_ENCODING;
    static const std::string CONNECTION;

    static const std::string CONNECTION_KEEP_ALIVE;
    static const std::string CONNECTION_CLOSE;

    static const std::string EMPTY;

protected:
    HttpMessageHeader();
    HttpMessageHeader(const std::string& version);
    virtual ~HttpMessageHeader();

private:
    std::string _version;
};

inline const std::string& HttpMessageHeader::getVersion() const
{
    return _version;
}


inline bool HttpMessageHeader::hasContentLength() const
{
    return has(CONTENT_LENGTH);
}

#endif