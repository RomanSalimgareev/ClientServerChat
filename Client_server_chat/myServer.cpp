#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSADATA WSData;
	SOCKET server;
	SOCKADDR_IN serverAddr;

	int result = WSAStartup(MAKEWORD(2,2), &WSData);
	if (result == 0)
		std::cout << "good" << "\n";

	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server != INVALID_SOCKET)
		std::cout << "good1" << "\n";

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;


	WSACleanup();
}