//
//  Set.hpp
//  OOP Lab 6 "Set"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#pragma once



#include <iostream>
#include <assert.h>
#include <string>
#include <algorithm>
#include <vector>

#include "BoolVector.hpp"





class Set: public BoolVector
{
    
public:
    
    static const int MAX_CODE = 127;
    static const std::vector<std::string> SPECIAL_SYMBOLS;
    
    friend std::istream &operator >> (std::istream &stream, Set &object);
    friend std::ostream &operator << (std::ostream &stream, const Set &object);
    
    // Конструкторы //------------------------------------------------------------------------------------------------------------------------------
    
    Set (const char value = (char) MAX_CODE) : BoolVector(MAX_CODE) {
        
        if (value < MAX_CODE) {
            
            set((int) value, 1);
            
        }
        
    }
    
    Set (const char* arr);
    Set (const Set &other);
    
    ~Set() {}
    
    
    // Методы //------------------------------------------------------------------------------------------------------------------------------------
    
    bool is_in_set (const char value) const;
    
    char max() const;
    char min() const;
    
    int power();
    
    
    // Перегрузки //--------------------------------------------------------------------------------------------------------------------------------
    
    Set &operator = (const Set &other);
    
    bool operator == (const Set &other) const;
    bool operator != (const Set &other) const;
    
    Set operator | (const Set &object) const;
    Set &operator |= (const Set &object);
    
    Set operator & (const Set &object) const;
    Set &operator &= (const Set &object);
    
    Set operator / (const Set &object) const;
    Set &operator /= (const Set &object);
    
    Set operator ~ () const;
    
    Set operator + (const char value) const;
    Set &operator += (const char value);
    
    Set operator - (const char value) const;
    Set &operator -= (const char value);
    
};



