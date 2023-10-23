//
//  main.cpp
//  AaDS Lab 3 "Shell sort"
//
//  Created by Antony Miroshnichenko on 15.10.2023.
//



#include <iostream>
#include <time.h>

#include "Funcs.hpp"



int main() {
    
    double time;
    
    int n = 1000000, arr[n];
    
    randomArray(arr, n, 1, 1000);
    
    
    
    std::cout << "Массив до сортировки: ";
    
    printArray(arr, n);
    
    
    
    clock_t start = clock();
    
    shellSort(arr, n);
            
    clock_t end = clock();
        
    time = (double) (end - start) / CLOCKS_PER_SEC;
    
    
    
    std::cout << std::endl << "Массив после сортировки: ";
    
    printArray(arr, n);
    
    std::cout << std::endl;
    
    
    
    if (orderCheck(arr, n) == true) {
        
        std::cout << "Массив упорядочен" << std::endl;
        
    }
    
    else {
        
        std::cout << "Массив не упорядочен" << std::endl;
        
    }
    
    std::cout << std::endl;
    
    
    
    std::cout << "Время работы алгоритма - " << time << "s" << std::endl;
}
