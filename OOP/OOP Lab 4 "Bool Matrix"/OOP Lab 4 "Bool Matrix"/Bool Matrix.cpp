//
//  Bool Matrix.cpp
//  OOP Lab 4 "Bool Matrix"
//
//  Created by Antony Miroshnichenko on 15.11.2023.
//



#include <iostream>
#include <vector>
#include <assert.h>

#include "Bool Matrix.hpp"





BoolMatrix::BoolMatrix (int lineCount, int columnCount, int value) {
    
    assert(lineCount >= 0 && columnCount >= 0);
        
    m_line = new BoolVector [lineCount];
    
    m_lineCount = lineCount;
    m_columnCount = columnCount;
    
    BoolVector line (columnCount, value);
    
    for (int i = 0; i < lineCount; i++) {
        
        m_line[i] = line;
        
    }
    
}



BoolMatrix::BoolMatrix (char** matrix, const int lineCount, int columnCount) {
    
    assert(columnCount >= 0 && lineCount >= 0);
    
    m_line = new BoolVector [lineCount];
    
    m_lineCount = lineCount;
    m_columnCount = columnCount;
    
    for (int i = 0; i < m_lineCount; i++) {
        
        BoolVector line (columnCount, matrix[i]);
        
        m_line[i] = line;
        
    }
    
}



BoolMatrix::BoolMatrix (const BoolMatrix &other) {
    
    m_lineCount = other.m_lineCount;
    m_columnCount = other.m_columnCount;
    
    m_line = new BoolVector [m_lineCount];
    
    for (int i = 0; i < m_lineCount; i++) {
        
        m_line[i] = other.m_line[i];
        
    }
    
}



int BoolMatrix::lineCount() const {
    
    return m_lineCount;
    
}



int BoolMatrix::columnCount() const {
    
    return m_columnCount;
    
}



void BoolMatrix::swap (BoolMatrix &other) {
    
    std::swap(m_lineCount, other.m_lineCount);
    std::swap(m_columnCount, other.m_columnCount);
    
    for (int i = 0; i < m_lineCount; i++) {
        
        std::swap(m_line, other.m_line);
        
    }
    
}



int BoolMatrix::weight() const {
    
    int allWeight = 0;
    
    for (int i = 0; i < m_lineCount; i++) {
        
        allWeight += m_line -> weight();
        
    }
    
    return allWeight;
    
}



BoolVector BoolMatrix::conjunction() const {
    
    BoolVector result = m_line[0];
    
    for (int i = 1; i < m_lineCount; i++) {
        
        result &= m_line[i];
        
    }
    
    return result;
    
}



BoolVector BoolMatrix::disjunction() const {
    
    BoolVector result = m_line[0];
    
    for (int i = 1; i < m_lineCount; i++) {
        
        result |= m_line[i];
        
    }
    
    return result;
    
}



int BoolMatrix::weight (int j) const {
    
    assert(j >= 0 && j < m_lineCount);
    
    return m_line[j].weight();
    
}



void BoolMatrix::invert(int i, int j) {
    
    assert(j >= 0 && j < m_lineCount);
    
    assert(i >= 0 && i < m_columnCount);
    
    m_line[j].inverse(i);
    
}



void BoolMatrix::invertFrom (int i, int j, int k) {
    
    assert(j >= 0 && j < m_lineCount);
    
    assert(i >= 0 && i < m_columnCount);
    
    assert(i + k < m_columnCount);
    
    for (int index = i; index < i + k; index++) {
        
        m_line[j].inverse(index);
        
    }
    
}



void BoolMatrix::set (int i, int j, int value) {
    
    assert(j >= 0 && j < m_lineCount);
    
    assert(i >= 0 && i < m_columnCount);
    
    m_line[j].set(i, value);
    
}



void BoolMatrix::setFrom (int i, int j, int k, int value) {
    
    assert(j >= 0 && j < m_lineCount);
    
    assert(i >= 0 && i < m_columnCount);
    
    assert(i + k < m_columnCount);
    
    for (int index = i; index < i + k; index++) {
        
        m_line[j].set(index, value);
        
    }
    
}



BoolMatrix &BoolMatrix::operator = (const BoolMatrix &other) {
    
    
    if (this == &other) {
        
        return *this;
        
    }
    
    
    delete [] m_line;
    
    m_line = new BoolVector [other.m_lineCount];
    
    
    m_columnCount = other.m_columnCount;
    
    m_lineCount = other.m_lineCount;
    
    
    for (int j = 0; j < m_lineCount; j++) {
        
        m_line[j] = other.m_line[j];
        
    }
    
    
    return *this;
    
    
}



BoolVector &BoolMatrix::operator [] (const int j) {
    
    assert(j >= 0 && j < m_lineCount);
    
    return m_line[j];
    
}



const BoolVector &BoolMatrix::operator [] (const int j) const {
    
    assert(j >= 0 && j < m_lineCount);
    
    return m_line[j];
    
}



BoolMatrix BoolMatrix::operator & (const BoolMatrix &other) const {
    
    BoolMatrix result(*this);
    
    for (int j = 0; j < m_lineCount; j++) {
        
        result.m_line[j] &= other.m_line[j];
        
    }
    
    return result;
    
}



BoolMatrix &BoolMatrix::operator &= (const BoolMatrix &other) {
    
    *this = *this & other;
    
    return *this;
    
}

BoolMatrix BoolMatrix::operator | (const BoolMatrix &other) const {
    
    BoolMatrix result(*this);
    
    for (int j = 0; j < m_lineCount; j++) {
        
        result.m_line[j] |= other.m_line[j];
        
    }
    
    return result;
    
}



BoolMatrix &BoolMatrix::operator |= (const BoolMatrix &other) {
    
    *this = *this | other;
    
    return *this;
    
}



BoolMatrix BoolMatrix::operator ^ (const BoolMatrix &other) const {
    
    BoolMatrix result(*this);
    
    for (int j = 0; j < m_lineCount; j++) {
        
        result.m_line[j] ^= other.m_line[j];
        
    }
    
    return result;
    
}



BoolMatrix &BoolMatrix::operator ^= (const BoolMatrix &other) {
    
    *this = *this ^ other;
    
    return *this;
    
}



BoolMatrix BoolMatrix::operator ~ () {
    
    BoolMatrix result(*this);
    
    for (int j = 0; j < m_lineCount; j++) {
        
        result.m_line[j] = ~result.m_line[j];
        
    }
    
    return result;
    
}





std::istream &operator >> (std::istream &stream, BoolMatrix &object) {
    
    for (int j = 0; j < object.lineCount(); j++) {
        
        stream >> object.m_line[j];
        
    }
    
    return stream;
    
}



std::ostream &operator << (std::ostream &stream, const BoolMatrix &object) {
    
    
    
    for (int j = 0; j < object.lineCount(); j++) {
        
        stream << "[" << object[j][0];
        
        for (int i = 1; i < object.lineCount(); i++) {
            
            stream << " " << object[j][i];
            
        }
        
        stream << "]" << std::endl;
        
    }
    
    return stream;
    
}
