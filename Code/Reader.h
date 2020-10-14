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
    int lenght(){
        return data.size();
    }
    int day2(std::string &date){
        std::string dayOne, dayTwo = "";
        int count = 0;
        int countTwo = 0;
        dayOne=data.at(count).getDate();
        while (data.at(count).getDate()==dayOne){
            count++;
        }
        dayTwo=data.at(count).getDate();
        while(data.at(count).getDate()==dayTwo){
            countTwo++;
            count++;
        }
        std::cout<<"Second day is " << dayTwo << std::endl;
        std::cout<<"Number of times visualized ";
        return countTwo;
    }
    int find_computer_owner(std::vector<std::string> names){
        Search<Data> my_search;
        for (size_t i = 0; i < names.size(); i++){
            Data dummy_log;
            dummy_log.setSourceHostname(names[i]);
            int search_res = my_search.search_sequential(data, dummy_log, &Data::compareSourceHostname);
            if (search_res >= 0){
                return search_res;
            }  
        }
        return -1;
    }
    std::vector<int> direccionIP (){
        std::string ipCompania = data.at(data.size()-1).getSourceIp();
        ipCompania.erase(10,ipCompania.length()-10);
        ipCompania.append("0");
        std::cout << "Company IP address is:  " << ipCompania << std::endl;
    }
    std::vector<int> portCount(int threshold){
        vector<int> ports;
        Search<int> searcher;
        for (size_t i = 0; i < data.size(); i++)    
        {
            int dst_port = atoi(data[i].getDestinationPort().c_str());
            if (dst_port < threshold)
            {
                if (searcher.search_sequential(ports, dst_port, &Data::compareEqual) < 0)
                    ports.push_back(dst_port);
            }
        }
        return ports;  
    }
};