//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#include "Reader.h"
#include "Sorter.h"
#include "Searcher.h"
#include "Data.h"
#include "ComputerConnections.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool Data::compareSourceHostname(Data &a, Data &b){
    stringstream ssa(a.getSourceHostname());
    string h1, h2;
    getline(ssa, h1, '.');
    stringstream ssb(b.getSourceHostname());
    getline(ssb, h2, '.');
    
    return h1 == h2;
}

bool Data::compareEqual(int &a, int &b){
    return a == b;
}
/*
int main(){
    Data data;
    data=reader();
    int secondDay;
    secondDay=day2(data);
    std::cout << secondDay << std::endl;
    Quicksort<Data<std::string>> organize;
    organize.sort(data, &compareSourceHostname);
    countNames(data);
    organize.sort(data, &compareSourceIP);
    direccionIP(data);
    organize.sort(data, &compareDestinationHostname);
    direccionIP(data);
    organize.sort(data, &compareDestinationPort);
    portCount(data);

    return 0;
}
*/
