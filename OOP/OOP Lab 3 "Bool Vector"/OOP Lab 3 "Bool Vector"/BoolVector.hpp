//
//  BV.hpp
//  OOP Lab 3 "Bool Vector"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//



#pragma once

#include <iostream>
#include <assert.h>





// Класс BV //----------------------------------------------------------------------------------------------------------------------------------------



class BoolVector
{
    
    friend std::istream &operator >> (std::istream &stream, BoolVector& bv);
    friend std::ostream &operator << (std::ostream &stream, const BoolVector& bv);
    
    class BoolRank;
    
    friend class Set;
    
public:
    
    // Конструкторы
    
    BoolVector (const int length = 10); // Конструктор по умолчанию
    
    BoolVector (const int length, const int value); // Конструктор с параметром (размер и значение - одно и то же для всех разрядов)
    BoolVector (const char* array); // Конструктор с параметром (из массива const char *)
    
    BoolVector (const BoolVector &bv); // Конструктор копирования
    
    
    ~BoolVector() { // Деструктор
        
        delete [] m_cells;
        
    }
    
    
    
    // Другие методы
    
    int length () const; // Длина (кол-во битов вектора)
    
    void swap (BoolVector &bv); // Обмен содержимого с другим вектором
    
    void inverse (); // Инверсия всех компонент вектора
    
    void inverse (const int i); // Инверсия i-ой компоненты
    
    void set (const int i, const bool x); // Установка в 0/1 i-ой компоненты
    
    
    
    void setAfterK (const int i, const int k, const bool x); // Установка в 0/1 k компонент, начиная с i-ой
    void setAll (const bool x); // Установка в 0/1 всех компонент вектора
    
    int weight () const; // Вес вектора (количество единичных компонент)
    
    
    
    // Перегрузки
    
    //int operator [] (const int i); // Получение компоненты
    BoolRank operator [] (const int i); // Получение компоненты
    const BoolRank operator [] (const int i) const; // Получение компоненты
    
    BoolVector operator & (const BoolVector &other) const;  // Побитовое умножение &
    BoolVector &operator &= (const BoolVector &other); // Побитовое умножение &=
    
    BoolVector operator | (const BoolVector &other) const; // Побитовое сложение |
    BoolVector &operator |= (const BoolVector &other); // Побитовое сложение |=
    
    BoolVector operator ^ (const BoolVector &other) const; // Побитовое исключающее ИЛИ ^
    BoolVector &operator ^= (const BoolVector &other); // Побитовое исключающее ИЛИ ^=
    
    BoolVector operator << (const int value) const; // Побитовый сдвиг <<
    BoolVector &operator <<= (const int value); // Побитовый сдвиг <<=
    
    BoolVector operator >> (const int value) const; // Побитовый сдвиг >>
    BoolVector &operator >>= (const int value); // Побитовый сдвиг >>=
    
    BoolVector operator ~ () const; // Побитовая инверсия
    
    BoolVector &operator = (const BoolVector &other); // Оператор присваивания
    
    bool operator == (const BoolVector& other) const;
    bool operator != (const BoolVector& other) const;
    
    
private:
    
    uint8_t* m_cells = nullptr;
    
    uint8_t m_unsignificantRankCount = 0;
    
    int m_length = 0;
    int m_cellCount = 0;
    
    
};




// Класс BoolRank //----------------------------------------------------------------------------------------------------------------------------------



class BoolVector::BoolRank 
{
    
public:
    
    BoolRank(uint8_t* cell, const int& maskPos) {
        
        m_cell = cell;
        
        m_mask >>= maskPos;
        
    }
    
    BoolRank& operator = (const bool value);
    BoolRank& operator = (const BoolRank& other);
    
    bool operator | (const bool value) const;
    
    bool operator & (const bool value) const;
    
    bool operator ~ () const;
    
    bool operator ^ (const bool value) const;
    
    bool operator == (const bool value) const;
    bool operator == (const BoolRank& other) const;
    
    operator bool() const;
    
    
private:
    
    
    uint8_t* m_cell = nullptr;
    uint8_t m_mask = 1 << 7;
    
};





// Потоковые ввод и вывод //--------------------------------------------------------------------------------------------------------------------------


std::istream &operator >> (std::istream &stream, BoolVector& bv);
std::ostream &operator << (std::ostream &stream, const BoolVector& bv);
