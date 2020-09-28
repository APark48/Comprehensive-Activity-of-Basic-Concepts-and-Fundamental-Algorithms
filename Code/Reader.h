//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#pragma once
#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::getline;

std::vector<class Data<std::string>> reader(){
    std::ifstream data("equipo10.csv");
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

int segundoDia(std::vector<class Data<std::string>> &read){
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
    std::string names[nameCount], name[nameCount];
    for(int i=0; i<nameCount; i++){
        std::cout << "Escribe el nombre en minusculas" << std::endl;
        std::cin >> name[i];
        names[i]=name[i];
        names[i].append(".reto.com");
    };
    int posiciones[nameCount];
    for(int j=0; j<nameCount; j++){
        posiciones[j]=busquedaBinariasourceHostname<std::string>(0, read.size()-1, names[j], read);
        if(posiciones[j]==-1){
            std::cout << name[j] << " no es un empleado de la empresa." << std::endl;
        } else {
            std::cout << name[j] << " si trabaja en la empresa." << std::endl;
        }
    };

}

void direccionIP(std::vector<class Data<std::string>> &read){
    std::string ipCompania = read.at(read.size()-1).getSourceIp();
    ipCompania.erase(10,ipCompania.length()-10);
    ipCompania.append(".0");
    std::cout << "La direccion IP de la compania es " << ipCompania << std::endl;
}