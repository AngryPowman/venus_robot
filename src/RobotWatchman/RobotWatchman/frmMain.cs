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
using RobotWatchman.network;

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
            RobotNetworkEvent.init();
        }

        public void addLog(string log)
        {
            lstLog.Items.Add("[" + DateTime.Now.ToString() + "] " + log);
            lstLog.SelectedIndex = lstLog.Items.Count - 1;
        }

        private void btnRobotLogin_Click(object sender, EventArgs e)
        {
            RobotNetworkEvent.connectToRobotServer(txtRobotLoginServer.Text, Convert.ToUInt16(txtRobotLoginPort.Text));
            RobotNetworkEvent.sendRobotLoginRequest(txtRobotLoginVerifyKey.Text);
        }

        public void robotLoginCallback(MemoryStream stream)
        {
            Protocol.S2CRobotLoginRsp response = RobotNetworkEvent.parseMessage<Protocol.S2CRobotLoginRsp>(stream);

            if (response.login_result == true)
            {
                btnRobotLogin.Enabled = false;
                btnRobotDisconnect.Enabled = true;

                addLog("机器人服务器验证成功！");
            }
            else
            {
                addLog("机器人服务器验证失败，请检查密钥是否正确。");
            }
        }
    }
}
