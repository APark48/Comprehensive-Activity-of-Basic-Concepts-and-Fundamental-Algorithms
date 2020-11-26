#pragma once
#include "Data.h"
#include "BinarySearchTree.h"
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
    /*
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
    }*/
    
    // Function to push a value of a Data type object to reader 
    void pushRecord(Data data){
        reader.push_back(data);
    } 
    
    // Function to return total registers
    int totalRegisters(){
        return reader.size();
    } 

     std::string getInternalIP(int position){
        std::string internalIp;
        std::string dInternalIp = reader.at(position).getDestinationIp().erase(10,reader.at(position).getDestinationIp().length()-10);
        std::string sInternalIp = reader.at(position).getSourceIp().erase(10,reader.at(position).getSourceIp().length()-10);
        if (dInternalIp == "10.214.58"){
            internalIp = reader.at(position).getDestinationIp();
        }
        if (sInternalIp == "10.214.58"){
            internalIp = reader.at(position).getSourceIp();
        }
        return internalIp;
    }

    void getDay(int day){
        
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

    int getSize(){
        return reader.size();
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
    std::string getDestinationHostname(int position){
        return reader.at(position).getDestinationHostname();
    }
    std::string getDate(int position){
        return reader.at(position).getDate();
    }

    void printHostname(){
        std::map<std::string, std::string> hostname;
        int size = reader.size();
        for (int i=0; i<size; i++){
            hostname.insert(std::make_pair(reader.at(i).getDestinationHostname(), reader.at(i).getDestinationIp()));
        }
        for (auto i:hostname){
            std::cout << i.first <<"\t" << i.second << std::endl;
        }
    }

    void printDate(Reader read){
        std::set<std::string> date;
        int size = reader.size();
        for (int i=0; i<size; i++){
            date.insert(reader.at(i).getDate());
        }
        for (auto i:date){
            std::cout << std::endl << i << std::endl;
            read.top(5,i);
        }
    }

    // Function to print total incoming connections from reto.com domain
    void printRetoDomains(){
        std::map<std::string, int> dict;
        int total = 1;
        int size = reader.size();
        for (int i=0; i<size; i++){
            if (reader.at(i).getDestinationHostname().erase(0, reader.at(i).getDestinationHostname().length()-8) == "reto.com"){
                if (reader.at(i).getDestinationIp() == reader.at(i).getSourceIp()){
                    dict[reader.at(i).getDestinationIp()]++;
                }
            }
        }
        std::cout << "printRetoDomains" << std::endl;
        for (auto i:dict){
            std::cout << i.first << "\t" << i.second << std::endl;
        }
    }/*
    void printDomains(){
        std::map<std::string, std::string> dict;
        int total = 1;
        int size = reader.size();
        for (int i=0; i<size; i++){
            if (reader.at(i).getDestinationHostname().erase(0, reader.at(i).getDestinationHostname().length()-8) != "reto.com"){
                if (reader.at(i).getDestinationIp() == reader.at(i).getSourceIp()){
                    dict.insert(std::make_pair(reader.at(i).getDestinationIp(),reader.at(i).getSourceIp()));
                }
            }
        }
        std::cout << "printDomains" << std::endl;
        for (auto i:dict){
            std::cout << i.first << "\t" << i.second << std::endl;
        }
    }*/

    
    std::map<std::string, int> dayConnection(std::string date){
        std::map<std::string, int> dict;
        int size = reader.size();
        for (int i=0; i<size;i++){
            if (reader.at(i).getDate() == date && reader.at(i).getDestinationHostname() != "-"){
                if(reader.at(i).getDestinationHostname().erase(0, reader.at(i).getDestinationHostname().length()-8)!="reto.com"){
                    dict[reader.at(i).getDestinationHostname()]++;
                }   
            }
        }
        return dict;/*
        std::map<std::string, int>::iterator iter;
        for (iter = dict.begin(); iter != dict.end(); iter++){
            std::cout << iter->first<< ":" << "\t" << iter->second << std::endl;
        }*/
    }
    std::multimap<int, std::string> invert(std::map<std::string, int> & mymap)
    {
        std::multimap<int, std::string> multiMap;

        std::map<std::string, int> :: iterator it;
        for (it=mymap.begin(); it!=mymap.end(); it++) 
        {
            multiMap.insert(make_pair(it->second, it->first));
        }

        return multiMap;
    }
    /*void topTest(int n, std::string date){
        std::map<std::string, int>dict = dayConnection(date);
        std::multimap<int, std::string> newmap = invert(dict);
        std::multimap<int, std::string> :: iterator iter;
        for (iter=newmap.end(); iter!=newmap.begin(); iter--) 
        {
            // printing the second value first because the 
            // order of (key,value) is reversed in the multimap
            std::cout << iter->second << ": " << iter->first << std::endl;
        }
        //best.print_preorder();
    }*/
    void top(int n, std::string date){
        std::string str;
        int val = 0;
        BinarySearchTree BST(str, val);
        std::map<std::string, int>dict = dayConnection(date);
        std::multimap<int, std::string> newmap = invert(dict);
        int i = -1;
        for (auto iter=newmap.rbegin(); iter!=newmap.rend(); iter++) {
            if (i<=n){
                i++;
                BST.insert(BST.getRoot(), iter->second, iter->first);
            }
        }
        std::cout << std::endl;
        BST.invert(BST.getRoot());
        BST.inorder(BST.getRoot()); 
    }
    
};