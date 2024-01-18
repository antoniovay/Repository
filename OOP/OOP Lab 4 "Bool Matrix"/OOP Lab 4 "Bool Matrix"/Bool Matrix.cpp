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





BoolMatrix::BoolMatrix (const int columnCount, const int lineCount, const bool value) {
    
    assert(lineCount >= 0 && columnCount >= 0);
        
    m_line = new BoolVector [columnCount];
    
    m_lineCount = columnCount;
    m_columnCount = lineCount;
    
    BoolVector line (lineCount, value);
    
    for (int i = 0; i < columnCount; i++) {
        
        m_line[i] = line;
        
    }
    
}



BoolMatrix::BoolMatrix (char** matrix, const int columnCount, int lineCount) {
    
    assert(columnCount >= 0 && lineCount >= 0);
    
    m_line = new BoolVector [columnCount];
    
    m_lineCount = columnCount;
    m_columnCount = lineCount;
    
    for (int i = 0; i < m_lineCount; i++) {
        
        BoolVector line (matrix[i]);
        
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
    
    return m_columnCount;
    
}



int BoolMatrix::columnCount() const {
    
    return m_lineCount;
    
}



void BoolMatrix::swap (BoolMatrix &other) {
    
    std::swap(m_lineCount, other.m_lineCount);
    std::swap(m_columnCount, other.m_columnCount);
    
    std::swap(m_line, other.m_line);
    
}



int BoolMatrix::weight() const {
    
    int allWeight = 0;
    
    for (int i = 0; i < m_lineCount; i++) {
        
        allWeight += m_line -> weight();
        
    }
    
    return allWeight;
    
}



BoolVector BoolMatrix::conjunction() const {
    
    assert(m_lineCount > 0);
    
    BoolVector result = m_line[0];
    
    for (int i = 1; i < m_lineCount; i++) {
        
        result &= m_line[i];
        
    }
    
    return result;
    
}



BoolVector BoolMatrix::disjunction() const {
    
    assert(m_lineCount > 0);
    
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



void BoolMatrix::invert(const int row, const int column) {
    
    assert(row >= 0 && row < m_lineCount);
    
    assert(column >= 0 && column < m_columnCount);
    
    m_line[row].inverse(column);
    
}



void BoolMatrix::invert (const int row, const int start, const int k) {
    
    assert(row >= 0 && row < m_lineCount);
    
    assert(start >= 0 && start < m_columnCount);
    
    assert(start + k < m_columnCount);
    
    for (int i = start; i < start + k - 1; i++) {
        
        m_line[row].inverse(i);
        
    }
    
}



void BoolMatrix::set (const int row, const int column, const int value) {
    
    assert(row >= 0 && row < m_lineCount);
    
    assert(column >= 0 && column < m_columnCount);
    
    m_line[row].set(column, value);
    
}



void BoolMatrix::set (const int row, const int start, const int k, const int value) {
    
    assert(row >= 0 && row < m_lineCount);
    
    assert(start >= 0 && start < m_columnCount);
    
    assert(start + k < m_columnCount);
    
    m_line[row].setAfterK(start, k, value);
    
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



BoolMatrix BoolMatrix::operator ~ () const {
    
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
