//
//  BV.hpp
//  OOP Lab 3 "Bool Vector"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//



#pragma once

#include <iostream>



class BV
{
    
    
public:
    
    // Конструкторы
    
    BV (const int size = 10); // Конструктор по умолчанию
    
    BV (const int size, const int value); // Конструктор с параметром (размер и значение - одно и то же для всех разрядов)
    BV (const int size, const char* array); // Конструктор с параметром (из массива const char *)
    
    BV (const BV &bv); // Конструктор копирования
    
    
    ~BV() { // Деструктор
        
        delete [] m_bv;
        
    }
    
    
    
    // Другие методы
    
    int length (); // Длина (кол-во битов вектора)
    
    void swap (BV &bv); // Обмен содержимого с другим вектором
    
    void inverse (); // Инверсия всех компонент вектора
    void inverse (const int i); // Инверсия i-ой компоненты
    
    void set (const int i, const bool x); // Установка в 0/1 i-ой компоненты
    void setAfterK (const int i, const bool x); // Установка в 0/1 k компонент, начиная с i-ой
    void setAll (const bool x); // Установка в 0/1 всех компонент вектора
    
    int weight (); // Вес вектора (количество единичных компонент)
    
    
    
    // Перегрузки
    
    int operator [] (const int i); // Получение компоненты
    
    BV &operator & (const BV &other);  // Побитовое умножение &
    BV &operator &= (const BV &other); // Побитовое умножение &=
    
    BV &operator | (const BV &other); // Побитовое сложение |
    BV &operator |= (const BV &other); // Побитовое сложение |=
    
    BV &operator ^ (const BV &other); // Побитовое исключающее ИЛИ ^
    BV &operator ^= (const BV &other); // Побитовое исключающее ИЛИ ^=
    
    BV &operator << (const BV &other); // Побитовый сдвиг <<
    BV &operator <<= (const BV &other); // Побитовый сдвиг <<=
    
    BV &operator >> (const BV &other); // Побитовый сдвиг >>
    BV &operator >>= (const BV &other); // Побитовый сдвиг >>=
    
    BV &operator ~ (); // Побитовая инверсия
    
    BV &operator = (const BV &other); // Оператор присваивания
    
    
    
private:
    
    unsigned char* m_bv;
    int m_size;
    
};




std::istream &operator >> (std::istream &stream, BV& bv) { // Потоковый ввод
    
    for (int i = 0; i < bv.length(); i++) {
        
        stream >> bv[i];
        
    }
    
    return stream;
}



std::ostream &operator << (std::ostream &stream, BV& bv) { // Потоковый вывод
    
    for (int i = 0; i < bv.length(); i++) {
        
        stream << bv[i];
        
    }
    
    return stream;
    
    
}
