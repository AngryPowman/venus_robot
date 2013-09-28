using ProtoBuf;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RobotWatchman.network
{
    enum Opcodes
    {
        //机器人鉴权
        C2SRobotLoginReq             = 10000,
        S2CRobotLoginRsp             = 10001,
    }

    public delegate void NetworkMessageCallback<T>(T message);
    class Handler
    {
        public void createHandler<T>(Delegate cb)
        {
            callback = cb;
        }

        /*public static Object parse<T>(byte[] buffer)
        {
            return Serializer.Deserialize<T>(new MemoryStream(buffer));
        }*/

        public Delegate callback { get; set; }
    }

    class OpcodesHandler
    {
        private Dictionary<Opcodes, Handler> _handlers = new Dictionary<Opcodes, Handler>();
        public OpcodesHandler()
        {
            addHandler<Protocol.S2CRobotLoginRsp>(Opcodes.S2CRobotLoginRsp, GlobalObject.MainForm.robotLoginCallback);
        }

        public Handler getHandler(Opcodes opcode)
        {
            return _handlers[opcode];
        }

        public void addHandler<TMessage>(Opcodes opcode, NetworkMessageCallback<TMessage> callback)
        {
            Handler handler = new Handler();
            handler.createHandler<TMessage>(callback);
            _handlers[opcode] = handler;
        }
    }
}
