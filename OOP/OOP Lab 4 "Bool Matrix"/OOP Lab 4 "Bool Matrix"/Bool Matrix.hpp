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
    
    
    friend std::istream &operator >> (std::istream& stream, BoolMatrix &other);
    friend std::ostream &operator << (std::ostream& stream, const BoolMatrix &other);
    
    
public:
    
    // Методы //-------------------------------------------------------------------------------------------------------------------------------------
    
    BoolMatrix (const int columnCount = 5, const int lineCount = 5, const bool value = 0); // Конструктор по умолчанию
    BoolMatrix (char** matrix, int lineCount, int columnCount); // Конструктор из матрицы char
    BoolMatrix (const BoolMatrix &other); // Конструктор копирования
    
    ~BoolMatrix () { // Деструктор
        
        delete [] m_line;
        
    }
    
    int lineCount() const; // Получить число строк
    int columnCount() const; // Получить число столбцов
    void swap (BoolMatrix &other); // Обмен содержимого с другой матрицей
    int weight() const; // Вес матрицы
    
    BoolVector conjunction() const; // Конъюнкция всех строк
    BoolVector disjunction() const; // Дизъюнкция всех строк

    int weight (int j) const; // Вес j-й строки
    
    void invert (const int row, const int column); // Инверсия в i-ой компоненты j-ой строки
    void invert (const int row, const int start, const int k); // Инверсия k компонент j-ой строки, начиная с i-ой компоненты
    void set (const int row, const int column, const int value); // Установка в 0/1 i-ой компоненты j-ой строки
    void set (const int row, const int start, const int k, const int value); // Установка в 0/1 k компонент j-ой строки, начиная с i-ой компоненты
    
    
    // Перегрузки //---------------------------------------------------------------------------------------------------------------------------------
    
    BoolMatrix &operator = (const BoolMatrix &other); // Присваивание
    
    BoolVector &operator [] (const int j); // Получение строки
    const BoolVector &operator [] (const int j) const; // Получение строки const
    
    BoolMatrix operator & (const BoolMatrix &other) const; // Построчное побитовое умножение &
    BoolMatrix &operator &= (const BoolMatrix &other); // Построчное побитовое умножение &=
    
    BoolMatrix operator | (const BoolMatrix &other) const; // Построчное побитовое сложение |
    BoolMatrix &operator |= (const BoolMatrix &other); // Построчное побитовое сложение|=
    
    BoolMatrix operator ^ (const BoolMatrix &other) const; // Построчное побитовое исключающее ИЛИ ^
    BoolMatrix &operator ^= (const BoolMatrix &other); // Построчное побитовое исключающее ИЛИ ^=
    
    BoolMatrix operator ~ () const; // Построчная побитовая инверсия
    
    
private:
    
    BoolVector* m_line = nullptr;
    int m_lineCount;
    int m_columnCount;
    
};





std::istream &operator >> (std::istream& stream, BoolMatrix &other);
std::ostream &operator << (std::ostream& stream, const BoolMatrix &other);
