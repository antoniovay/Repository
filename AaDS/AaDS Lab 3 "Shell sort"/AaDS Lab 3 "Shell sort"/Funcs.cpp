//
//  Funcs.cpp
//  AaDS Lab 3 "Shell sort"
//
//  Created by Antony Miroshnichenko on 15.10.2023.
//



#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <assert.h>

#include "Funcs.hpp"



// Создать файл

std::string createNameOfFile(int size, int range) {
    
    std::string fileName = "array_";
    
    
    fileName += std::to_string(size);
    
    fileName += "_";
    
    fileName += std::to_string(range);
    
    fileName += ".txt";
    

    return fileName;
    
}



// Записать вектор в файл

void printVectorToFile (const std::vector<int> array, const std::string name) {
    
    char* fileName = new char [name.length() + 1];
    
    std::strcpy(fileName, name.c_str());
    
    FILE *f = fopen (fileName, "w");
    
    assert(f != NULL);
    
    for (auto it = array.begin(); it != array.end(); ++it) {
        
        fprintf(f, "%d ", *it);
        
    }
    
    delete [] fileName;
    
    fclose (f);
    
}



// Вывод вектора

void printVector (const std::vector<int> array) { // Вывод вектора
    
    std::cout << "[";
    
    for (auto it = array.begin(); it != array.end(); it++) {
        
        if ( it != array.begin() ) {
            
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



// Сортировка Шелла с выбором длин промежутков по Шеллу

void shellSort (std::vector<int>& array) {
    
    
    for (int gap = array.size() / 2; gap > 0; gap /= 2) {
        
        
        sort(array, gap);
        
    }
    
    //std::cout << std::endl << "Выполнена сортировка shellSort" << std::endl;
}



// Сортировка Шелла с выбором длин промежутков по Кнуту

void shellSortKnut(std::vector<int>& array) {
    
    int gap = 1;
    
    while (gap < array.size() / 3) {
        
        
        gap = gap * 3 + 1;
        
    }
    
    for (; gap > 0; gap /= 3) {
        
        sort(array, gap);
        
    }
    
    //std::cout << std::endl << "Выполнена сортировка shellSortKnut" << std::endl;
    
}



// Сортировка Шелла с выбором длин промежутков по 2 ^ m - 1

void shellSort2MMinus1(std::vector<int>& array) {
    
    int gap = 1;
    
    while ( gap < array.size() ) {
        
        gap *= 2;
        
    }
    
    gap /= 2;
    
    gap--;
    
    for (; gap > 0; gap /= 2) {
        
        sort(array, gap);
        
    }
    
    //std::cout << std::endl << "Выполнена сортировка shellSort2MMinus1" << std::endl;
    
}



// Собственно сортировка

void sort (std::vector<int>& array, int gap) {
    
    
    for (int i = gap; i < array.size(); i++) {
        
        int temp = array[i];
        
        int j;
        
        for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
            
            array[j] = array[j - gap];
            
        }
        
        
        array[j] = temp;
        

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



std::string typeOfAlgorythm (const int &type) {
    
    switch (type) {
            
        case 1: return "shellSort"; break;
        case 2: return "shellSortKnut"; break;
        case 3: return "shellSort2MMinus1"; break;
            
        default: return 0; break;
            
    }
    
}
