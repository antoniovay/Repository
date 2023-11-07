//
//  main.cpp
//  AaDS Lab 5 "Hoare Sort"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//



#include <iostream>
#include <vector>

#include "Funcs.hpp"



int main() {
    
    std::vector<int> array;
    
    int size = 20;
    
    randomVector(array, 20, -100, 100);
    
    printVector(array);
    
    hoareSort(array, 0, size - 1);
    
    printVector(array);
    
    orderCheck(array);
    
    
    
    
    
    
    
    
}
