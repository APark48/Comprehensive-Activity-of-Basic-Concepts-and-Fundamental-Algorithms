//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once

template <typename T>
class Data{
private:
    T date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
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
    Data(T date, T time, T sourceIp, T sourcePort, T sourceHostname, T destinationIp, T destinationPort, T destinationHostname){
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

    //Functions to get data
    T getDate(){
        return date;
    }
    T getTime(){
        return time;
    }
    T getSourceIp(){
        return sourceIp;
    }
    T getSourcePort(){
        return sourcePort;
    }
    T getSourceHostname(){
        return sourceHostname;
    }
    T getDestinationIp(){
        return destinationIp;
    } 
    T getDestinationPort(){
        return destinationPort;
    } 
    T getDestinationHostname(){
        return destinationHostname;
    }
};