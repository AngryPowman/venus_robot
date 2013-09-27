#ifndef __SESSION_H__
#define __SESSION_H__

#include <common.h>
#include <network_common.h>
#include <protobuf.h>
#include <packet.h>
#include <tcp_connection.h>
#include "opcodes.h"

class Session
{
public:
    Session(const uint64_t& session_id)
        : _sessionId(session_id)
    {
    }

    ~Session()
    {
    }

public:
    void set_connection_ptr(const TcpConnectionPtr& connection)
    {
        _connection = connection;
    }

    uint64_t session_id() const
    {
        return _sessionId;
    }

    template <typename T> void send_message(uint32 opcode, const T& message)
    {
        if (_connection != NULL)
        {
            size_t byteSize = message.ByteSize();
            byte* message_data = new byte[byteSize];
            message.SerializeToArray(message_data, byteSize);

            _connection->write(message_data, byteSize);

            SAFE_DELETE_ARR(message_data);
        }
    }

public:
    void robot_login_handler(const NetworkMessage& message)
    {
        std::cout << "enter login handler, session id = " << _sessionId << std::endl;

        Protocol::C2SRobotLoginReq request;
        message.parse(request);

        std::cout << "received robot key = " << request.verify_key() << std::endl;

        Protocol::S2CRobotLoginRsp robot_login_response;
        robot_login_response.set_login_result(request.verify_key() == "@##36911$0&&!AbC");

        send_message<Protocol::S2CRobotLoginRsp>(Opcodes::S2CRobotLoginRsp, robot_login_response);
    }

private:
    uint64_t _sessionId;
    TcpConnectionPtr _connection;
};

#endif