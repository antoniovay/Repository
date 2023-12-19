//
//  Set.cpp
//  OOP Lab 6 "Set"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#include "Set.hpp"



class Set: public BoolVector
{
    
public:
    
    Set(int size, const char chr = '*');
    Set(const char* arr);
    Set(const Set &other);
    
    ~Set() {
        
        delete [] m_set;
        
    }
    
    
    
private:
    
    BoolVector* m_set = nullptr;
    
    
};
