

#include <fstream>
#include <iostream>

int main(){
    
    std::ofstream io("test.xxx", std::ios::binary | std::ofstream::trunc);
    
    char msg[4] = {0,1,2,3};
    if(io){
        std::cout << sizeof(msg[0]) << '\n' << std::endl;
        std::cout << msg[0] << std::endl;
        std::cout << msg[1] << std::endl;
        std::cout << msg[2] << std::endl;
        std::cout << msg[3] << std::endl;
        io.write(reinterpret_cast<const char*>(&msg[0]), sizeof(msg[0]));
        io.write(reinterpret_cast<const char*>(&msg[1]), sizeof(msg[1]));
        io.write(reinterpret_cast<const char*>(&msg[2]), sizeof(msg[2]));
        io.write(reinterpret_cast<const char*>(&msg[3]), sizeof(msg[3]));
    }
    io.close();
    io.clear();
    
    return 0;
}

//https://beej.us/guide/bgnet/html/single/bgnet.html