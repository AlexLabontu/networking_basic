//https://causeyourestuck.io/2016/01/17/socket-cc-windows/

#include <iostream>
#include <winsock2.h>
 
using namespace std;
 
int main()
{
    
    //==================*/
    
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
 
	//hostent *host = gethostbyname(HOSTNAME_CSTR);
 
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
    
    char addresser[16];
    cout << "IP: ";
    cin.clear();
    cin >> addresser;
    
    if(addresser[0]=='m'&&addresser[1]=='e')
        addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
    else
        addr.sin_addr.s_addr = inet_addr(addresser); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
    //sock.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;
	addr.sin_family = AF_INET;
    addr.sin_port = htons(55555);
 
    if(!connect(server, (SOCKADDR *)&addr, sizeof(addr))){
        cout << "Connected to server!" << endl;
        cout << "What is your Message?" << endl;
 
        char buffer[1024];
        
        cin.ignore();
        cin.get(buffer, 1024);
        
        send(server, buffer, sizeof(buffer), 0);
        
        while(strcmp(buffer,"/quit")){
            cout << "Message sent!" << endl;
            
            recv(server, buffer, sizeof(buffer), 0);
            if(strcmp(buffer,"/quit")){
                cout << "Server says:\n" << buffer << endl;
                
                cout << "\nWhat is your Message?" << endl;
                
                memset(&buffer[0], 0, sizeof(buffer));
                cin.ignore();
                cin.get(buffer, 1024);
                
                send(server, buffer, sizeof(buffer), 0);
            }
        }
        memset(buffer, 0, sizeof(buffer));
    }
    closesocket(server);
    WSACleanup();
    cout << "Socket closed." << endl << endl;
    system("pause");
}