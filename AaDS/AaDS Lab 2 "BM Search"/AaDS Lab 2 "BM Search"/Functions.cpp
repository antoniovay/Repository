//
//  Functions.cpp
//  AaDS Lab 2 "BM Search"
//
//  Created by Antony Miroshnichenko on 01.10.2023.
//



#include <iostream>
#include <string>
#include <vector>

#include "Functions.hpp"



void printVector (const std::vector<int> vectorOfOccurrences) { // Вывод вектора
    
    for (auto it = vectorOfOccurrences.begin(); it != vectorOfOccurrences.end(); it++) {
        
        if ( it != vectorOfOccurrences.begin() ) {
            
            std::cout << ", ";
            
        }
        
        std::cout << *it;
        
    }
    
    std::cout << ";" << std::endl;
    
}



void fillTAB (int* TAB, std::string pattern) { // Заполнение таблицы TAB
    
    const int sizeOfPattern = (int) pattern.size();
    
    for (int i = 0; i < sizeOfPattern - 1; i++) {
        
        TAB[pattern[i]] = sizeOfPattern - 1 - i;
        
    }
    
    for (int i = 0; i < 256; i++) {
        
        if ( !(TAB[i]) ) {
            
            TAB[i] = sizeOfPattern;
            
        }
        
    }
}



// Нахождение всех перестаановок в диапазоне
void getOccurrences (std::vector<int> &listOfOccurrences, const std::string text, const std::string pattern, int* TAB, const int leftEdge, const int rightEdge) {
    
    if (pattern.size() == 0)
        
        return;
    
    const int sizeOfPattern = (int) pattern.size();
    
    {
        
        int i = sizeOfPattern + leftEdge - 1, j = sizeOfPattern - 1, k = i;
        
        bool f = 0, a = 1;
        
        while (a) {
            
            if ( i >= 0 && i < (rightEdge + 1) ) {
                
                if (j >= 0) {
                    
                    if (text[k] == pattern[j]) {
                        
                        k--;
                        j--;
                        
                        if (j <= 0) {
                            
                            f = 1;
                            
                        }
                        
                    }
                    
                    else {
                        
                        if (f) {
                            
                            listOfOccurrences.push_back(i + 1 - sizeOfPattern);
                            
                        }
                        
                        f = 0;
                        
                        i += TAB[text[i]];
                        
                        j = sizeOfPattern - 1;
                        
                        k = i;
                        
                    }
                    
                }
                
                else {
                    
                    j = sizeOfPattern - 1;
                    
                }
                
            }
            
            else {
                
                a = 0;
                
            }
            
        }
    }
}



// Функция получения индекса первого вхождения подстроки в тексте
int searchBMFirstOccurrence (const std::string text, const std::string pattern) {
    
    int start = 0, stop = (int) pattern.size();
    
    int TAB[256] = {0};
    
    fillTAB(TAB, pattern);
    
    std::vector<int> listOfOccurrences;
    
    while (listOfOccurrences.size() < 1 && stop < text.size() && stop != 0) {
        
        getOccurrences(listOfOccurrences, text, pattern, TAB, start, stop);
        
        start = stop;
        stop += stop;
        
    }
    
    if ( !listOfOccurrences.empty() ) {
        
        return listOfOccurrences[0];
        
    }
    
    return -1;
    
}



// Функция получения индексов всех вхождений подстроки в тексте
std::vector<int> searchBMAllOccurrences (const std::string text, const std::string pattern) {
    
    const int leftEdge = 0, rightEdge = (int) text.size();
    
    int TAB[256] = {0};
    
    fillTAB(TAB, pattern);
    
    std::vector<int> listOfOccurrences;
    
    getOccurrences(listOfOccurrences, text, pattern, TAB, leftEdge, rightEdge);
    
    return listOfOccurrences;
    
}



// Функция получения индексов вхождений подстроки в тексте в заданном диапазоне (индексы начала и конца поиска в тексте)
std::vector<int> searchBMAllOccurrencesInDiapason(const std::string text, const std::string pattern, const int leftEdge, const int rightEdge) {
    
    int TAB[256] = {0};
    
    fillTAB(TAB, pattern);
    
    std::vector<int> listOfOccurrences;
    
    getOccurrences(listOfOccurrences, text, pattern, TAB, leftEdge, rightEdge);
    
    return listOfOccurrences;
    
}
