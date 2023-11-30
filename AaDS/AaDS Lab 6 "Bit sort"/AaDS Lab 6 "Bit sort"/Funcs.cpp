//
//  Funcs.cpp
//  AaDS Lab 6 "Bit sort"
//
//  Created by Antony Miroshnichenko on 16.11.2023.
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
        
        //assert(*i <= *(i + 1));
        
        if (*i > *(i + 1)) {
            
            //std::cout << "Массив не упорядочен" << std::endl;
            
            assert(*i <= *(i + 1));
            
        }
        
    }
    
    
    //std::cout << "Массив упорядочен" << std::endl;
    
}










void bitSort(std::vector<int>& array, int l, int r, int mask) {
    
    if (l < r || mask >= 0) {
        
        int i = l, j = r;
        
        while (i <= j) {
            
            while (i <= j) {
                
                while (i <= j && (mask & array[i]) == 0)
                    
                    i++;
                
                while (i <= j && (mask & array[i]) > 1)
                    
                    j--;
                
                if (i < j) {
                    
                    std::swap(array[i], array[j]);
                    
                    i++;
                    j--;
                    
                }
                
            }
            
            bitSort(array, l, j, mask >> 1);
            bitSort(array, i, r, mask >> 1);
            
        }
        
    }
    
    
    
    
    
}
