//
//  main.cpp
//  AaDS Lab 3 "Shell sort"
//
//  Created by Antony Miroshnichenko on 15.10.2023.
//



#include <iostream>

#include "Funcs.hpp"



int main() {
    
    int n = 10, arr[n];
    
    randomArray(arr, n, 1, 100);
    
    std::cout << "Массив до сортировки: ";
    
    printArray(arr, n);
    
    shellSort(arr, n);
    
    std::cout << std::endl << "Массив после сортировки: ";
    
    printArray(arr, n);
    
    std::cout << std::endl;
}
