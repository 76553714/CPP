#include <iostream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOK = WSAStartup(ver, &wsData);
    if (wsOK != 0) 
    {
        cerr << "Can't initialize winsock! Quitting" << endl;
        return -1;
    }

    // Create a socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET) 
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return -1;
    }

    // Bind the IP address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000); // Choose any available port
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

    cout << "Server is listening..." << endl;

    // Wait for a connection
    sockaddr_in client;
    int clientSize = sizeof(client);

    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connected on

    ZeroMemory(host, NI_MAXHOST);    // same as memset(host, 0, NI_MAXHOST);
    ZeroMemory(service, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        cout << host << " connected on port " << service << endl;
    }
    else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    // Close listening socket (moved outside the loop to keep listening)
    closesocket(listening);

    // While loop: accept and display the message from the client
    char buf[4096];

    while (true) {
        ZeroMemory(buf, 4096);

        // Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == SOCKET_ERROR) {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived == 0) {
            cout << "Client disconnected" << endl;
            break;
        }

        // Display the message received from the client
        cout << "CLIENT> " << string(buf, 0, bytesReceived) << endl;

        // Optional: Send a response back to the client
        string response = "Message received!";
        send(clientSocket, response.c_str(), response.size() + 1, 0);
    }

    // Close the socket
    closesocket(clientSocket);

    // Cleanup winsock
    WSACleanup();

    return 0;
}
