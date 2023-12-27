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
    
    char valueCopy = value;
    
    m_size = 1;
    
    m_set = new BoolVector[100];
    
    for (int i = 0; i < 100; i++)
    
        m_set[i] = BoolVector(7);
    
    for (int i = 6; i > 0; i--) {
        
        bool x = valueCopy / pow (2, i);
        
        m_set[0].set(i, x);
        
        //valueCopy = (char) ((unsigned int) valueCopy % pow (2, i));
        
    }
    
    
    
}



Set::Set (const char* arr) {
    
    
    
}



Set::Set (const Set &other) {
    
    
    
}



// Методы //------------------------------------------------------------------------------------------------------------------------------------------



bool Set::is_in_set(const char ch) {
    
    
    
}



char Set::max() {
    
    
    
}



char Set::min() {
    
    
    
}



int Set::size() {
    
    return m_size;
    
}



// Перегрузки //--------------------------------------------------------------------------------------------------------------------------------------



Set &Set::operator = (const Set &other) {
    
    
    
}




bool Set::operator == (const Set &other) {
    
    
    
}




bool Set::operator != (const Set &other) {
    
    
    
}




Set Set::operator | (const Set &other) {
    
    Set result(*this);
    
    result |= other;
    
    return result;
    
}




Set &Set::operator |= (const Set &other) {
    
    
    
    return *this;
    
}




Set Set::operator & (const Set &other) {
    
    Set result(*this);
    
    result &= other;
    
    return result;
    
}




Set &Set::operator &= (const Set &other) {
    
    
    
    return *this;
    
}




Set Set::operator / (const Set &other) {
    
    Set result(*this);
    
    result /= other;
    
    return result;
    
}




Set &Set::operator /= (const Set &other) {
    
    
    
    return *this;
    
}




Set Set::operator ~ () {
    
    Set result(*this);
    
    
    
    return result;

}




Set Set::operator + (const Set &other) {
    
    Set result(*this);
    
    result += other;
    
    return result;
    
}




Set &Set::operator += (const Set &other) {
    
    
    
}




Set Set::operator - (const Set &other) {
    
    Set result(*this);
    
    result -= other;
    
    return result;
    
}




Set &Set::operator -= (const Set &other) {
    
    
    
}









std::istream &operator >> (std::istream &stream, Set &object) {
    
    for (int i = 0; i < object.m_size; i++) {
        
        
        
    }
    
    return stream;
    
}



std::ostream &operator << (std::ostream &stream, const Set &object) {
    
    stream << "[ ";
    
    for (int i = 0; i < object.m_size; i++) {
        
        stream << object[i] << " ";
        
    }
    
    stream << "]" << std::endl;
    
    return stream;
    
}
