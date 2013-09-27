using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using ProtoBuf;

namespace RobotWatchman.network
{
    class RobotNetworkEvent
    {
        private static Socket _clientSocket;
        public static void connectToRobotServer(string ip, UInt16 port)
        {
            addLog("正在连接到机器人服务器 " + ip + ":" + port.ToString() + "...");

            //连接到服务器
            if (_clientSocket != null && _clientSocket.Connected)
            {
                _clientSocket.Shutdown(SocketShutdown.Both);
                _clientSocket.Close();
            }

            _clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            IAsyncResult connectResult =
                _clientSocket.BeginConnect(
                IPAddress.Parse(ip),
                port,
                new AsyncCallback(onConnected), _clientSocket
                );
        }

        public static void sendRobotLoginRequest(string verify_key)
        {
            Protocol.C2SRobotLoginReq request = new Protocol.C2SRobotLoginReq();
            request.verify_key = verify_key;

            sendPacket<Protocol.C2SRobotLoginReq>(request);
        }

        /*******************************************************************************************
        /* 网络事件
        /*******************************************************************************************/
        private static void onConnected(IAsyncResult result)
        {
            Socket socket = (Socket)result.AsyncState;
            if (socket.Connected)
            {
                socket.EndConnect(result);

                byte[] buffer = new byte[1024];
                socket.BeginReceive(buffer, 0, 1024, SocketFlags.None, new AsyncCallback(onReceived), socket);
            }
        }

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

            Console.WriteLine("received {0} bytes.", bytesReceived);
        }

        /*******************************************************************************************
        /* 其它函数
        /*******************************************************************************************/
        static void addLog(string log)
        {
            GlobalObject.MainForm.addLog(log);
        }

        private static void sendPacket<T>(T message)
        { 
            // Serialize body data first
            MemoryStream streamBody = new MemoryStream();
            //BinaryFormatter protoDataFormatter = new BinaryFormatter();
            //protoDataFormatter.Serialize(streamBody, message);

            Serializer.SerializeWithLengthPrefix(streamBody, message, PrefixStyle.None);
            UInt32 bodyLen = (uint)streamBody.Length;

            // Serialize header data and body
            const int headerLen = 8;
            MemoryStream streamPacket = new MemoryStream();
            BinaryWriter writer = new BinaryWriter(streamPacket);
            writer.Write(headerLen + bodyLen);
            writer.Write(10000);
            writer.Write(streamBody.ToArray());

            int packetLen = (int)streamPacket.Length;

            _clientSocket.BeginSend(streamPacket.ToArray(), 0, packetLen, 0, new AsyncCallback(onSendCompleted), _clientSocket);
        }
    }
}
