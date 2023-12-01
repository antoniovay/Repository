//
//  main.cpp
//  AaDS Lab 6 "Bit sort"
//
//  Created by Antony Miroshnichenko on 16.11.2023.
//



#include <iostream>
#include <vector>
#include <assert.h>

#include "Funcs.hpp"



int main() {
    
    int size = 20000;
    
    int range = 100;
    
    double time;
    
    std::vector<int> array;
    
    randomVector(array, size, -range, range);

    

    printVector(array);



    clock_t start = clock();

    bitSort(array, range);

    clock_t end = clock();

    time = (double) (end - start) / CLOCKS_PER_SEC;



    printVector(array);

    orderCheck(array);


    std::cout << "Время работы алгоритма - " << time << "s" << std::endl;
    
    
    
}
