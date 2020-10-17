//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#ifndef Data_h
#define Data_h
#include <string>
#include <iostream>

using std::cout;

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
    }
    ~Data(){};

    //Functions to get data
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

    void setDate (std::string val) {
        date = val;};     
    void setTime (std::string val) {
        time = val;};     
    void setSourceIp (std::string val) {
        sourceIp = val;};     
    void setSourcePort (std::string val) {
        sourcePort = val;};     
    void setSourceHostname (std::string val) {
        sourceHostname = val;};     
    void setDestinationIp (std::string val) {
        destinationIp = val;};     
    void setDestinationPort (std::string val) {
        destinationPort = val;};     
    void setDestinationHostname (std::string val) {
        destinationHostname = val;};

    static bool compareSourceHostname(Data &a, Data &b);

    static bool compareEqual(int &a, int &b);

    void print(){
    cout << date << ", ";
    cout << time << ", ";
    cout << sourceIp << ", ";
    cout << sourcePort << ", ";
    cout << sourceHostname << ", ";
    cout << destinationIp << ", ";
    cout << destinationPort << ", ";
    cout << destinationHostname << std::endl;
    }

};

#endif