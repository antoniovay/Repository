//
//  Bool Matrix.hpp
//  OOP Lab 4 "Bool Matrix"
//
//  Created by Antony Miroshnichenko on 15.11.2023.
//



#pragma once



#include <iostream>
#include <vector>

#include "BoolVector.hpp"



class BoolMatrix
{
    
public:
    
    // Методы //-------------------------------------------------------------------------------------------------------------------------------------
    
    BoolMatrix (int lineCount = 5, int columnCount = 5, int value = 0); // Конструктор по умолчанию
    BoolMatrix (char** matrix, int lineCount, int columnCount); // Конструктор из матрицы char
    BoolMatrix (const BoolMatrix &other); // Конструктор копирования
    
    ~BoolMatrix () { // Деструктор
        
        delete [] m_line;
        
    }
    
    int lineCount(); // Получить число строк
    int columnCount(); // Получить число столбцов
    void swap (BoolMatrix &other); // Обмен содержимого с другой матрицей
    int weight(); // Вес матрицы
    
    BoolVector conjunction(); // Конъюнкция всех строк
    BoolVector disjunction(); // Дизъюнкция всех строк

    int weight (int j); // Вес j-й строки
    
    void invert(int i, int j); // Инверсия в i-ой компоненты j-ой строки
    void invertFrom (int i, int j, int k); // Инверсия k компонент j-ой строки, начиная с i-ой компоненты
    void set (int i, int j, int value); // Установка в 0/1 i-ой компоненты j-ой строки
    void setFrom (int i, int j, int k, int value); // Установка в 0/1 k компонент j-ой строки, начиная с i-ой компоненты
    
    
    // Перегрузки //---------------------------------------------------------------------------------------------------------------------------------
    
    BoolMatrix &operator = (const BoolMatrix &other); // Присваивание
    
    BoolVector &operator [] (const int j); // Получение строки
    const BoolVector &operator [] (const int j) const; // Получение строки const
    
    BoolMatrix operator & (const BoolMatrix &other); // Построчное побитовое умножение &
    BoolMatrix &operator &= (const BoolMatrix &other); // Построчное побитовое умножение &=
    
    BoolMatrix operator | (const BoolMatrix &other); // Построчное побитовое сложение |
    BoolMatrix &operator |= (const BoolMatrix &other); // Построчное побитовое сложение|=
    
    BoolMatrix operator ^ (const BoolMatrix &other); // Построчное побитовое исключающее ИЛИ ^
    BoolMatrix &operator ^= (const BoolMatrix &other); // Построчное побитовое исключающее ИЛИ ^=
    
    BoolMatrix operator ~ (); // Построчная побитовая инверсия
    
    
private:
    
    BoolVector* m_line;
    int m_lineCount;
    int m_columnCount;
    
};





std::istream &operator >> (std::istream& stream, BoolMatrix &other);
std::ostream &operator << (std::ostream& stream, const BoolMatrix &other);
