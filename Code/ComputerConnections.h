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
    ComputerConnections();
    ~ComputerConnections(){}
    
    // Reversing vector by simulating a stack
    T sourceConnections(std::vector<T> elements){
        // Create empty vector
        std::vector<T> reversedElements;
        while (elements.size() != 0){
            // Push current vectors' last element to new vector
            reversedElements.push_back(elements.back());
            // Pop last value of current vector
            elements.pop_back();
        }
        return reversedElements;
    }

    T destinationConnections(int sourceIP){

    }


    T createNewSourceIP(int n){

    }
};
