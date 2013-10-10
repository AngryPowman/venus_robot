#ifndef __HTTP_HEADER_STREAM_H__
#define __HTTP_HEADER_STREAM_H__

#include <istream>
#include <ostream>
#include <ios>

class HTTPSession;
class HTTPHeaderStreamBuf
{
public:
    typedef std::ios::openmode openmode;

    HTTPHeaderStreamBuf(HTTPSession& session, openmode mode);
    ~HTTPHeaderStreamBuf();

protected:
    int readFromDevice(char* buffer, std::streamsize length);
    int writeToDevice(const char* buffer, std::streamsize length);

private:
    HTTPSession& _session;
    bool         _end;
};

class HTTPHeaderIOS
    : public virtual std::ios
{
public:
    HTTPHeaderIOS(HTTPSession& session, HTTPHeaderStreamBuf::openmode mode);
    ~HTTPHeaderIOS();
    HTTPHeaderStreamBuf* rdbuf();

protected:
    HTTPHeaderStreamBuf _buf;
};


class HTTPHeaderInputStream
    : public HTTPHeaderIOS, public std::istream
{
public:
    HTTPHeaderInputStream(HTTPSession& session);
    ~HTTPHeaderInputStream();
};


class HTTPHeaderOutputStream
    : public HTTPHeaderIOS, public std::ostream
{
public:
    HTTPHeaderOutputStream(HTTPSession& session);
    ~HTTPHeaderOutputStream();
};

#endif