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



