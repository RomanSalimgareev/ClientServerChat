#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

#define PORT 8080
#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSADATA WSData;
	SOCKET server, client;
	SOCKADDR_IN serverAddr, clientAddr;

	int result = WSAStartup(MAKEWORD(2, 2), &WSData);
	if (result == 0)
	{
		std::cout << "good" << "\n";
	}

	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server != INVALID_SOCKET)
	{
		std::cout << "good1" << "\n";
	}

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(PORT);
	bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	listen(server, 5);

	int clientAddrSize = sizeof(clientAddr);
	client = accept(server, (SOCKADDR*)&clientAddr, &clientAddrSize);
	if (client != INVALID_SOCKET)
	{
		char buffer[1024] = "Hello client!";
		std::cout << buffer;
		send(client, buffer, sizeof(buffer), 0);
	}
	closesocket(server);
	closesocket(client);
	WSACleanup();

	return 0;
}