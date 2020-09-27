//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include <string>

class Data{
private:
    std::string date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
public:
    //Constructors & Destructor
    //Default constructor in case no arguments are provided
    Data(){
        date="None";
        time="None";
        sourceIp="None";
        sourcePort="None";
        sourceHostname="None";
        destinationIp="None";
        destinationPort="None";
        destinationHostname="None";
    }
    //Constructor if arguments are provided
    Data(std::string date, std::string time, std::string sourceIp, std::string sourcePort, std::string sourceHostname, std::string destinationIp, std::string destinationPort, std::string destinationHostname){
        this->date=date;
        this->time=time;
        this->sourceIp=sourceIp;
        this->sourcePort=sourcePort;
        this->sourceHostname=sourceHostname;
        this->destinationIp=destinationIp;
        this->destinationPort=destinationPort;
        this->destinationHostname=destinationHostname;
    }
    ~Data(){};
};