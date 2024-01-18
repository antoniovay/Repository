//
//  main.cpp
//  OOP Lab 3 "Bool Vector"
//
//  Created by Antony Miroshnichenko on 07.11.2023.
//




#include "BoolVector.hpp"



int main() {
    
    BoolVector x(30, 1);
    
    std::cout << x;
    
    std::cout << x.length() << std::endl;
    
    x.setAfterK(5, 4, 0);
    
    std::cout << x;
    
}
