//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>

template <typename T>
class Search 
{
private:    

public:
    Search() {};
    ~Search() {};

    int sequentialSearch(std::vector<T> arr, T val, bool (*compare)(T &a, T &b))
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            if ((*compare)(val, arr[i]))
                return i;
        }
        return -1;        
    };
};