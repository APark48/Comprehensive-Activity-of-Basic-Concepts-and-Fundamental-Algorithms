//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include "Data.h"
#include "Searcher.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::getline;

std::vector<class Data<std::string>> reader(){
    std::ifstream data("equipo11.csv");
    std::string date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
    std::vector<class Data<std::string>> read;
    while (data.peek()!=EOF){
        std::getline(data, date, ',');
        std::getline(data, time, ',');
        std::getline(data, sourceIp, ',');
        std::getline(data, sourcePort, ',');
        std::getline(data, sourceHostname, ',');
        std::getline(data, destinationIp, ',');
        std::getline(data, destinationPort, ',');
        std::getline(data, destinationHostname, '\n');
        Data<std::string> r(date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname);
        read.push_back(r);
    }
    
    int count=0;
    for(int i=0; i<read.size(); i++){
        count+=1;
    }

    std::cout << "The .csv file has " << count << " registers." << std::endl;
    data.close();
    return read;
}

int day2(std::vector<class Data<std::string>>&read){
    std::string dayOne, dayTwo = "";
    int count = 0;
    int countTwo = 0;
    dayOne=read.at(count).getDate();
    while (read.at(count).getDate()==dayOne){
        count++;
    }

    dayTwo=read.at(count).getDate();
    while(read.at(count).getDate()==dayTwo){
        countTwo++;
        count++;
    }
    std::cout<<"Second day is " << dayTwo << std::endl;
    std::cout<<"Number of times visualized ";
    return countTwo;
}

void countNames(std::vector<class Data<std::string>> &read){
    int count = 7;
    std::string name;
    std::vector<std::string> names(read.size());
    std::vector<int> positions(count);
    for(int i=0; i<count; i++){
        std::cout << "Name to find: ";
        std::cin >> name;
        names.push_back(name);
        names[i].append("reto.com");
        positions.at(i) = binarySearch<std::string>(0, read.size()-1, names.at(i), names);
        if(positions.at(i)==-1){
            std::cout << name << " is not an employee." << std::endl;
        } else {
            std::cout << name << " is an employee." << std::endl;
        }
    };
}

void direccionIP(std::vector<class Data<std::string>>&read){
    std::string ipCompania = read.at(read.size()-1).getSourceIp();
    ipCompania.erase(10,ipCompania.length()-10);
    ipCompania.append("0");
    std::cout << "Company IP address is:  " << ipCompania << std::endl;
}

void mails(std::vector<class Data<std::string>> &read){
    int count;
    std::cout<< "How many mails do you want to search?: ";
    std::cin >> count;
    std::vector<std::string> mails(count);
    for(int i=0; i<count; i++){
        std::cout << "Write name in lowercase: ";
        std::cin >> mails.at(i);
        mails.at(i).append(".com");
    };

    std::vector<std::string> hostNames;
    for(int i=0; i<read.size(); i++){
        std::string destinationHost = read.at(i).getDestinationHostname();
        hostNames.push_back(destinationHost);
    }

    std::vector<int> positions(count);
    for(int j=0; j<count; j++){
        positions.at(j)=binarySearch<std::string>(0, hostNames.size()-1, mails.at(j), hostNames);
        if(positions[j]==-1){
            std::cout << mails.at(j) << " is not an email used in the company." << std::endl;
        } else {
            std::cout << mails.at(j) << " is a mail used in the company." << std::endl;
        }
    };
}

void portCount(std::vector<class Data<std::string>> &read){
    std::vector<std::string> ports;
    int check;
    for(int i=0; i<read.size(); i++){
        check=binarySearch(0, ports.size()-1, read.at(i).getDestinationPort(), ports);
        if(check==-1){
            ports.push_back(read.at(i).getDestinationPort());
        }
    }
    for(int j=0; j<ports.size(); j++){
        std::cout << ports.at(j) << std::endl;
    }
}