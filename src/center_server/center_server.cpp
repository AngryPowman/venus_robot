// center_server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <tcp_client.h>
#include <tcp_connection.h>


struct ClientEventHandler
{
    void onConnectedHandler(const TcpConnectionPtr& connection)
    {
        connection->write((const byte*)"ni mei de", 80);
    }
};

int main(int argc, char* argv[])
{
    IOService io_service;

    ClientEventHandler handler;

    TcpConnectionPtr connection(new TcpConnection(io_service));
    connection->setConnectedCallback(std::bind(&ClientEventHandler::onConnectedHandler, handler, std::placeholders::_1));
    connection->connect(InetAddress("210.209.86.171", 22));
    io_service.service().run();

    system("pause");
	return 0;
}

