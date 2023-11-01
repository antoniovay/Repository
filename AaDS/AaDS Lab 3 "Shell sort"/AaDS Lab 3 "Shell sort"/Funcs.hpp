//
//  Funcs.hpp
//  AaDS Lab 3 "Shell sort"
//
//  Created by Antony Miroshnichenko on 15.10.2023.
//



#pragma once

#include <iostream>



std::string createNameOfFile(int size, int range);

void printVectorToFile (const std::vector<int> array, const std::string name); // Записать вектор в файл


void printVector (std::vector<int> array); // Вывод массива

void randomVector (std::vector<int>& array, int size, int a, int b); // Генерация случайного массива


void shellSort (std::vector<int>& array); // Сортировка Шелла с выбором длин промежутков по Шеллу

void shellSortKnut(std::vector<int>& array); // Сортировка Шелла с выбором длин промежутков по Кнуту

void shellSort2MMinus1(std::vector<int>& array); // Сортировка Шелла с выбором длин промежутков по 2 ^ m - 1

void sort (std::vector<int>& array, int gap); // Собственно сортировка


bool orderCheck (const std::vector<int> array); // Проверка на упорядоченность

std::string typeOfAlgorythm (const int &number);
