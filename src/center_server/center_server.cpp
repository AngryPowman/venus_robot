// center_server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "asio_service_deamon.h"

int main(int argc, char* argv[])
{
    try
    {
        AsioServiceDeamon serviceEntry;
        serviceEntry.start("robot_service", 4);
    }
    catch (...)
    {
        std::cout << "An unknown exception occurred." << std::endl;
    }

    system("pause");
	return 0;
}

