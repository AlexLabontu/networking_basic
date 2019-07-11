client.exe:makefile client.cpp
	g++ client.cpp -o client.exe -lws2_32 -static-libgcc -static-libstdc++ "C:\utils\NP++\compiler\MinGW\lib\libws2_32.a"
	
server.exe:makefile makefile server.cpp
	g++ server.cpp -o server.exe -lws2_32 -static-libgcc -static-libstdc++ "C:\utils\NP++\compiler\MinGW\lib\libws2_32.a"
	
bin_save.exe:makefile bin_save.cpp
	g++ bin_save.cpp -o bin_save.exe -lws2_32 -static-libgcc -static-libstdc++
	
fire.exe:makefile fire.cpp
	g++ fire.cpp -o fire.exe -lws2_32 -static-libgcc -static-libstdc++
	
all:makefile client.exe server.exe

clear:
	rm *.exe
	rm test.xxx