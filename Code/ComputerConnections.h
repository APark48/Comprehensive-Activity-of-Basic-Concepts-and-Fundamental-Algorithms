//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "Data.h"

template <typename T>
class ComputerConnections {
private:
    T IP;
    T name;
    T sourceConnections;
    T destinationConnections;    
public:
    ComputerConnections(std::string sourceHostname){

    }
    ~ComputerConnections(){}
    
    T sourceConnections(std::vector<T> elements){
        std::vector<T> reversedElements;
        while (elements.size() != 0){
            reversedElements.push_back(elements.back());
            elements.pop_back();
        }
        return reversedElements;
    }

    T destinationConnections(int sourceIP){

    }


    T createNewSourceIP(int n){

    }
};
