#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

#define PORT 8080
#pragma comment (lib, "ws2_32.lib")

int main()
{
	WSADATA wsaData;
	SOCKET client;
	SOCKADDR_IN clientAddr;

	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	client = socket(AF_INET, SOCK_STREAM, 0);
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(PORT);
	clientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");;

	int status = connect(client, (SOCKADDR*)&clientAddr, sizeof(clientAddr));
	char buffer[1024] = {};
	recv(client, buffer, sizeof(buffer), 0);
	
	std::cout << "Message from server:" << buffer << "\n";

	closesocket(client);
	WSACleanup();

	return 0;
}