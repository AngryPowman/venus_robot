// center_server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "asio_service_deamon.h"
#include "ascii.h"
#include "socket.h"

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

