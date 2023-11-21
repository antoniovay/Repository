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
    
    double time;
    
    std::vector<int> array;
    
    randomVector(array, 20, 0, 100);
    
    int k = (int) array.size();
    
    

    

    printVector(array);



    clock_t start = clock();

    bitSort(array, 0, k - 1, k);

    clock_t end = clock();

    time = (double) (end - start) / CLOCKS_PER_SEC;



    printVector(array);

    orderCheck(array);


    std::cout << "Время работы алгоритма - " << time << "s" << std::endl;
    
    
    
}
