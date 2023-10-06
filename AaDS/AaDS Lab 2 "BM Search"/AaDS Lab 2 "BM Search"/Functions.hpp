//
//  Functions.hpp
//  AaDS Lab 2 "BM Search"
//
//  Created by Antony Miroshnichenko on 01.10.2023.
//



#pragma once



// Вывод вектора
void printVector (const std::vector<int> vectorOfOccurrences);


// Заполнение таблицы TAB
void fillTAB (int* TAB, std::string pattern);


// Нахождение всех перестаановок в диапазоне, работа с вектором answer
void getOccurrences (std::vector<int> &listOfOccurrences, const std::string text, const std::string pattern, int* TAB, const int leftEdge, const int rightEdge);


// 1. Функция получения индекса первого вхождения подстроки в тексте
int searchBMFirstOccurrence (const std::string text, const std::string pattern);


// 2. Функция получения индексов всех вхождений подстроки в тексте
std::vector<int> searchBMAllOccurrences (const std::string text, const std::string pattern);


// 3. Функция получения индексов вхождений подстроки в тексте в заданном диапазоне (индексы начала и конца поиска в тексте)
std::vector<int> searchBMAllOccurrencesInDiapason (const std::string text, const std::string pattern, const int leftEdge, const int rightEdge);
