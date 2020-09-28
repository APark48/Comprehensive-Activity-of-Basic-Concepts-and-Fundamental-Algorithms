//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#include "Data.h"
#include <iostream>
#include <vector>

template <typename T>
int binarySearch(int inicio, int final, int valor, std::vector<class Data<T>> &valores){
    if(final>=inicio){
        int i=inicio + (final-inicio)/2;
        if(valores.at(i).getSourceHostname()==valor){
            return i;
        } 
        if (valores.at(i).getSourceHostname()>valor){
            return binarySearch(inicio, i-1, valor, valores);
        }
        return binarySearch(i+1, final, valor, valores);
    }
    return -1;
}