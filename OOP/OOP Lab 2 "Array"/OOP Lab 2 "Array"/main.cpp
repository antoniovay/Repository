//
//  main.cpp
//  OOP Lab 2 "Array"
//
//  Created by Antony Miroshnichenko on 17.10.2023.
//



#include <iostream>
#include <assert.h>
#include <string>

#include "Array.hpp"



int main() {
    
    
    int mas[10] = {0};
    
    Array<int> arr(10, mas);
    
    std::cout << arr << std::endl;
    
    
    const char  s[10] = "qwertyuio";
    
    Array<std::string> str(10, s);
        
    std::cout << str << std::endl;
    
    
}
