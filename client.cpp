#include <string>
#include <iostream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOK = WSAStartup(ver, &wsData);
    if (wsOK != 0) {
        cerr << "Can't initialize winsock! Quitting" << endl;
        return -1;
    }

    // Create a socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cerr << "Can't create a socket! Quitting" << endl;
        return -1;
    }

    // Fill in the hint structure
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000); // Port to connect on
    inet_pton(AF_INET, "127.0.0.1", &hint.sin_addr);

    // Connect to the server
    int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connResult == SOCKET_ERROR) {
        cerr << "Can't connect to server! Quitting" << endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Do-while loop to send and receive data
    char buf[4096];
    string userInput;

    while (true) {
        // Prompt the user for some text
        cout << "> ";
        getline(cin, userInput);

        // Send the text
        if (userInput.size() > 0) {
            int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
            if (sendResult == SOCKET_ERROR) {
                cerr << "Error in send(). Quitting" << endl;
                break;
            }
        }

        // Wait for response
        ZeroMemory(buf, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == SOCKET_ERROR) {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived > 0) {
            // Display response from the server
            cout << "SERVER> " << string(buf, 0, bytesReceived) << endl;
        }
    }

    // Gracefully close down everything
    closesocket(sock);
    WSACleanup();

    return 0;
}
