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
        }

        public void addLog(string log)
        {
            lstLog.Items.Add("[" + DateTime.Now.ToString() + "] " + log);
        }

        private void btnRobotLogin_Click(object sender, EventArgs e)
        {
            RobotNetworkEvent.connectToRobotServer(txtRobotLoginServer.Text, Convert.ToUInt16(txtRobotLoginPort.Text));
            RobotNetworkEvent.sendRobotLoginRequest(txtRobotLoginVerifyKey.Text);
        }



    }
}
