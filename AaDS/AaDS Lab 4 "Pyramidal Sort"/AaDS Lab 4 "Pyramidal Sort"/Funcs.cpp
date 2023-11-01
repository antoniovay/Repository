//
//  Funcs.cpp
//  AaDS Lab 4 "Pyramidal Sort"
//
//  Created by Antony Miroshnichenko on 28.10.2023.
//



#include <iostream>
#include <vector>

#include "Funcs.hpp"



// Вывод вектора

void printVector (const std::vector<int> vectorOfOccurrences) { // Вывод вектора
    
    std::cout << "[";
    
    for (auto it = vectorOfOccurrences.begin(); it != vectorOfOccurrences.end(); it++) {
        
        if ( it != vectorOfOccurrences.begin() ) {
            
            std::cout << ", ";
            
        }
        
        std::cout << *it;
        
    }
    
    std::cout << "];" << std::endl;
    
}



// Генерация случайного массива

void randomVector (std::vector<int>& array, int size, int a, int b) {
    
    srand(time(0));
    
    for (int i = 0; i < size; i++) {
        
        array.push_back( rand() % (b - a + 1) + a );
        
    }
    
}



// Проверка на упорядоченность

bool orderCheck (std::vector<int> array) {
    
    for (auto i = array.begin(); i < array.end() - 1; i++) {
        
        if (*i > *(i + 1)) {
            
            return false;
            
        }
        
    }
    
    
    return true;
    
}



// Просеивание i-го элемента массива array (с обменом на каждом шаге)

void sift1 (std::vector<int>& array, int i) {
    
    int j = 2*i + 1;
    
    int size = array.size();
    
    
    while (i < size) {
        
        if (j < size) {
            
            if (j + 1 < size && array[j + 1] > array[j]) {
                    
                j++;
                    
            }
            
            
            if (array[j] < array[i]) {
                
                std::swap(array[i], array[j]);
                
                i = j; j = 2*i + 1;
                
            }
            
            else {
                
                i += size;
                
            }
            
        }
        
        else {
            
            i += size;
            
        }
        
    }
}



//

void heapSort (std::vector<int>& array) {
    
    int size = array.size();
    
    
    for (int i = size/2 - 1; i >= 0; i--) {
        
        sift1(array, i);
        
    }
    
    
    for (int i = size - 1; i > 0; i--) {
        
        std::swap(array[0], array[i]);
        
        sift1(array, i);
        
    }
    
}
