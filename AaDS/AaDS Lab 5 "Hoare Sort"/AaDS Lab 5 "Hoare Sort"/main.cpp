//
//  main.cpp
//  AaDS Lab 5 "Hoare Sort"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//



#include <iostream>
#include <vector>
#include <time.h>

#include "Funcs.hpp"



int main() {
    
    double time;
    
    
    std::vector<int> array;
    
    int size = 20;
    
    randomVector(array, 20, -100, 100);
    
    printVector(array);
    
    
    
    clock_t start = clock();
    
    hoareSort(array, 0, size - 1);
    
    clock_t end = clock();
    
    time = (double) (end - start) / CLOCKS_PER_SEC;
    
    
    
    printVector(array);
    
    orderCheck(array);
    
    
    std::cout << "Время работы алгоритма - " << time << "s" << std::endl;
    
    
    
    
    
}
