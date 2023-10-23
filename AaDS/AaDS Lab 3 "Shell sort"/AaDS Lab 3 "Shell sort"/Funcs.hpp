//
//  Funcs.hpp
//  AaDS Lab 3 "Shell sort"
//
//  Created by Antony Miroshnichenko on 15.10.2023.
//



#pragma once

#include <iostream>



void printArray (int *array, int size); // Вывод массива

void randomArray (int *array, int size, int a, int b); // Генерация случайного массива


void shellSort (int *array, int size); // Сортировка Шелла с выбором длин промежутков по Шеллу

void sort (int *array, int size, int gap); // Собственно сортировка


bool orderCheck (int *array, int size); // Проверка на упорядоченность
