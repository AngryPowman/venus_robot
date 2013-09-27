using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RobotWatchman.network
{
    class Opcodes
    {
        //机器人鉴权
        static UInt32 C2SRobotLoginReq             = 10000;
        static UInt32 S2CRobotLoginRsp             = 10001;
    }

    class OpcodesHandler
    {
        UInt32 opcodes;
        Delegate callback;
    }
}
