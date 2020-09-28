//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include "Data.h"
#include <iostream>
#include <vector>

template <typename T>
int binarySearch(int start, int end, T value, std::vector<class Data<T>> &elements){
    if(end>=start){
        int mid=start + (start-end)/2;
        if(elements.at(mid).getSourceHostname()==value){
            return mid;
        } 
        if (elements.at(mid).getSourceHostname()>value){
            return binarySearch(start, mid-1, value, elements);
        }
        return binarySearch(mid+1, end, value, elements);
    }
    return -1;
}