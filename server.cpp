//https://causeyourestuck.io/2016/01/17/socket-cc-windows/

#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <string>
 
using namespace std;
 
int main()
{   
    //system("fire.cmd & exit");
    
    //==================
    
    WSADATA WSAData;
 
    SOCKET server, client;
 
    SOCKADDR_IN serverAddr, clientAddr;
 
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
 
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(55555);
 
    bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(server, 0);
    
    cout << "Listening for incoming connections..." << endl;
 
    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);
    if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
    {
        cout << inet_ntoa(clientAddr.sin_addr) << endl;
        cout << "Client connected!" << endl;
        
        recv(client, buffer, sizeof(buffer), 0);
        
        while(strcmp(buffer,"/quit")){
            cout << "Client says:\n" << buffer << endl;
            
            cout << "\nWhat is your Message?" << endl;
            
            memset(&buffer[0], 0, sizeof(buffer));
            cin.ignore();
            cin.get(buffer, 1024);
            
            send(client, buffer, sizeof(buffer), 0);
            
            if(strcmp(buffer,"/quit")){
                cout << "Message sent!" << endl;
                
                recv(client, buffer, sizeof(buffer), 0);
            }
        }
        memset(buffer, 0, sizeof(buffer));
        closesocket(client);
        cout << "Client disconnected." << endl;
    }
    system("pause");
}
