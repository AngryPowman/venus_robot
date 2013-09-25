#ifndef PACKET_H_
#define PACKET_H_

#include <google/protobuf/message.h>

#pragma pack(push, 1)

struct SERVER_DECL ServerPacket
{
    const static int HEADER_LENGTH = sizeof(size_t) + sizeof(size_t);

    size_t len;
    uint32_t opcode;
    byte* message;

    //const google::protobuf::Message* protoMessage() const
    //{
    //    return (google::protobuf::Message*)message;
    //}

    ServerPacket() : len(0), opcode(0), message(NULL)
    {
    }
};

#pragma pack(pop)

#endif