//
//  main.cpp
//  OOP Lab 5 "List"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#include <iostream>

#include "List.hpp"



int main() {
    
    List<int> list = List<int>(1, 10000);
    
    list.enter();
    
    
    std::cout << "LIST_DATA:" << std::endl;
    std::cout << "size: " << list.size() << std::endl;
    std::cout << "max: " << list.max() << std::endl;
    std::cout << "min: " << list.min() << std::endl;
    std::cout << "empty?: " << list.empty() << std::endl;
    
    std::cout << std::endl;
    
    list.print();
    
}
