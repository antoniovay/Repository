//
//  Set.cpp
//  OOP Lab 6 "Set"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#include "Set.hpp"



// Символы с кодами до 31 //--------------------------------------------------------------------------------------------------------------------------

const std::vector<std::string> Set::SPECIAL_SYMBOLS
{
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS", "TAB", "LF", "VT", "FF", "CR", "SO", "SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US"
};



// Конструкторы //------------------------------------------------------------------------------------------------------------------------------------



Set::Set (const char* arr) : BoolVector(MAX_CODE) {
    
    for (int i = 0; arr[i] != '\0'; i++) {
        
        *this += arr[i];
        
    }

}



Set::Set (const Set &other) : BoolVector(other)

{}



// Методы //------------------------------------------------------------------------------------------------------------------------------------------



bool Set::is_in_set(const char value) const {
    
    if ((unsigned int) value >= MAX_CODE)
        
        return false;
    
    return operator [] ((int) value);
    
}



char Set::max()  const {
    
    for (int i = MAX_CODE - 1; i >= 0; i--) {
        
        if (operator[](i))
            
            return (char) i;
        
    }
    
    return (char) 0;
    
}



char Set::min() const {
    
    for (int i = 0; i < MAX_CODE; i++) {
        
        if (operator[](i))
            
            return (char) i;
        
    }
    
    return (char) 0;
    
}



int Set::power() {
    
    return weight();
    
}



// Перегрузки //--------------------------------------------------------------------------------------------------------------------------------------



Set &Set::operator = (const Set &other) {
    
    BoolVector::operator = (other);
    
    return *this;
    
}




bool Set::operator == (const Set &other) const {
    
    return BoolVector::operator == (other);
    
}




bool Set::operator != (const Set &other) const {
    
    return !(*this == other);
    
}




Set Set::operator | (const Set &object) const {
    
    Set result(*this);
    
    result |= object;
    
    return result;
    
}




Set &Set::operator |= (const Set &object) {
    
    BoolVector::operator |= (object);
    
    return *this;
    
}




Set Set::operator & (const Set &object) const {
    
    Set result(*this);
    
    result &= object;
    
    return result;
    
}




Set &Set::operator &= (const Set &object) {
    
    BoolVector::operator &= (object);
    
    return *this;
    
}




Set Set::operator / (const Set &object) const {
    
    Set result(*this);
    
    result /= object;
    
    return result;
    
}




Set &Set::operator /= (const Set &object) {
    
    BoolVector::operator &= (~object);
    
    return *this;
    
}




Set Set::operator ~ () const {
    
    Set result(*this);
    
    result.inverse();
        
    return result;

}




Set Set::operator + (const char value) const {
    
    Set result(*this);
    
    result += value;
    
    return result;
    
}




Set &Set::operator += (const char value) {
    
    if (value >= 0 && value < MAX_CODE)
                
        operator [] ((int) value) = true;
        
    return *this;
    
}




Set Set::operator - (const char value) const {
    
    Set result(*this);
    
    result -= value;
    
    return result;
    
}




Set &Set::operator -= (const char value) {
    
    if (value >= 0 && value < MAX_CODE)
                
        operator [] ((int) value) = false;
        
    return *this;
    
}




// Потоковый ввод-вывод //----------------------------------------------------------------------------------------------------------------------------



std::ostream &operator << (std::ostream& stream, const Set &other) {
    
    stream << "{";
    
    bool wasPrint = false;
    
    for (int i = 0; i < Set::MAX_CODE; i++) {
        
        if ( other.is_in_set((char) i) ) 
        
        {
            
            stream << (wasPrint ? ", " : "");
            
            
            if (i < Set::SPECIAL_SYMBOLS.size())
                
                stream << Set::SPECIAL_SYMBOLS[i];
            
            else
                
                stream << (char) i;
            
            
            wasPrint = true;
            
        }
        
    }
    
    stream << "}";
    stream << std::endl;
    
    return stream;
    
}




std::istream& operator >> (std::istream& stream, Set& other) {
    
    
    
}

