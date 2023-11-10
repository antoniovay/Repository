//
//  BV.hpp
//  OOP Lab 3 "Bool Vector"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//



#pragma once

#include <iostream>





// Класс BV //----------------------------------------------------------------------------------------------------------------------------------------



class BV
{
    
    friend std::istream &operator >> (std::istream &stream, BV& bv);
    friend std::ostream &operator << (std::ostream &stream, BV& bv);
    
    class BoolRank;
    
public:
    
    // Конструкторы
    
    BV (const int length = 10); // Конструктор по умолчанию
    
    BV (const int length, const int value); // Конструктор с параметром (размер и значение - одно и то же для всех разрядов)
    BV (const int length, const char* array); // Конструктор с параметром (из массива const char *)
    
    BV (const BV &bv); // Конструктор копирования
    
    
    ~BV() { // Деструктор
        
        delete [] m_cells;
        
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
    
    //int operator [] (const int i); // Получение компоненты
    BoolRank operator [] (const int i); // Получение компоненты
    const BoolRank operator [] (const int i) const; // Получение компоненты
    
    BV operator & (const BV &other);  // Побитовое умножение &
    BV &operator &= (const BV &other); // Побитовое умножение &=
    
    BV operator | (const BV &other); // Побитовое сложение |
    BV &operator |= (const BV &other); // Побитовое сложение |=
    
    BV operator ^ (const BV &other); // Побитовое исключающее ИЛИ ^
    BV &operator ^= (const BV &other); // Побитовое исключающее ИЛИ ^=
    
    BV operator << (const int value); // Побитовый сдвиг <<
    BV &operator <<= (const int value); // Побитовый сдвиг <<=
    
    BV operator >> (const int value); // Побитовый сдвиг >>
    BV &operator >>= (const int value); // Побитовый сдвиг >>=
    
    BV operator ~ (); // Побитовая инверсия
    
    BV &operator = (const BV &other); // Оператор присваивания
    
    
    
private:
    
    uint8_t* m_cells = nullptr;
    
    uint8_t m_unsignificantRankCount = 0;
    
    int m_length = 0;
    int m_cellCount = 0;
    
    
};




// Класс BoolRank //----------------------------------------------------------------------------------------------------------------------------------



class BV::BoolRank 
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



std::istream &operator >> (std::istream &stream, BV& bv) { // Потоковый ввод
    
    char* string = new char [bv.m_length];
    
        for (int i = 0; i < bv.m_length; ++i) {
            
            stream >> string[i];
            
        }
        
        for (unsigned int i = 0; i < bv.m_length; ++i) {
            
            if (string[i] != '0')
                
                bv.set(i, 1);
            
            else
            
                bv.set(i, 0);
            
        }
        
        delete [] string;
    
        return stream;
    
}



std::ostream &operator << (std::ostream &stream, BV& bv) { // Потоковый вывод
    
    for (int i = 0; i < bv.m_cellCount; ++i) {
        
            stream << "[";
        
            for (uint8_t j = 1 << 7; j > 0; j >>= 1) {
                
                if (bv.m_cells[i] & j) {
                    
                    stream << "1";
                    
                    if ((j >> 1) > 0)
                        
                        stream << " ";
                    
                }
                
                else {
                    
                    stream << "0";
                    
                    if ((j >> 1) > 0)
                        
                        stream << " ";
                    
                }
                
            }
        
            stream << "] ";
        
        }
    
        stream << std::endl;
        
        return stream;
    
    
}
