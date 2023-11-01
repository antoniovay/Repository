//
//  main.cpp
//  AaDS Lab 4 "Pyramidal Sort"
//
//  Created by Antony Miroshnichenko on 28.10.2023.
//



#include <iostream>
#include <vector>

#include "Funcs.hpp"



int main() {
    
    std::vector<int> array;
    
    randomVector(array, 20, -100, 100);
    
    
    std::cout << "Массив до сортировки: ";
    
    printVector(array);
    
    
    heapSort(array);
    
    
    std::cout << std::endl << "Массив после сортировки: ";
    
    printVector(array);
    
    std::cout << std::endl;
    
    
    bool order = orderCheck(array);
    
    if (order) {
        
        std::cout << "Массив упорядочен";
        
    }
    
    else {
        
        std::cout << "Массив не упорядочен";
        
    }
    
    
    std::cout << std::endl << std::endl;
    
}
