//
//  BV.cpp
//  OOP Lab 3 "Bool Vector"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//



#include <iostream>
#include <vector>

#include "BV.hpp"



BV::BV (const int size) {
    
    m_bv = new unsigned char [m_size];
    
    for (int i = 0; i < size; i++) {
        
        m_bv[i] = 0;
        
    }
    
}



BV::BV (const int size, const int value) {
    
    m_bv = new unsigned char [m_size];
    
    for (int i = 0; i < size; i++) {
        
        m_bv[i] = value;
        
    }
    
}



BV::BV (const int size, const char* array) {
    
    m_bv = new unsigned char [m_size];
    
    for (int i = 0; i < size; i++) {
        
        m_bv[i] = array[i];
        
    }
    
}



BV::BV (const BV &other) {
    
    m_bv = new unsigned char [other.length()];
    
    for (int i = 0; i < other.length; i++) {
        
        m_bv[i] = other.m_bv[i];
        
    }
    
}









int BV::length () {
    
    return m_size;
    
}

