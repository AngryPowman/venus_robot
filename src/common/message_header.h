#ifndef __MESSAGE_HEADER_H__
#define __MESSAGE_HEADER_H__

#include <ostream>
#include <istream>
#include <vector>
#include "name_value_collection.h"


class MessageHeader : public NameValueCollection
{
public:
    MessageHeader();
    MessageHeader(const MessageHeader& messageHeader);
    virtual ~MessageHeader();

    MessageHeader& operator = (const MessageHeader& messageHeader);

public:
    virtual void write(std::ostream& ostr) const;
    virtual void read(std::istream& istr);
    int getFieldLimit() const;
    void setFieldLimit(int limit);
    bool hasToken(const std::string& fieldName, const std::string& token) const;
    static void splitElements(const std::string& s, std::vector<std::string>& elements, bool ignoreEmpty = true);
    static void splitParameters(const std::string& s, std::string& value, NameValueCollection& parameters);
    static void splitParameters(const std::string::const_iterator& begin, const std::string::const_iterator& end, NameValueCollection& parameters);
    static void quote(const std::string& value, std::string& result, bool allowSpace = false);

private:
    enum Limits
    {
        MAX_NAME_LENGTH  = 256,
        MAX_VALUE_LENGTH = 8192,
        DFL_FIELD_LIMIT  = 100
    };

    int _fieldLimit;
};

#endif // __MESSAGE_HEADER_H__
