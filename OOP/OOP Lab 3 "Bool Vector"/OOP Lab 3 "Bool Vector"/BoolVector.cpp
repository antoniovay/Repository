//
//  BV.cpp
//  OOP Lab 3 "Bool Vector"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//





#include "BoolVector.hpp"



BoolVector::BoolVector (const int length) {
    
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



BoolVector::BoolVector (const int length, const int value) {
    
    assert(length >= 0);
    
    m_cellCount = length / 8 + (length % 8 != 0);
    
    
    m_cells = new uint8_t [m_cellCount];
    
    
    for (unsigned int i = 0; i < m_cellCount; i++) {
        
        if (value)
            
            m_cells[i] = 255;
        
        else
            
            m_cells[i] = 0;
        
    }
    
    
    m_unsignificantRankCount = m_cellCount * 8 - length;
    
    
    m_length = length;
    
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}



BoolVector::BoolVector (const char* array) {
    
    assert (strlen(array) >= 0);
    
    m_length = (int) strlen(array);
    
    m_cellCount = m_length / 8 + (m_length % 8 != 0);
    
    
    m_cells = new uint8_t [m_cellCount];
    
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = array[i];
        
    }
    
    
    m_unsignificantRankCount = (m_cellCount * 8) - m_length;
    
}



BoolVector::BoolVector (const BoolVector &other) {
    
    m_cells = new uint8_t [other.m_cellCount];
    
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = other.m_cells[i];
        
    }
    
    
    m_unsignificantRankCount = other.m_unsignificantRankCount;
    
    
    m_length = other.m_length;
    
    m_cellCount = other.m_cellCount;
    
}









int BoolVector::length () const {
    
    return m_length;
    
}



void BoolVector::swap (BoolVector &bv) {
    
    std::swap (m_length, bv.m_length);
    std::swap (m_cellCount, bv.m_cellCount);
    std::swap (m_unsignificantRankCount, bv.m_unsignificantRankCount);
    std::swap (m_cells, bv.m_cells);
    
}



void BoolVector::inverse () {
    
    for (int i = 0; i < m_cellCount; i++) {
        
        m_cells[i] = ~m_cells[i];
        
    }
    
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}



void BoolVector::inverse (const int i) {
    
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



void BoolVector::set (const int i, const bool x) {
    
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



void BoolVector::setAfterK (const int i, const int k, const bool x) {
    
    assert(i >= 0 && i + k < m_length && k > 0);
    
    for (int it = i; it <= i + k - 1; it++) {
        
            (*this)[it] = x;
        
    }
    
}



void BoolVector::setAll (const bool x) {
    
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



int BoolVector::weight() const {
    
    int weight = 0;
    
    for (int i = 0; i < m_cellCount; i++) {
        
        for (uint8_t mask = 1 << 7; mask != 0; mask >>= 1) {
            
            if(m_cells[i] & mask)
                
                weight++;
            
        }
        
    }
    
    return weight;
    
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



BoolVector::BoolRank BoolVector::operator [] (const int i) {
    
    assert(i >= 0 && i < m_length);
    
    return BoolRank (m_cells + i / 8, i % 8);
    
}

const BoolVector::BoolRank BoolVector::operator [] (const int i) const {
    
    assert(i >= 0 && i < m_length);
    
    return BoolRank (m_cells + i / 8, i % 8);
    
}



BoolVector BoolVector::operator & (const BoolVector &other) const {
    
    assert (m_length == other.m_length);
        
    BoolVector result(*this);
        
        
    for (int i = 0; i < m_cellCount; i++) {
        
        result.m_cells[i] = m_cells[i] & other.m_cells[i];
        
    }
    
    
    return result;
    
}



BoolVector &BoolVector::operator &= (const BoolVector &other) {
    
    *this = *this & other;
        
    return *this;
    
}



BoolVector BoolVector::operator | (const BoolVector &other) const {
    
    assert(m_length == other.m_length);
        
    BoolVector result(other);
    
    for (int i = 0; i < m_cellCount; i++) {
        
        result.m_cells[i] = m_cells[i] | other.m_cells[i];
        
    }
    
    return result;
    
}



BoolVector &BoolVector::operator |= (const BoolVector &other) {
    
    *this = *this | other;
        
    return *this;
    
}



BoolVector BoolVector::operator ^ (const BoolVector &other) const {
    
    assert(m_length == other.m_length);
        
    BoolVector result(other);
    
    for(int i = 0; i < m_cellCount; i++) {
        
        result.m_cells[i] = m_cells[i] ^ other.m_cells[i];
        
    }
    
    return result;
    
}



BoolVector &BoolVector::operator ^= (const BoolVector &other) {
    
    *this = *this ^ other;
        
    return *this;
    
}



BoolVector BoolVector::operator << (const int value) const {
    
    BoolVector result(*this);
    
    result <<= value;
    
    return result;
    
}



BoolVector &BoolVector::operator <<= (int value) {
    
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



BoolVector BoolVector::operator >> (const int value) const {
    
    BoolVector result(*this);
    
    result >>= value;

    return result;
    
}




BoolVector &BoolVector::operator >>= (int value) {
    
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



BoolVector BoolVector::operator ~ () const {
    
    BoolVector result (*this);
        
    for (int i = 0; i < m_cellCount; i++) {
        
        result.m_cells[i] = ~result.m_cells[i];
        
    }
    
    result.m_cells[m_cellCount - 1] >>= result.m_unsignificantRankCount;
    result.m_cells[m_cellCount - 1] <<= result.m_unsignificantRankCount;
    
    return result;
    
}



BoolVector &BoolVector::operator = (const BoolVector &other) {
    
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



bool BoolVector::operator == (const BoolVector& other) const {
    if(m_length != other.m_length)
        return false;
    
    for(int i = 0; i < m_cellCount; ++i)
        if(m_cells[i] != other.m_cells[i]) {
            return false;
        }
    return true;
}



bool BoolVector::operator != (const BoolVector& other) const {
    
    return !(*this == other);
    
}







// Класс BoolRank //----------------------------------------------------------------------------------------------------------------------------------



BoolVector::BoolRank& BoolVector::BoolRank::operator = (const bool value) {
    
    if (value) {
        
        *m_cell |= m_mask;
        
    }
    
    else {
        
        *m_cell &= ~m_mask;
        
    }
    
    return *this;
    
}



BoolVector::BoolRank& BoolVector::BoolRank::operator = (const BoolVector::BoolRank &other) {
    
    return *this = (bool) other;
    
}



bool BoolVector::BoolRank::operator | (const bool value) const {
    
    return (bool) *this | value;
    
}



bool BoolVector::BoolRank::operator & (const bool value) const {
    
    return (bool) *this & value;
    
}



bool BoolVector::BoolRank::operator ~ () const {
    
    return !this->operator bool();
    
}



bool BoolVector::BoolRank::operator ^ (const bool value) const {
    
    return (bool) *this ^ value;
    
}



bool BoolVector::BoolRank::operator == (const bool value) const {
    
    return (bool) *this == value;
    
}



bool BoolVector::BoolRank::operator == (const BoolVector::BoolRank &other) const {
    
    return (*this == (bool) other);
    
}



BoolVector::BoolRank::operator bool() const {
    
    if (m_mask & *m_cell) {
        
        return true;
    
    }
    
    else {
        
        return false;
        
    }
}





// Потоковые ввод и вывод //--------------------------------------------------------------------------------------------------------------------------



std::istream &operator >> (std::istream &stream, BoolVector& bv) { // Потоковый ввод
    
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



std::ostream &operator << (std::ostream &stream, const BoolVector& bv) { // Потоковый вывод
    
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
