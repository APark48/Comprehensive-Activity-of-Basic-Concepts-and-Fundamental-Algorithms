#include "Data.h"
#include "Reader.h"
#include "ComputerConnections.h"
#include <fstream>
#include <string>
#include <iostream>

int main(){
    Reader reader;
    std::ifstream data;
    data.open("nuevo11.csv");
    while (data.good()){
        std::string date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
        std::getline(data, date, ',');
        std::getline(data, time, ',');
        std::getline(data, sourceIp, ',');
        std::getline(data, sourcePort, ',');
        std::getline(data, sourceHostname, ',');
        std::getline(data, destinationIp, ',');
        std::getline(data, destinationPort, ',');
        std::getline(data, destinationHostname, '\n');
        Data line(date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname);
        reader.pushRecord(line);
    }

    //reader.print();
    std::cout << "Total registers are: " << reader.totalRegisters() << std::endl;
    std::cout << "Total second day records are: " << reader.secondDayRecords() << std::endl;
    //std::cout << reader.belonging() << std::endl;
    //std::cout << reader.serverReto() << std::endl;

    ComputerConnections computer;
    computer.setComputer(reader);
    computer.print();
    std::cout << "Last connection is: "<< computer.lastConnection(reader);

    return 0;
}
