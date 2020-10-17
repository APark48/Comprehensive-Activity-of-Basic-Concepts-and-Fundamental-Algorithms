//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
#include "Reader.h"
#include "Sorter.h"
#include "Searcher.h"
#include "Data.h"
//#include "ComputerConnections.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool Data::compareSourceHostname(Data &a, Data &b){
    stringstream ssa(a.getSourceHostname());
    string h1, h2;
    getline(ssa, h1, '.');
    stringstream ssb(b.getSourceHostname());
    getline(ssb, h2, '.');
    
    return h1 == h2;
}

bool Data::compareEqual(int &a, int &b){
    return a == b;
}

int main(){
    Reader data;
    if (data.loadDataFromcsv("equipo11.csv") > 0)
        cout << "DONE" << endl;
    else
    {
        cout << "ERROR loading input file... Exiting program...";
        return 0;
    }

    cout << "Number of registers: " << data.length() << endl;
    
    string date; int count;
    data.day2(1, date, count);
    cout << "Date of second day is: " << date << " with " << count << " logs." << endl;

    vector<string> names;
    names.push_back("jeffrey");
    names.push_back("scott");
    names.push_back("katherine");
    cout << "Found register from ";
    for (size_t i = 0; i < names.size(); i++){
        cout << names[i] << ", ";
    }
    cout << endl;
    cout << "\t" << (data.findHostname(names) >= 0 ? "YES" : "NO") << endl;
    
    cout << "Destination ports under 1000: \n\t";
    vector<int> ports = data.portCount(1000);
    for (size_t i = 0; i < ports.size(); i++){
        cout << ports[i] << ", ";
    }
    cout << endl;

    return 0;
}

