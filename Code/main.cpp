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

bool compareDestinationHostname (Data<std::string> &a, Data<std::string> &b){
     return a.getDestinationHostname()<b.getDestinationHostname();
}

bool compareDestinationPort(Data<std::string> &a, Data<std::string> &b){
    return a.getDestinationPort()<b.getDestinationPort();
};

int main(){
    std::vector<class Data<std::string>> data;
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
