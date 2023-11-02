//
//  Funcs.cpp
//  AaDS Lab 4 "Pyramidal Sort"
//
//  Created by Antony Miroshnichenko on 28.10.2023.
//



#include <iostream>
#include <vector>
#include <assert.h>

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



// Считать вектор из файла

void scanVectorFromFile(std::vector<int>& array, const std::string& name) {
    
    char* fileName = new char [name.length() + 1];
    
    FILE *f;
    
    
    std::strcpy(fileName, name.c_str());
    
    f = fopen (fileName, "r");
    
    assert(f != NULL);
    
    {
        
        int x;
        
        while (fscanf (f, "%d", &x) != EOF) {
            
            array.push_back(x);
            
        }
        
    }
    
    fclose (f);
    
    delete [] fileName;
    
}



// Сгенерировать имя файла

std::string createNameOfFile(int size, int range) {
    
    std::string fileName = "array_";
    
    
    fileName += std::to_string(size);
    
    fileName += "_";
    
    fileName += std::to_string(range);
    
    fileName += ".txt";
    

    return fileName;
    
}



// Генерация случайного массива

void randomVector (std::vector<int>& array, int size, int a, int b) {
    
    srand(time(0));
    
    for (int i = 0; i < size; i++) {
        
        array.push_back( rand() % (b - a + 1) + a );
        
    }
    
}



// Проверка на упорядоченность

void orderCheck (std::vector<int> array) {
    
    for (auto i = array.begin(); i < array.end() - 1; i++) {
        
        if (*i > *(i + 1)) {
            
            std::cout << "Массив не упорядочен" << std::endl;
            
        }
        
    }
    
    
    std::cout << "Массив упорядочен" << std::endl;
    
}



// Просеивание i-го элемента массива array (с обменом на каждом шаге)

void sift1 (std::vector<int>& array, int size, int i) {
    
    int j = 2*i + 1;
    
    
    while (i < size) {
        
        if (j < size) {
            
            if (j + 1 < size && array[j + 1] > array[j]) {
                    
                j++;
                    
            }
            
            
            if (array[j] > array[i]) {
                
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
        
        sift1(array, size, i);
        
    }
    
    
    for (int i = size - 1; i > 0; i--) {
        
        std::swap(array[0], array[i]);
        
        sift1(array, i, 0);
        
    }
    
}
