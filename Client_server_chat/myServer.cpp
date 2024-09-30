#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSADATA WSData;
	SOCKET server, client;
	SOCKADDR_IN serverAddr, clientAddr;

	int result = WSAStartup(MAKEWORD(2, 0), &WSData);
	if (result == 0)
	{
		std::cout << "good" << "\n";
		return 1;
	}

	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server != INVALID_SOCKET)
	{
		std::cout << "good1" << "\n";
		return 1;
	}

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(8000);
	
	bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	listen(server, 2);

	int clientAddrSize = sizeof(clientAddr);
	client = accept(server, (SOCKADDR*)&clientAddr, &clientAddrSize);
	if (client != INVALID_SOCKET)
	{
		char buffer[1024] = "Hello client!";
		send(client, buffer, sizeof(buffer), 0);
	}

	closesocket(server);
	closesocket(client);
	WSACleanup();
}