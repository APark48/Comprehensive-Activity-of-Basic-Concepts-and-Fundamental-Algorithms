//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include <vector>
#include "Data.h"
template <typename T>
int binarySearch(int inicio, int final, T valor, std::vector<T> &valores){
    if(final>=inicio){
        int i=inicio + (final-inicio)/2;
        if(valores.at(i)==valor){
            return i;
        } 
        if (valores.at(i)>valor){
            return binarySearch(inicio, i-1, valor, valores);
        }
        return binarySearch(i+1, final, valor, valores);
    }
    return -1;
}