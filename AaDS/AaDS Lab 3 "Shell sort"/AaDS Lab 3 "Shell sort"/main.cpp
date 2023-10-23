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
    
    int size;
    
    std::cout << "Введите желаемый размер массива >> ";
    
    std::cin >> size;
    
    std::cout << std::endl;
    
    int arr[size];
    
    randomArray(arr, size, 1, 1000);
    
    
    
    std::cout << "Массив до сортировки: ";
    
    printArray(arr, size);
    
    
    
    clock_t start = clock();
    
    shellSort(arr, size);
            
    clock_t end = clock();
        
    time = (double) (end - start) / CLOCKS_PER_SEC;
    
    
    
    std::cout << std::endl << "Массив после сортировки: ";
    
    printArray(arr, size);
    
    std::cout << std::endl;
    
    
    
    if (orderCheck(arr, size) == true) {
        
        std::cout << "Массив упорядочен" << std::endl;
        
    }
    
    else {
        
        std::cout << "Массив не упорядочен" << std::endl;
        
    }
    
    std::cout << std::endl;
    
    
    
    std::cout << "Время работы алгоритма - " << time << "s" << std::endl;
}
