#pragma once
#include "Reader.h"
#include <stack>

class ComputerConnections{
private:
    std::string ip, name; 
    int inConnections, outConnections;
public:
    ComputerConnections(){};
    ~ComputerConnections(){};

    std::string getIp(){
        return ip;
    }
    int getInConnections(){
        return inConnections;
    }

    // Function to print computer data
    void print(){
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "IP: " << ip << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Total Incoming Connections: " << inConnections << std::endl;
        std::cout << "Total Outgoing Connections: " << outConnections << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
    }

    // Function to set a computer
    void setComputer(Reader data){
        int position;
        std::cout << "Enter random number to set computer: ";
        std::cin >> position;
        ip = data.getSourceIp(position);
        name = data.getHostName(position);
        inConnections = totalInConnections(data);
        outConnections = totalOutConnections(data);
    }

    // Function to return total incoming connections
    int totalInConnections(Reader data){
        int count = 0;
        int size = data.totalRegisters();
        for (int i=0; i<size; i++){
            if (ip == data.getDestinationIp(i)){
                count++;
            }
        }
        return count;     
    }

    // Function to return total outgoing connections
    int totalOutConnections(Reader data){
        int count = 0;
        int size = data.totalRegisters();
        for (int i=0; i<size; i++){
            if (ip == data.getSourceIp(i)){
                count++;
            }
        }
        return count;
    }

    // Function to return last connection of computer
    std::string lastConnection(Reader data){
        std::vector<std::string> last;
        int size = data.totalRegisters();
        for (int i=0; i<size; i++){
            if (data.getSourceIp(i) == ip){
                last.push_back(data.getDestinationIp(i));
            }
        }
        if (ip == last.back()){
            std::cout << "Internal Connection." << std::endl;
        }
        else {
            std::cout << "External Connection." << std::endl;
        }
        return last.back();
    }

    std::map<std::string, int> serverConnections(Reader reader){
        std::map<std::string, int> dict;
        int size = reader.getSize();
        for (int i=0; i<size; i++){
            if(reader.getDestinationHostname(i).erase(0, reader.getDestinationHostname(i).length()-8)!="reto.com"){
                dict.insert(std::make_pair(reader.getDestinationIp(i), NULL));
            }
        }
        return dict;
    }
    std::map<std::string, int> retoServerConnections(Reader reader){
        std::map<std::string, int> dict;
        int size = reader.getSize();
        for (int i=0; i<size; i++){
            if(reader.getDestinationHostname(i).erase(0, reader.getDestinationHostname(i).length()-8)=="reto.com"){
                dict.insert(std::make_pair(reader.getDestinationIp(i), NULL));
            }
        }
        return dict;
    }
    void returnServerIp(Reader data, std::map<std::string, int> dict){
        int size = dict.size();
        for (int i=0; i<size; i++){
            if (data.getDestinationIp(i) != data.getSourceIp(i)){
                dict.at(data.getDestinationIp(i)) += 1;
            }
        }
        for (auto i:dict){
            std::cout << i.first << "\t\t" << i.second << std::endl;
        }
    }

    

};