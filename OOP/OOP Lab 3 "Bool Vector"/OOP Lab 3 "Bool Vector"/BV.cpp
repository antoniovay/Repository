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
    
    m_cellCount = length / 8 + (length % 8 != 0);
    
    
    m_cells = new uint8_t [m_cellCount];
    
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = 0;
        
    }
    
    
    m_unsignificantRankCount = m_cellCount * 8 - length;
    
    
    m_length = length;
    
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}



BV::BV (const int length, const int value) {
    
    m_cellCount = length / 8 + (length % 8 != 0);
    
    
    m_cells = new uint8_t [m_cellCount];
    
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = value;
        
    }
    
    
    m_unsignificantRankCount = m_cellCount * 8 - length;
    
    
    m_length = length;
    
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}



BV::BV (const int length, const char* array) {
    
    assert (strlen(array) >= 0);
    
    m_length = (int) strlen(array);
    
    m_cellCount = m_length / 8 + (m_length % 8 != 0);
    
    
    m_cells = new uint8_t [m_cellCount];
    
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = array[i];
        
    }
    
    
    m_unsignificantRankCount = (m_cellCount * 8) - m_length;
    
}



BV::BV (const BV &other) {
    
    m_cells = new uint8_t [other.m_cellCount];
    
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = other.m_cells[i];
        
    }
    
    
    m_unsignificantRankCount = other.m_unsignificantRankCount;
    
    
    m_length = other.m_length;
    
    m_cellCount = other.m_cellCount;
    
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
    
    assert(k >= 0 && k < m_length);
    
    int currentUnit = k / 8, currentI = k % 8;
    
    uint8_t mask = 1;
    
    mask <<= 7 - currentI;
    
    for (; mask <= 128; mask >>= 1) {
        
        if (x) {
            
            m_cells[currentUnit] |= mask;
        }
        
        else {
            
            m_cells[currentUnit] &= ~mask;
            
        }
        
    }
    
    for (int i = currentUnit; i < m_cellCount; i++) {
        
        if (x) {
            
            m_cells[i] = 255;
            
        }
        
        else {
            
            m_cells[i] = 0;
            
        }
        
    }
    
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



/*
int BV::operator [] (const int i) {
    
    assert(i >= 0 && i < m_length);
    
    int currentUnit = i / 8, currentI = i % 8;
    
    uint8_t mask = 1;
    
    mask <<= 7 - currentI;
    
    if (m_cells[i] & mask)
        
        return 1;
    
    else return 0;
    
}
*/



BV::BoolRank BV::operator [] (const int i) {
    
    assert(i >= 0 && i < m_length);
    
    return BoolRank (m_cells + i / 8, i % 8);
    
}

const BV::BoolRank BV::operator [] (const int i) const {
    
    assert(i >= 0 && i < m_length);
    
    return BoolRank (m_cells + i / 8, i % 8);
    
}



BV BV::operator & (const BV &other) {
    
    assert (m_length == other.m_length);
        
    BV result(*this);
        
        
    for (int i = 0; i < m_cellCount; i++) {
        
        result.m_cells[i] = m_cells[i] & other.m_cells[i];
        
    }
    
    
    return result;
    
}



BV &BV::operator &= (const BV &other) {
    
    *this = *this & other;
        
    return *this;
    
}



BV BV::operator | (const BV &other) {
    
    assert(m_length == other.m_length);
        
    BV result(other);
    
    for (int i = 0; i < m_cellCount; i++) {
        
        result.m_cells[i] = m_cells[i] | other.m_cells[i];
        
    }
    
    return result;
    
}



BV &BV::operator |= (const BV &other) {
    
    *this = *this | other;
        
    return *this;
    
}



BV BV::operator ^ (const BV &other) {
    
    assert(m_length == other.m_length);
        
    BV result(other);
    
    for(int i = 0; i < m_cellCount; i++) {
        
        result.m_cells[i] = m_cells[i] ^ other.m_cells[i];
        
    }
    
    return result;
    
}



