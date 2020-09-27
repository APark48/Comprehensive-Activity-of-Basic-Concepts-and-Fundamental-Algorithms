//Developed by Alfredo Jeong Hyun Park (A01658259)
//Developed by Valter Alejandro Kuhne Hernández (A01379392)
//Copyright © 2020. All rights reserved.
//#include "Reader.h"
#include "Sorter.h"
#include <iostream>

int main(){
    std::vector <int> v = {5,4,6,78,92,1,40};
    Quicksort <int> q;
    q.quicksort(v, 1, 8);
    for (auto i:v){
        std::cout << i << " ";
    }

    return 0;
}