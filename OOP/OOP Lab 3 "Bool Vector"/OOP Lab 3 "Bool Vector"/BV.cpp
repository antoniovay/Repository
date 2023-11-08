//
//  BV.cpp
//  OOP Lab 3 "Bool Vector"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//



#include <iostream>
#include <vector>
#include <assert.h>

#include "BV.hpp"



BV::BV (const int length) {
    
    m_length = length;
    
    m_cellCount = length / 8 + (length % 8 != 0);
    
    m_unsignificantRankCount = m_cellCount * 8 - length;
    
    
    m_cells = new uint8_t [m_length];
    
    
    for (int i = 0; i < length; i++) {
        
        m_cells[i] = 0;
        
    }
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}



BV::BV (const int length, const int value) {
    
    m_length = length;
    
    m_cellCount = length / 8 + (length % 8 != 0);
    
    m_unsignificantRankCount = m_cellCount * 8 - length;
    
    
    m_cells = new uint8_t [m_cellCount];
    
    
    for (int i = 0; i < length; i++) {
        
        m_cells[i] = value;
        
    }
    
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}



BV::BV (const int length, const char* array) {
    
    assert(strlen(array) >= 0);
        
    m_length = (int) strlen(array);
    
    m_cellCount = m_length / 8 + (m_length % 8 != 0);
    
    m_unsignificantRankCount = (m_cellCount * 8) - m_length;
    
    m_cells = new uint8_t [m_cellCount];
    
    
    for (int i = 0; i < m_length; ++i) {
        
        if (array[i] != '0')
            
            set(i, 1);
        
        else
            
            set(i, 0);
        
    }
    
}



BV::BV (const BV &other) {
    
    m_length = other.m_length;
    
    m_cellCount = other.m_cellCount;
    
    m_unsignificantRankCount = other.m_unsignificantRankCount;
    
    m_cells = new uint8_t [other.m_cellCount];
    
    
    for (int i = 0; i < m_cellCount; ++i) {
        
        m_cells[i] = other.m_cells[i];
        
    }
    
}









int BV::length () {
    
    return m_length;
    
}



void BV::swap (BV &bv) {
    
    std::swap (m_length, bv.m_length);
    std::swap (m_cellCount, bv.m_cellCount);
    std::swap (m_unsignificantRankCount, bv.m_unsignificantRankCount);
    std::swap (m_cells, bv.m_cells);
    
}



void BV::inverse () {
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = ~m_cells[i];
        
    }
    
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}



void BV::inverse (const int i) {
    
    assert(i >= 0 && i < m_length);
    
    int currentUnit = i / 8, currentI = i % 8;
    
    uint8_t mask = 1;
    
    mask <<= 7 - currentI;
    
    if (m_cells[currentUnit] & mask) {
        
        m_cells[currentUnit] &= ~mask;
        
    }
    
    else {
        
        m_cells[currentUnit] |= mask;
        
    }
    
}



void BV::set (const int i, const bool x) {
    
    assert(i >= 0 && i < m_length);
    
    int currentUnit = i / 8, currentI = i % 8;
    
    uint8_t mask = 1;
    
    mask <<= 7 - currentI;
    
    
    if (x) {
        
        m_cells[currentUnit] |= mask;
    }
    
    else {
        
        m_cells[currentUnit] &= ~mask;
        
    }
    
}



void BV::setAfterK (const int k, const bool x) {
    
    
    
}



void BV::setAll (const bool x) {
    
    uint8_t mask = 0;
    
    if (x) {
        
        mask = 255;
        
    }
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = mask;
        
    }
    
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}



int BV::weight () {
    
    uint8_t mask;
    
    int weightCounter = 0;
    
    for (int i = 0; i < m_cellCount; i++) {
        
        mask = 1;
        
        for (; mask <= 128; mask <<= 1) {
            
            if (m_cells[i] & mask) {
                
                weightCounter++;
                
            }
            
        }
    }
    
    return weightCounter;
    
}












// Перегрузки


int BV::operator [] (const int i) {
    
    return m_cells[0];
    
}



BV BV::&operator & (const BV &other) {
    
    
    
}



BV BV::&operator &= (const BV &other) {
    
    
    
}



BV BV::&operator | (const BV &other) {
    
    
    
}



BV BV::&operator |= (const BV &other) {
    
    
    
}



BV BV::&operator ^ (const BV &other) {
    
    
    
}



BV BV::&operator ^= (const BV &other) {
    
    
    
}



BV BV::&operator << (const BV &other) {
    
    
    
}



BV BV::&operator <<= (const BV &other) {
    
    
    
}



BV BV::&operator >> (const BV &other) {
    
    
    
}




BV BV::&operator >>= (const BV &other) {
    
    
    
}



BV BV::&operator ~ () {
    
    
    
}



BV BV::&operator = (const BV &other) {
    
    
    
}






