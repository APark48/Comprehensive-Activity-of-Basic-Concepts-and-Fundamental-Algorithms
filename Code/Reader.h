//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include "Data.h"
#include <fstream>
#include <vector>

std::vector <class Data> read(){
    std::string date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
    std::ifstream data("equipo11.csv");
    while(data.peek()!=EOF){
        std::getline(data, date, ',');
        std::getline(data, time, ',');
    }
}