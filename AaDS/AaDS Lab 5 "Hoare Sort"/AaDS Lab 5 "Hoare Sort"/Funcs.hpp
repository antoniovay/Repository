//
//  Funcs.hpp
//  AaDS Lab 5 "Hoare Sort"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//



#pragma once

#include <iostream>
#include <vector>



void printVector (std::vector<int> array); // Вывод массива

void scanVectorFromFile(std::vector<int>& array, const std::string& name); // Считать вектор из файла

std::string createNameOfFile(int size, int range); // Сгенерировать имя файла

void randomVector (std::vector<int>& array, int size, int a, int b); // Генерация случайного массива

void orderCheck (const std::vector<int> array); // Проверка на упорядоченность



void hoareSort(std::vector<int>& array, int l, int r); // Сортировка Хоара_3
