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

    void setDate (std::string val) {
        date = val;};     
    void setTime (std::string val) {
        time = val;};     
    void setSourceIP (std::string val) {
        sourceIp = val;};     
    void setSourcePort (std::string val) {
        sourcePort = val;};     
    void setSourceHostname (std::string val) {
        sourceHostname = val;};     
    void setDestinationIP (std::string val) {
        destinationIp = val;};     
    void setDestinationPort (std::string val) {
        destinationPort = val;};     
    void setDestinationHostname (std::string val) {
        destinationHostname = val;};

    static bool compareSourceHostname(Data &a, Data &b);

    static bool compareEqual(int &a, int &b);

};