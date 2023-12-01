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
    
    double time, avgTime;
    
  
    for (int size = 10000; size <= 1000000; size *= 10) {
        
        for (int range = 10; range <= 100000; range *= 100) {
            
            
            
            std::cout << std::endl << std::endl << std::endl << "-----//Выполняется побитовая сортировка массивов размера " << size << " c элементами в диапазоне [" << -range << "; " << range << "]//-----" << std::endl << std::endl;
            
            
            std::vector<int> array, copy;
            
            avgTime = 0;
            
            scanVectorFromFile(array, createNameOfFile(size, range));
            
            
            for (int i = 1; i <= 3; i++) {
                
                copy = array;
                
                
                clock_t start = clock();
                
                bitSort(copy, range);
                
                clock_t end = clock();
                
                
                time = (double) (end - start) / CLOCKS_PER_SEC;
                
                //std::cout << std::endl << "Время работы - " << time << "s" << std::endl;
                
                
                avgTime += time;
                
                
                orderCheck(copy);
                
            }
            
            std::cout /*<< std::endl << std::endl*/ << "Среднее время - " << avgTime/3 << "s" << std::endl << std::endl;
            
        }
        
    }
    
    //
    
    
    
    std::cout << std::endl << std::endl;
    
    
    
    
}
