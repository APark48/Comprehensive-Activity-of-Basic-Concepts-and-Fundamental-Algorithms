//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include "Data.h"
#include <fstream>
#include <vector>

using std::getline;

std::string date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
std::vector <class Data> read(){
    std::ifstream data("equipo11.csv");
    while(data.peek()!=EOF){
        std::getline(data, date, ',');
        std::getline(data, time, ',');
        std::getline(data, sourceIp, ',');
        std::getline(data, sourcePort, ',');
        std::getline(data, sourceHostname, ',');
        std::getline(data, destinationIp, ',');
        std::getline(data, destinationPort, ',');
        std::getline(data, destinationHostname, '\n');
        Data r(date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname);
        read.push_back(r);
    }
}