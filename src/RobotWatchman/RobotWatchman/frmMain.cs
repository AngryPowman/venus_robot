using ProtoBuf;
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
using System.Threading.Tasks;
using System.Windows.Forms;

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
            Protocol.RobotLoginReq req = new Protocol.RobotLoginReq();
        }

        private void addLog(string log)
        {
            lstLog.Items.Add("[" + DateTime.Now.ToString() + "] " + log);
        }

        private void btnRobotLogin_Click(object sender, EventArgs e)
        {
            connectRobotServer(txtRobotLoginServer.Text, Convert.ToUInt16(txtRobotLoginPort.Text));
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
                //发送机器人登录请求
                Protocol.RobotLoginReq robotLoginReq = new Protocol.RobotLoginReq();
                robotLoginReq.verify_key = txtRobotLoginVerifyKey.Text;

                MemoryStream stream = new MemoryStream();
                Serializer.Serialize(stream, robotLoginReq);

                socket.BeginSend(stream.ToArray(), 0, (int)stream.Length, 0, new AsyncCallback(onSendCompleted), socket);
            }
        }

        private static void onSendCompleted(IAsyncResult ar)
        {
            try
            {
                // Retrieve the socket from the state object.     
                Socket handler = (Socket)ar.AsyncState;

                // Complete sending the data to the remote device.     
                int bytesSent = handler.EndSend(ar);

                Console.WriteLine("Sent {0} bytes to server.", bytesSent);
                handler.Shutdown(SocketShutdown.Both);
                handler.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

    }
}
