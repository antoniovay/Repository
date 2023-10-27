//
//  main.cpp
//  AaDS Lab 3 "Shell sort"
//
//  Created by Antony Miroshnichenko on 15.10.2023.
//



#include <iostream>
#include <time.h>
#include <algorithm>

#include "Funcs.hpp"



int main() {
    
    
    std::cout << "Тест:" << std::endl;
    
    std::vector<int> test;
    
    randomVector(test, 10, -10, 10);
    
    printVector(test);
    
    shellSort(test);
    
    printVector(test);
    
    std::cout << std::endl;
    
    
    
    
    typedef void (*algoritm)(std::vector<int>& array);
    
    algoritm typeOfAlg[3];
    
    typeOfAlg[0] = shellSort;
    typeOfAlg[1] = shellSortKnut;
    typeOfAlg[2] = shellSort2MMinus1;
    
    
    
    
    double time;
    
    for (int type = 1; type <=3; type++)
    
        for (int size = 10000; size < 1000001; size *= 10)
        
            for (int range = 10; range < 100001; range *= 100) {
                
                std::cout << std::endl << "-----//Выполняется сортировка методом " << typeOfAlgorythm(type) << " массивов размера " << size << " c элементами в диапазоне [" << -range << "; " << range << "]//-----" << std::endl << std::endl << std::endl << std::endl;
                
                double avgTime = 0;
                
                for (int i = 1; i < 4; i++) {
                    
                    std::vector<int> array;
                                        
                    randomVector(array, size, -range, range);
                    
                    //std::cout << "Массив до сортировки: ";
                    
                    //printVector(array);
                    
                    
                    
                    clock_t start = clock();
                    
                    typeOfAlg[type](array);
                    
                    clock_t end = clock();
                    
                    time = (double) (end - start) / CLOCKS_PER_SEC;
                    
                    avgTime += time;
                    
                    
                    
                    //std::cout << std::endl << "Массив после сортировки: ";
                    
                    //printVector(array);
                    
                    //std::cout << std::endl;
                    
                    
                    
                    if (orderCheck(array) == true) {
                        
                        std::cout << "Массив упорядочен" << std::endl;
                        
                    }
                    
                    else {
                        
                        std::cout << "Массив не упорядочен" << std::endl;
                        
                    }
                    
                    std::cout << std::endl;
                    
                    
                    
                    std::cout << "Время работы алгоритма - " << time << "s" << std::endl << std::endl << std::endl << std::endl;
                    
                }
                
                std::cout << std::endl << std::endl << "Среднее время работы - " << avgTime/3 << "s" << std::endl << std::endl << std::endl;
                
            }
    
}
