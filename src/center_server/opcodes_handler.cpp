#include "stdafx.h"
#include "opcodes.h"
#include "opcodes_handler.h"
#include "session.h"

#define MAKE_MESSAGE_HANDLER(message_name, func_name) \
    OpcodeHandler(message_name, std::bind(&Session::func_name, std::placeholders::_1, std::placeholders::_2));
    

OpcodeTable::OpcodeTable()
{
    _opcodeTable[Opcodes::C2SLoginRequest] = MAKE_MESSAGE_HANDLER("C2SLoginRequest", login_request_handler);
}