BV &BV::operator ^= (const BV &other) {
    
    *this = *this ^ other;
        
    return *this;
    
}



BV BV::operator << (const int value) {
    
    BV result(*this);
    
    result <<= value;
    
    return result;
    
}



BV &BV::operator <<= (int value) {
    
    assert (value >= 0 && value <= m_length);
    
        
    if (value >= 8) {
        
        for (int i = 0; i < m_cellCount - value / 8; i++) {
            
            m_cells[i] = m_cells[i + value / 8];
            
        }
        
        for (int i = 1; i <= value / 8; i++) {
            
            m_cells[m_cellCount - i] = 0;
            
        }
        
        value = value % 8;
        
    }
    

    if (value > 0) {
        
        uint8_t mask;
        
        for (int i = 0; i < m_cellCount; i++) {
            
            m_cells[i] <<= value;
            
            mask = m_cells[i + 1];
            
            mask >>= (8 - value);
            
            m_cells[i] |= mask;
            
        }
        
    }


    return *this;
    
}



BV BV::operator >> (const int value) {
    
    BV result(*this);
    
    result >>= value;

    return result;
    
}




BV &BV::operator >>= (int value) {
    
    assert (value >= 0 && value <= m_length);
        
    
    if (value >= 8) {
        
        for (int i = m_cellCount - 1; i >= 1; i--) {
            
            m_cells[i] = m_cells[i - value / 8];
            
        }
        
        for(int i = 0; i < value / 8; i++) {
            
            m_cells[i] = 0;
            
        }
        
        value = value % 8;
        
    }
    
    
    if (value > 0) {
        
        uint8_t mask;
        
        for(int i = m_cellCount - 1; i >= 0; i--) {
            
            m_cells[i] >>= value;
            
            mask = m_cells[i - 1];
            
            mask <<= (8 - value);
            
            m_cells[i] |= mask;
            
        }
        
    }
    
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
    
    return *this;
    
}



BV BV::operator ~ () {
    
    BV result (*this);
        
    for (int i = 0; i < m_cellCount; i++) {
        
        result.m_cells[i] = ~result.m_cells[i];
        
    }
    
    return result;
    
}



BV &BV::operator = (const BV &other) {
    
    if (this != &other) {
        
        
        delete [] m_cells;
        
        m_cells = new uint8_t [other.m_cellCount];
    
        
        for (int i = 0; i < m_cellCount; i++) {
            
            m_cells[i] = other.m_cells[i];
            
        }
        
        
        m_unsignificantRankCount = other.m_unsignificantRankCount;
        
        
        m_length = other.m_length;
        
        m_cellCount = other.m_cellCount;
        
        
        
        
            
        
        
        }
    
        
        return *this;
    
}






// Класс BoolRank //----------------------------------------------------------------------------------------------------------------------------------



BV::BoolRank& BV::BoolRank::operator = (const bool value) {
    
    if (value) {
        
        *m_cell |= m_mask;
        
    }
    
    else {
        
        *m_cell &= ~m_mask;
        
    }
    
    return *this;
    
}



BV::BoolRank& BV::BoolRank::operator = (const BV::BoolRank &other) {
    
    return *this = (bool) other;
    
}



bool BV::BoolRank::operator | (const bool value) const {
    
    return (bool) *this | value;
    
}



bool BV::BoolRank::operator & (const bool value) const {
    
    return (bool) *this & value;
    
}



bool BV::BoolRank::operator ~ () const {
    
    return !this->operator bool();
    
}



bool BV::BoolRank::operator ^ (const bool value) const {
    
    return (bool) *this ^ value;
    
}



bool BV::BoolRank::operator == (const bool value) const {
    
    return (bool) *this == value;
    
}



bool BV::BoolRank::operator == (const BV::BoolRank &other) const {
    
    return (*this == (bool) other);
    
}



BV::BoolRank::operator bool() const {
    
    if (m_mask & *m_cell) {
        
        return true;
    
    }
    
    else {
        
        return false;
        
    }
}
