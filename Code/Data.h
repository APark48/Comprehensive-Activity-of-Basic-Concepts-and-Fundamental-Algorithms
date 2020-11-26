#pragma once
#include <string>
#include <iostream>

class Data{
private:
    std::string date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
public:
    Data(){
        date="";
        time="";
        sourceIp="";
        sourcePort="";
        sourceHostname="";
        destinationIp="";
        destinationPort="";
        destinationHostname="";
    };
    Data(std::string date, std::string time, std::string sourceIp, std::string sourcePort, std::string sourceHostname, std::string destinationIp, std::string destinationPort, std::string destinationHostname){
        this->date=date;
        this->time=time;
        this->sourceIp=sourceIp;
        this->sourcePort=sourcePort;
        this->sourceHostname=sourceHostname;
        this->destinationIp=destinationIp;
        this->destinationPort=destinationPort;
        this->destinationHostname=destinationHostname;  
    };
    ~Data(){};

    //Getters
    std::string getDate(){
        return date;
    }
    std::string getTime(){
        return time;
    }
    std::string getSourceIp(){
        return sourceIp;
    }
    std::string getSourcePort(){
        return sourcePort;
    }
    std::string getSourceHostname(){
        return sourceHostname;
    }
    std::string getDestinationIp(){
        return destinationIp;
    }
    std::string getDestinationPort(){
        return destinationPort;
    }
    std::string getDestinationHostname(){
        return destinationHostname;
    }
    //setters
    void setSourceIp(std::string sourceIp){
        sourceIp = this->sourceIp;
    }
    void setDestinationIp(std::string destinationIp){
        destinationIp = this->destinationIp;
    }
};