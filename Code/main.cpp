//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#include "Reader.h"
#include "Sorter.h"
#include "Searcher.h"
#include "Data.h"
#include <iostream>

bool compareSourceHostname (Data<std::string> &a, Data<std::string> &b){
     return a.getSourceHostname()<b.getSourceHostname();
}

bool compareSourceIP(Data<std::string> &a, Data<std::string> &b){
    return a.getSourceIp()<b.getSourceIp();
};


int main(){
    std::vector<class Data<std::string>> datos;
    datos=reader();
    int dia2;
    dia2=segundoDia(datos);
    std::cout << dia2 << std::endl;
    Quicksort<Data<std::string>> organizar;
    organizar.sort(datos, &compareSourceHostname);
    countNames(datos);
    organizar.sort(datos, &compareSourceIP);
    direccionIP(datos);
    

    return 0;
}
