//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#include "Data.h"
#include <iostream>
#include <vector>

template <typename T>
int binarySearch(int start, int end, T value, std::vector<class Data<T>> &elements){
    if(end>=start){
        int i=start + (start-end)/2;
        if(valores.at(i).getSourceHostname()==value){
            return i;
        } 
        if (valores.at(i).getSourceHostname()>value){
            return binarySearch(start, i-1, value, elements);
        }
        return binarySearch(i+1, end, value, elements);
    }
    return -1;
}