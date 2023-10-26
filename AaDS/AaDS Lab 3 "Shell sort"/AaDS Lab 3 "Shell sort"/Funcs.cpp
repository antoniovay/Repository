//
//  Funcs.cpp
//  AaDS Lab 3 "Shell sort"
//
//  Created by Antony Miroshnichenko on 15.10.2023.
//



#include <iostream>
#include <time.h>
#include <string>

#include "Funcs.hpp"



// Вывод массива

void printArray (int *array, int size) {
    
    if (size > 100) {
        
        std::cout << "Массив не выыеден из-за слишком большого размера" << std::endl;
        
        return;
        
    }
    
    std::cout << "[";
    
    for (int i = 0; i < size; i++) {
        
        std::cout << array[i];
        
        if (i < size - 1) {
            
            std::cout << ", ";
            
        }
        
    }
    
    std::cout << "]" << std::endl;
    
}



// Генерация случайного массива

void randomArray (int *array, int size, int a, int b) {
    
    srand(time(0));
    
    for (int i = 0; i < size; i++) {
        
        array[i] = rand() % (b - a + 1) + a;
        
    }
    
}



// Сортировка Шелла с выбором длин промежутков по Шеллу

void shellSort (int *array, int size) {
    
    
    for (int gap = size / 2; gap > 0; gap /= 2) {
        
        
        sort(array, size, gap);
        
    }
    
    //std::cout << std::endl << "Выполнена сортировка shellSort" << std::endl;
}



// Сортировка Шелла с выбором длин промежутков по Кнуту

void shellSortKnut(int *array, int size) {
    
    int gap = 1;
    
    while (gap < size / 3) {
        
        sort(array, size, gap);
        
        gap = gap * 3 + 1;
        
    }
    
    //std::cout << std::endl << "Выполнена сортировка shellSortKnut" << std::endl;
    
}



// Сортировка Шелла с выбором длин промежутков по 2 ^ m - 1

void shellSort2MMinus1(int *array, int size) {
    
    int gap;
    
    for (int m = 1; pow(2, m) < size; m++) {
        
        gap = pow(2, m) - 1;
        
        sort(array, size, gap);
        
    }
    
    //std::cout << std::endl << "Выполнена сортировка shellSort2MMinus1" << std::endl;
    
}



// Собственно сортировка

void sort (int *array, int size, int gap) {
    
    
    for (int i = gap; i < size; i++) {
        
        int temp = array[i];
        
        int j;
        
        for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
            
            array[j] = array[j - gap];
            
        }
        
        
        array[j] = temp;
        

    }
}



// Проверка на упорядоченность

bool orderCheck (int *array, int size) {
    
    for (int i = 0; i < size - 1; i++) {
        
        if (array[i] > array[i + 1]) {
            
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
