// center_server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "asio_service_deamon.h"
#include "ascii.h"
#include "socket.h"

using namespace Poco::Net;

int main(int argc, char* argv[])
{

    try
    {
        AsioServiceDeamon serviceEntry;
        serviceEntry.start("robot_service", 1);
    }
    catch (...)
    {
        std::cout << "An unknown exception occurred." << std::endl;
    }

    system("pause");
	return 0;
}

