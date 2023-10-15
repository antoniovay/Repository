//
//  Funcs.cpp
//  AaDS Lab 3 "Shell sort"
//
//  Created by Antony Miroshnichenko on 15.10.2023.
//



#include <iostream>
#include <time.h>

#include "Funcs.hpp"



void printArray (int arr[], int n) {
    
    std::cout << "[";
    
    for (int i = 0; i < n; i++) {
        
        std::cout << arr[i];
        
        if (i < n - 1) {
            
            std::cout << ", ";
            
        }
        
    }
    
    std::cout << "]" << std::endl;
    
}



void randomArray (int *mas, int n, int a, int b) {
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        
        mas[i] = rand() % (b - a + 1) + a;
        
    }
    
}



void shellSort (int arr[], int size) {
    
    
    for (int gap = size / 2; gap > 0; gap /= 2) {
        
        
        for (int i = gap; i < size; i += 1) {
            
            int temp = arr[i];
            
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                
                arr[j] = arr[j - gap];
                
            }
            
            
            arr[j] = temp;
            

        }
        
    }
}
