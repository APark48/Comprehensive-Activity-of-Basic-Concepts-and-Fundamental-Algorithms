#pragma once
#include "Data.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <set>

class Reader{
private:
    std::vector<Data> reader;
public:
    Reader(){};
    ~Reader(){};

    // Function to print all records
    void print(){
        unsigned int size = reader.size();
        for (size_t i = 0; i < size; i++){
            std::cout << "Date: " << reader.at(i).getDate() << std::endl;
            std::cout << "Time: " << reader.at(i).getTime() << std::endl;
            std::cout << "Source IP: " << reader.at(i).getSourceIp() << std::endl;
            std::cout << "Source Port: " << reader.at(i).getSourcePort() << std::endl;
            std::cout << "Source Hostname: " << reader.at(i).getSourceHostname() << std::endl;
            std::cout << "Destination IP: " << reader.at(i).getDestinationIp() << std::endl;
            std::cout << "Destination Port: " << reader.at(i).getDestinationPort() << std::endl;
            std::cout << "Destination Hostname: " << reader.at(i).getDestinationHostname() << std::endl;
            std::cout << "-------------------------------------------" << std::endl;
        } 
    }
    
    // Function to push a value of a Data type object to reader 
    void pushRecord(Data data){
        reader.push_back(data);
    } 
    
    // Function to return total registers
    int totalRegisters(){
        return reader.size();
    } 

    // Function to return second day records
    int secondDayRecords(){
        std::string firstday = reader.at(0).getDate();

        int totalCount = 0;
        int position = 0;

        while (reader.at(position).getDate() == firstday){
            totalCount++;
            position++;
        }
        return totalCount;
    } 

    // Function to return if any of the PCs belongs to given user
    bool belonging(std::string name){
        std::string hostName = name+".reto.com";
        int size = reader.size();
        bool found = false;

        for (int i=0; i<size;i++){
            if (reader.at(i).getDestinationHostname() == hostName){
                found=true;
            }
        }
        return found;
    } 
    
    // Function to return if any PC belongs to server.reto.com
    bool serverReto(){
        bool found = false;
        int size = reader.size();
        for (int i=0; i<size;i++){
            if (reader.at(i).getDestinationHostname() == "server.reto.com"){
                found = true;
            }
        }
        return found;
    } 

    std::string getHostName(int position){
        return reader.at(position).getSourceHostname();
    }
    std::string getSourceIp(int position){
        return reader.at(position).getSourceIp();
    }
    std::string getDestinationIp(int position){
        return reader.at(position).getDestinationIp();
    }

    void printHostname(){
        std::set<std::string> hostname;
        int size = reader.size();
        for (int i=0; i<size; i++){
            hostname.insert(reader.at(i).getDestinationHostname());
        }
        for (auto i:hostname){
            std::cout << i << std::endl;
        }
    }
    
    void dayConnection(std::string date){
        std::map<std::string, int> dict;
        int size = reader.size();
        int count = 1;
        for (int i=0; i<size;i++){
            if (reader.at(i).getDate() == date){
                if (reader.at(i).getDestinationHostname() != "-"){
                    dict.insert(std::make_pair(reader.at(i).getDestinationHostname(), count));
                }
            }
            count++;
        }
        std::map<std::string, int>::iterator iter;
        for (iter = dict.begin(); iter != dict.end(); iter++){
            std::cout << iter->first<< ":" << "\t" << iter->second << std::endl;
        }
    }
    
};