//
//  Set.hpp
//  OOP Lab 6 "Set"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#pragma once



#include <iostream>
#include <assert.h>

#include "BoolVector.hpp"





class Set: public BoolVector
{
    
public:
    
    friend std::istream &operator >> (std::istream &stream, Set &object);
    friend std::ostream &operator << (std::ostream &stream, const Set &object);
    
    // Конструкторы //------------------------------------------------------------------------------------------------------------------------------
    
    Set (const char value = 32);
    Set (const char* arr);
    Set (const Set &other);
    
    ~Set() {
        
        delete [] m_set;
        
    }
    
    
    // Методы //------------------------------------------------------------------------------------------------------------------------------------
    
    bool is_in_set (const char ch);
    
    char max();
    char min();
    
    int size();
    
    
    // Перегрузки //--------------------------------------------------------------------------------------------------------------------------------
    
    Set &operator = (const Set &other);
    
    bool operator == (const Set &other);
    bool operator != (const Set &other);
    
    Set operator | (const Set &other);
    Set &operator |= (const Set &other);
    
    Set operator & (const Set &other);
    Set &operator &= (const Set &other);
    
    Set operator / (const Set &other);
    Set &operator /= (const Set &other);
    
    Set operator ~ ();
    
    Set operator + (const Set &other);
    Set &operator += (const Set &other);
    
    Set operator - (const Set &other);
    Set &operator -= (const Set &other);
    
    
private:
    
    int m_size;
    BoolVector* m_set = nullptr;
    
    
};
