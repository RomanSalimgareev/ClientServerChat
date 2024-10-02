#include <WinSock2.h>

#pragma comment (lib, "ws2_32.lib")

int main()
{
	WSADATA wsaData;
	SOCKET client;
	SOCKADDR_IN clientAddr

	int result = WSAStartup(MAKEWORD(2, 0), wsaData);

	client = socket(AF_INET, SOCK_STREAM, 0);
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(8000);
	clientAddr.sin_addr = INADDR_ANY;
	
	bind(client, (SOCKADDR*)&clientAddr, sizeof(clientAddr));

	connect(client, (SOCKADDR*)&clientAddr, sizeof(clientAddr));
	char buffer[1024];
	recv(client, buffer, sizeof(buffer), 0);
	
	std::cout << "Message from server:" << buffer << "\n";

	closesocket(client);
	WSACleanup();
}