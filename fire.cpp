//==============================================================================
//    Project: networking
//    File: fire.cpp
//    Author: Alex Labontu
//    Date: 10/2/2018 11:10:48 PM
//==============================================================================

/*
    Copyright (c) Microsoft Corporation

    SYNOPSIS

        Sample code for the Windows Firewall COM interface.
*/

#include <windows.h>   // WinApi header
#include <iostream>     /* abs */


int main(){
            HANDLE console;
            console = GetStdHandle(STD_OUTPUT_HANDLE);
    
    for(int k = 0; k < 256; k++){
                    SetConsoleTextAttribute(console, k);
                    std::cout << k << "Hello" << std::endl;
        
    }
    
    return 0;
}