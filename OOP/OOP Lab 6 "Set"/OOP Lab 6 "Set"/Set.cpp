//
//  Set.cpp
//  OOP Lab 6 "Set"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#include "Set.hpp"



// Конструкторы //------------------------------------------------------------------------------------------------------------------------------------



Set::Set (const char value) {
    
    assert(value >= 32 && value <= 127);
    
    m_size = 0;
    
    m_set = new BoolVector[100];
    
    
    
}



Set::Set (const char* arr) {
    
    
    
}



Set::Set (const Set &other) {
    
    
    
}



// Методы //------------------------------------------------------------------------------------------------------------------------------------------



bool is_in_set(const char ch) {
    
    
    
}



char max() {
    
    
    
}



char min() {
    
    
    
}



int size() {
    
    
    
}



// Перегрузки //--------------------------------------------------------------------------------------------------------------------------------------



Set &operator = (const Set &other) {
    
    
    
}




bool operator == (const Set &other) {
    
    
    
}




bool operator != (const Set &other) {
    
    
    
}




Set operator | (const Set &other) {
    
    
    
}




Set &operator |= (const Set &other) {
    
    
    
}




Set operator & (const Set &other) {
    
    
    
}




Set &operator &= (const Set &other) {
    
    
    
}




Set operator / (const Set &other) {
    
    
    
}




Set &operator /= (const Set &other) {
    
    
    
}




Set operator ~ () {
    
    
    
}




Set operator + (const Set &other) {
    
    
    
}




Set &operator += (const Set &other) {
    
    
    
}




Set operator - (const Set &other) {
    
    
    
}




Set &operator -= (const Set &other) {
    
    
    
}




