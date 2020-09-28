//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#include "Reader.h"
#include "Sorter.h"
#include "Searcher.h"
#include "Data.h"
#include <iostream>

bool compareHostnameF (Data<std::string> &a, Data<std::string> &b){
     return 0;
}

bool compareIPFuente(Data<std::string> &a, Data<std::string> &b){
    return 0;
};


int main(){
    std::vector<class Data<std::string>> datos;
    datos=readRecords();
    int dia2;
    dia2=segundoDia(datos);
    std::cout << dia2 << std::endl;
    Sorter<Data<std::string>> organizar;
    organizar.ordenaQuick(datos, &compareHostNameFuente);
    countNames(datos);
    organizar.ordenaQuick(datos, &compareIPFuente);
    direccionIP(datos);
    

    return 0;
}
