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
    
    int* arr;
    
    for (int type = 1; type <=3; type++)
    
        for (int size = 10000; size < 1000001; size *= 10)
        
            for (int range = 10; range < 100001; range *= 100) {
                
                std::cout << std::endl << "-----//Выполняется сортировка методом " << typeOfAlgorythm(type) << " массивов размера " << size << " c элементами в диапазоне [" << -range << "; " << range << "]//-----" << std::endl << std::endl << std::endl << std::endl;
                
                double avgTime = 0;
                
                for (int i = 1; i < 4; i++) {
                    
                    arr = new int [size];
                    
                    randomArray(arr, size, -range, range);
                    
                    //std::cout << "Массив до сортировки: ";
                    
                    //printArray(arr, size);
                    
                    
                    
                    clock_t start = clock();
                    
                    switch (type) {
                            
                        case 1: shellSort(arr, size); break;
                            
                        case 2: shellSortKnut(arr, size); break;
                            
                        case 3: shellSort2MMinus1(arr, size); break;
                            
                        default: break;
                            
                    }
                    
                    clock_t end = clock();
                    
                    time = (double) (end - start) / CLOCKS_PER_SEC;
                    
                    avgTime += time;
                    
                    
                    
                    //std::cout << std::endl << "Массив после сортировки: ";
                    
                    //printArray(arr, size);
                    
                    //std::cout << std::endl;
                    
                    
                    
                    if (orderCheck(arr, size) == true) {
                        
                        std::cout << "Массив упорядочен" << std::endl;
                        
                    }
                    
                    else {
                        
                        std::cout << "Массив не упорядочен" << std::endl;
                        
                    }
                    
                    std::cout << std::endl;
                    
                    
                    
                    std::cout << "Время работы алгоритма - " << time << "s" << std::endl << std::endl << std::endl << std::endl;
                    
                    delete [] arr;
                    
                }
                
                std::cout << std::endl << std::endl << "Среднее время работы - " << avgTime/3 << "s" << std::endl << std::endl << std::endl;
                
            }
    
}
