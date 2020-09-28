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

std::vector<class Data<std::string>> reader(){
    std::ifstream data("equipo11.csv");
    std::string date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname;
    std::vector<class Data<std::string>> read;
    while (data.peek()!=EOF){
        std::getline(data, date, ',');
        std::getline(data, time, ',');
        std::getline(data, sourceIp, ',');
        std::getline(data, sourcePort, ',');
        std::getline(data, sourceHostname, ',');
        std::getline(data, destinationIp, ',');
        std::getline(data, destinationPort, ',');
        std::getline(data, destinationHostname, '\n');
        Data<std::string> r(date, time, sourceIp, sourcePort, sourceHostname, destinationIp, destinationPort, destinationHostname);
        read.push_back(r);
    }
    
    int count=0;
    for(int i=0; i<read.size(); i++){
        count+=1;
    }

    std::cout << "El archivo tiene " << count << " registros." << std::endl;
    data.close();
    return read;
}

int segundoDia(std::vector<class Data<std::string>>&read){
    std::string dia1, dia2 = "";
    int contador_iterativo = 0;
    int contar_dia_2 = 0;
    dia1=read.at(contador_iterativo).getDate();
    while (read.at(contador_iterativo).getDate()==dia1){
        contador_iterativo++;
    }

    dia2=read.at(contador_iterativo).getDate();
    while(read.at(contador_iterativo).getDate()==dia2){
        contar_dia_2++;
        contador_iterativo++;
    }
    std::cout<<"El segundo dia es " << dia2 << std::endl;
    return contar_dia_2;
}

void countNames(std::vector<class Data<std::string>> &read){
    std::cout<<"Cuantos nombres quieres buscar?" << std::endl;
    int nameCount;
    std::cin >> nameCount;
    std::vector<std::string> names;
    std::string name;
    std::vector<int> posiciones;
    for(int i=0; i<nameCount; i++){
        std::cout << "Escribe el nombre en minusculas" << std::endl;
        std::cin >> name;
        names.push_back(name);
        names[i].append(".reto.com");
        posiciones.at(i) = binarySearch<std::string>(0, read.size()-1, names.at(i), read);
        if(posiciones.at(i)==-1){
            std::cout << name << " no es un empleado de la empresa." << std::endl;
        } else {
            std::cout << name << " si trabaja en la empresa." << std::endl;
        }
    };

}

void direccionIP(std::vector<class Data<std::string>>&read){
    std::string ipCompania = read.at(read.size()-1).getSourceIp();
    ipCompania.erase(10,ipCompania.length()-10);
    ipCompania.append(".0");
    std::cout << "La direccion IP de la compania es " << ipCompania << std::endl;
}

// void mails(std::vector<class Data<std::string>> &read){
//     int mailCount;
//     std::cout<< "Cuantos correos quieres buscar?" << std::endl;
//     std::cin >> mailCount;
//     std::string mails[mailCount];
//     for(int i=0; i<mailCount; i++){
//         std::cout << "Escribe el nombre en minusculas" << std::endl;
//         std::cin >> mails.at(i);
//         mails.at(i).append(".com");
//     };

//     std::vector<std::string> hostNames;
//     for(int i=0; i<read.size(); i++){
//         std::string destinationHost = read.at(i).getDestinationHostname();
//         hostNames.push_back(destinationHost);
//     }

//     int posiciones[mailCount];
//     for(int j=0; j<mailCount; j++){
//         posiciones.at(j)=binarySearch<std::string>(0, hostNames.size()-1, mails.at(j), hostNames);
//         if(posiciones[j]==-1){
//             std::cout << mails.at(j) << " no es un correo que se usa en la empresa." << std::endl;
//         } else {
//             std::cout << mails.at(j) << " si es un correo que se usa en la empresa." << std::endl;
//         }
//     };
// }

// void portCount(std::vector<class Data<std::string>> &read){
//     std::vector<std::string> ports;
//     int check;
//     for(int i=0; i<read.size(); i++){
//         check=binarySearch(0, ports.size()-1, read.at(i).getDestinationPort(), ports);
//         if(check==-1){
//             ports.push_back(read.at(i).getDestinationPort());
//         }
//     }
//     for(int j=0; j<ports.size(); j++){
//         std::cout << ports.at(j) << std::endl;
//     }
// }