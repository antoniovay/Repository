//
//  Functions.hpp
//  AaDS Lab 2 "BM Search"
//
//  Created by Antony Miroshnichenko on 01.10.2023.
//



#pragma once



// Вывод вектора
void printVector (const std::vector<int> nums);


// Заполнение таблицы TAB
void fillTAB (int* tab, std::string subString);


// Нахождение всех перестаановок в диапазоне, работа с вектором answer
void getOccurrences (std::vector<int> &answer, const std::string text, const std::string pattern, int* TAB, const int leftEdge, const int rightEdge);


// 1. Функция получения индекса первого вхождения подстроки в тексте
int searchBMFirstOccurrence (const std::string string, const std::string subString);


// 2. Функция получения индексов всех вхождений подстроки в тексте
std::vector<int> searchBMAllOccurrences (const std::string string,const std::string subString);


// 3. Функция получения индексов вхождений подстроки в тексте в заданном диапазоне (индексы начала и конца поиска в тексте)
std::vector<int> searchBMAllOccurrencesInDiapason (const std::string string, const std::string subString, const int start, const int stop);
