﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using ProtoBuf;
using System.Windows.Forms;

namespace RobotWatchman.network
{
    class RobotNetworkEvent
    {
        private static OpcodesHandler _opcodeHandler = new OpcodesHandler();
        private static Dictionary<string, UInt32> _opcodesTable = new Dictionary<string, UInt32>();
        public static void init()
        {
            foreach (Opcodes opcode in Enum.GetValues(typeof(Opcodes)))
            {
                string strKey = Enum.GetName(typeof(Opcodes), opcode);
                UInt32 strValue = (UInt32)opcode;
                _opcodesTable.Add(strKey, strValue);
            }
        }

        const int HEADER_LENGTH = 8;
        private static Socket _clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        private static byte[] _recvBuffer = new byte[1024];
        public static void connectToRobotServer(string ip, UInt16 port)
        {
            addLog("正在连接到机器人服务器 " + ip + ":" + port.ToString() + "...");

            //连接到服务器
            disconnectRobotServer();

            _clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            _clientSocket.Connect(IPAddress.Parse(ip), port);
            _clientSocket.BeginReceive(_recvBuffer, 0, _recvBuffer.Length, SocketFlags.None, new AsyncCallback(onReceived), _clientSocket);
        }

        public static void disconnectRobotServer()
        {
            //连接到服务器
            if (_clientSocket != null && _clientSocket.Connected)
            {
                _clientSocket.Shutdown(SocketShutdown.Both);
                _clientSocket.Disconnect(true);
                _clientSocket.Close();
            }
        }

        /// <summary>
        /// 机器人验证请求
        /// </summary>
        /// <param name="verify_key"></param>
        public static void sendRobotLoginRequest(string verify_key)
        {
            addLog("正在验证机器人密钥...");
            Protocol.C2SRobotLoginReq request = new Protocol.C2SRobotLoginReq();
            request.verify_key = verify_key;

            sendPacket<Protocol.C2SRobotLoginReq>(request);
        }

        /*******************************************************************************************
        /* 网络事件
        /*******************************************************************************************/
        private static void onSendCompleted(IAsyncResult result)
        {
            try
            {
                // Retrieve the socket from the state object.     
                Socket socket = (Socket)result.AsyncState;

                // Complete sending the data to the remote device.     
                int bytesSent = socket.EndSend(result);

                Console.WriteLine("Sent {0} bytes to server.", bytesSent);
                //handler.Shutdown(SocketShutdown.Both);
                //handler.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        private static void onReceived(IAsyncResult result)
        {
            Socket socket = (Socket)result.AsyncState;
            int bytesReceived = socket.EndReceive(result);

            if (bytesReceived == 0)
            {
                onDisconnected();
                return;
            }

            MemoryStream streamPacket = new MemoryStream(_recvBuffer);
            BinaryReader reader = new BinaryReader(streamPacket);
            UInt32 len = reader.ReadUInt32();
            UInt32 opcode = reader.ReadUInt32();

            UInt32 messageLen = len - HEADER_LENGTH;
            byte[] message = new byte[messageLen];
            reader.Read(message, 0, message.Length);

            Handler handlerInfo = _opcodeHandler.getHandler((Opcodes)opcode);
            if (handlerInfo != null)
            {
                //Type type = Type.GetType(handlerInfo.protoType.FullName);
                //object responseMessage = type.Assembly.CreateInstance(type.Name);
                //handlerInfo.messageObject = Serializer.Deserialize<Object>(new MemoryStream(message));
                //robotLoginResponse
                //    = Serializer.Deserialize<Protocol.S2CRobotLoginRsp>(new MemoryStream(message));
                GlobalObject.MainForm.Invoke(handlerInfo.callback, new MemoryStream(message));
            }

            Console.WriteLine("received {0} bytes.", bytesReceived);
        }

        private static void onDisconnected()
        { 
        
        }

        /*******************************************************************************************
        /* 其它函数
        /*******************************************************************************************/
        private static void addLog(string log)
        {
            GlobalObject.MainForm.addLog(log);
        }

        private static void sendPacket<T>(T message)
        { 
            // Serialize body data first
            MemoryStream streamBody = new MemoryStream();
            Serializer.Serialize(streamBody, message);
            UInt32 bodyLen = (uint)streamBody.Length;

            // Find opcode value with proto typename
            UInt32 opcode = _opcodesTable[message.GetType().Name];

            // Serialize header data and body
            MemoryStream streamPacket = new MemoryStream();
            BinaryWriter writer = new BinaryWriter(streamPacket);
            writer.Write(HEADER_LENGTH + bodyLen);
            writer.Write(opcode);
            writer.Write(streamBody.ToArray());

            int packetLen = (int)streamPacket.Length;

            _clientSocket.BeginSend(streamPacket.ToArray(), 0, packetLen, 0, new AsyncCallback(onSendCompleted), _clientSocket);
        }

        public static T parseMessage<T>(MemoryStream stream)
        {
            return Serializer.Deserialize<T>(stream);
        }
    }
}
