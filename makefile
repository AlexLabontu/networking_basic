client.exe:makefile client.cpp
	g++ client.cpp -o client.exe -lws2_32 -static-libgcc -static-libstdc++ "C:\utils\NP++\compiler\MinGW\lib\libws2_32.a"
	
server.exe:makefile makefile server.cpp
	g++ server.cpp -o server.exe -lws2_32 -static-libgcc -static-libstdc++ "C:\utils\NP++\compiler\MinGW\lib\libws2_32.a"
	
all:makefile client.exe server.exe

clear:
	rm *.exe