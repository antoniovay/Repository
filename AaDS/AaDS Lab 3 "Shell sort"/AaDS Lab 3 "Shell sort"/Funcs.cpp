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
        
        sort(array, gap);
        
        gap = gap * 3 + 1;
        
    }
    
    //std::cout << std::endl << "Выполнена сортировка shellSortKnut" << std::endl;
    
}



// Сортировка Шелла с выбором длин промежутков по 2 ^ m - 1

void shellSort2MMinus1(std::vector<int>& array) {
    
    int gap;
    
    for (int m = 2; m < array.size(); m *= 2) {
        
        gap = m - 1;
        
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
