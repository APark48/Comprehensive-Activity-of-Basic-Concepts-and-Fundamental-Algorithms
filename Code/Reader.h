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

class Reader{
private:
    std::vector<Data> data;

public:
    ~Reader();
    Reader();

    int loadDataFromcsv(std::string path){
        std::ifstream file(path);
        if (!file.is_open())
            return -1;
        std::string line, date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
        while (getline(file, line)){
            std::stringstream ss(line);
            getline(ss, date, ',');
            getline(ss, time, ',');
            getline(ss, sourceIp, ',');
            getline(ss, sourcePort, ',');
            getline(ss, sourceHostname, ',');
            getline(ss, destinationIp, ',');
            getline(ss, destinationPort, ',');
            getline(ss, destinationHostname, '\n');
            Data alog(date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname);
            data.push_back(alog);
        }
        return 1;
    }
    void print_data(){
        for (size_t i = 0; i < data.size(); i++){
            data[i].print();
        }    
    }
    int length(){
        return data.size();
    }
    void day2(int day, std::string &date, int &count){
        date = "";
        count = 0;

        int curr = -1;
        for (size_t i = 0; i < data.size(); i++){
            if (data[i].getDate() != date){
                curr++;
                if (day >= curr){
                    date = data[i].getDate();
                }
                else{
                    break;
                }                
            }
            if (day == curr){
                count++;
            }
        }
    }    
    int findHostname(std::vector<std::string> names){
        Search<Data> mySearch;
        for (size_t i = 0; i < names.size(); i++){
            Data dummyData;
            dummyData.setSourceHostname(names[i]);
            int searchRes = mySearch.sequentialSearch(data, dummyData, &Data::compareSourceHostname);
            if (searchRes >= 0){
                return searchRes;
            }  
        }
        return -1;
    }
    std::vector<std::string> addressIp (){
        vector<std::string> addresses;
        std::string address;
        for (size_t i = 0; i < data.size(); i++){
            address = data[i].getSourceIp();
            address.erase(10,address.length()-10);
            address.append("0");
        }
        std::cout << "Company IP address is:  " << address << std::endl;
    }
    std::vector<int> portCount(int threshold){
        vector<int> ports;
        Search<int> searcher;
        for (size_t i = 0; i < data.size(); i++){
            int dst_port = atoi(data[i].getDestinationPort().c_str());
            if (dst_port < threshold){
                if (searcher.sequentialSearch(ports, dst_port, &Data::compareEqual) < 0)
                    ports.push_back(dst_port);
            }
        }
        return ports;  
    }
};