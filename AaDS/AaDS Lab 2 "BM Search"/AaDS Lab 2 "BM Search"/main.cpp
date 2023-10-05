//
//  main.cpp
//  AaDS Lab 2 "BM Search"
//
//  Created by Antony Miroshnichenko on 01.10.2023.
//



#include <iostream>
#include <vector>
#include <string>

#include "Functions.hpp"



int main()
{
    
    const std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator", pattern = "tor";
    
    const int leftEdge1 = 0, rightEdge1 = 91;
    const int leftEdge2 = 17, rightEdge2 = 91; // Нужно для проверки работы функции searchBMAllOccurrencesInDiapason
    const int leftEdge3 = 28, rightEdge3 = 36;
    
    int indexForFirstFunc; // Переменная для ответа из 1 функции (можно и в вектор listOfOccurrences записать)
    std::vector<int> listOfOccurrences; // Вектор
    
    
    
    // Реализация 1 функции
    
    indexForFirstFunc = searchBMFirstOccurrence(text, pattern);  // Одно число - индекд 1-го вхождения
    
    std::cout << "1. Индекс первого вхождения:  " << indexForFirstFunc << std::endl << std::endl;
    
    
    
    // Реализация 2 функции
    
    listOfOccurrences = searchBMAllOccurrences(text, pattern); // Вектор, т.к. возможно несколько значений
    
    std::cout << "2. Индексы всех вхождений:  ";
    printVector (listOfOccurrences);
    
    std::cout << std::endl;
    
    
    
    // Реализация 3 функции в диапазоне [0, 91] (весь текст)
    
    listOfOccurrences = searchBMAllOccurrencesInDiapason(text, pattern, leftEdge1, rightEdge1);  // Вектор, т.к. возможно несколько значений
    
    std::cout << "3.1. Индексы всех вхождений в диапазоне [" << leftEdge1 << ", " << rightEdge1 << "]:  ";
    printVector(listOfOccurrences);
    
    
    
    // Реализация 3 функции в диапазоне [17, 91]
    
    listOfOccurrences = searchBMAllOccurrencesInDiapason(text, pattern, leftEdge2, rightEdge2);
    
    std::cout << "3.2. Индексы всех вхождений в диапазоне [" << leftEdge2 << ", " << rightEdge2 << "]:  ";
    printVector(listOfOccurrences);
    
    
    
    // Реализация 3 функции в диапазоне [28, 36]
    
    listOfOccurrences = searchBMAllOccurrencesInDiapason(text, pattern, leftEdge3, rightEdge3);
    
    std::cout << "3.3. Индексы всех вхождений в диапазоне [" << leftEdge3 << ", " << rightEdge3 << "]:  ";
    printVector(listOfOccurrences);
    
    
    
    std::cout << std::endl << std::endl;
    
}
