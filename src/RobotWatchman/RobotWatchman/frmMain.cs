using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Diagnostics;
using ProtoBuf;
using System.Runtime.Serialization.Formatters.Binary;

namespace RobotWatchman
{
    public partial class frmMain : Form
    {

        Socket _clientSocket;
        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
        }

        private void addLog(string log)
        {
            lstLog.Items.Add("[" + DateTime.Now.ToString() + "] " + log);
        }

        private void btnRobotLogin_Click(object sender, EventArgs e)
        {
            //for (int i = 0; i < 300; i++)
            //{
                connectRobotServer(txtRobotLoginServer.Text, Convert.ToUInt16(txtRobotLoginPort.Text));
            //}
        }

        /// <summary>
        /// 连接到机器人服务器
        /// </summary>
        /// <param name="ip"></param>
        /// <param name="port"></param>
        private void connectRobotServer(string ip, UInt16 port)
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


        /*******************************************************************************************
        /* 网络事件
        /*******************************************************************************************/
        void onConnected(IAsyncResult result)
        {
            Socket socket = (Socket)result.AsyncState;
            if (socket.Connected)
            {
                socket.EndConnect(result);

                // Connect to robot server
                Protocol.RobotLoginReq robotLoginReq = new Protocol.RobotLoginReq();
                robotLoginReq.verify_key = txtRobotLoginVerifyKey.Text;

                // Serialize body data first
                MemoryStream streamBody = new MemoryStream();
                //BinaryFormatter protoDataFormatter = new BinaryFormatter();
                //protoDataFormatter.Serialize(streamBody, messageBase);

                Serializer.SerializeWithLengthPrefix(streamBody, robotLoginReq, PrefixStyle.None);
                UInt32 bodyLen = (uint)streamBody.Length;

                // Serialize header data and body
                const int headerLen = 8;
                MemoryStream streamPacket = new MemoryStream();
                BinaryWriter writer = new BinaryWriter(streamPacket);
                writer.Write(headerLen + bodyLen);
                writer.Write(10000);
                writer.Write(streamBody.ToArray());

                int packetLen = (int)streamPacket.Length;

                socket.BeginSend(streamPacket.ToArray(), 0, packetLen, 0, new AsyncCallback(onSendCompleted), socket);
            }
        }

        private static void onSendCompleted(IAsyncResult ar)
        {
            try
            {
                // Retrieve the socket from the state object.     
                Socket socket = (Socket)ar.AsyncState;

                // Complete sending the data to the remote device.     
                int bytesSent = socket.EndSend(ar);

                Console.WriteLine("Sent {0} bytes to server.", bytesSent);
                //handler.Shutdown(SocketShutdown.Both);
                //handler.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

    }
}
