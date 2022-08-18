// ConsoleApplication_Serial_Com.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CSerialCom.h"

int main()
{
    CSerialCom port;
    CString portName = "COM3";
    if(!(port.OpenPort(portName)))
    {
        std::cout << "Open port failed!!\n";
    }
    else
    {
        std::cout << "Port open successfully\n";
        if (!port.ConfigurePort(19200, 8, 0, ONESTOPBIT))
        {
            std::cout << "Set successfully!\n";
        }
        else
        {
            std::cout << "set Unsuccessfull\n";
        }
    }
    return 0;
}
