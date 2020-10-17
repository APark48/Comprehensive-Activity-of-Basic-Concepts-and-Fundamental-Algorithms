//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.

// Date created: 13/October/2020
// Last modified: 16/October/2020 

// Computer Connections is a class consisting of three functions:
// 1. newSourceConnection that reverses the logs.
// 2. newDestinationConnection that returns logs in order.
// 3. createNewIp which appends a new number to the end of the IP.

#pragma once
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "Data.h"
#include "Reader.h"

template <typename T>
class ComputerConnections:Reader{
private:
    T ip;
    T name;
    T sourceConnections;
    T destinationConnections;    
public:
    ComputerConnections(){
    }
    ~ComputerConnections(){}
    
    // Reversing vector by simulating a stack, current vector's last element will be pushed back to new vector and popped.
    std::vector<T> newSourceConnection(std::vector<T> elements){
        // Empty reversed vector
        std::vector<T> reversedElements;
        while (elements.size() != 0){
            // Pushing last element of current vector
            reversedElements.push_back(elements.back());
            // Popping current vector element
            elements.pop_back();
        }
        return reversedElements;
    }

    // Function that returns source IP in order  
    std::vector<T> newDestinationConnection(){
        std::vector<std::string> addresses;
        std::string address;
        for (int i = 0; i<data.size(); i++){
            address = data[i].getSourceIp();
            if (address != "-"){
                addresses.push_back(address);     
            }
        }
        return addresses;
    }

    // Function to append to the end of our IP address the value we ask the user to input to then create a vector with only this addresses.
    std::vector<T> createNewIp(std::string num){
        std::vector<std::string> addresses;
        std::string address;
        for (size_t i = 0; i < data.size(); i++){
            address = data[i].getSourceIp();
            address.erase(10,address.length()-10);
            address.append(num);
            if (address == data[i].getSourceIp()){
                addresses.push_back(address);
            }
        }
        return addresses;
    }
};
