using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
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
        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            Protocol.RobotLoginReq req = new Protocol.RobotLoginReq();
            req.account = "138001655";

            startNetwork();
        }

        private void addLog(string log)
        {
            lstLog.Items.Add("[" + DateTime.Now.ToString() + "] " + log);
        }

        TcpClient client = new TcpClient();
        private void startNetwork()
        {
            addLog("CLIENT : socket 连接成功 ...");

            using (NetworkStream stream = client.GetStream())
            {
                //发送
                //Console.WriteLine("CLIENT : 发送数据 ...");

                //msg.WriteTo(stream);

                //关闭
                stream.Close();
            }
            client.Close();
            addLog("CLIENT : 关闭 ...");
        }

    }
}
