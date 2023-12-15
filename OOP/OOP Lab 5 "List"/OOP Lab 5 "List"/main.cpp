//
//  main.cpp
//  OOP Lab 5 "List"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#include <iostream>

#include "List.hpp"



int main() {
    
    List<int> list(23, 10000);
    List<int> list2(2, 1);
    
    
    std::cout << "list:" << std::endl;
    std::cout << list.size() << std::endl << list.maxElement() << std::endl << list.isEmpty() << std::endl << std::endl;
    std::cout << "list2:" << std::endl;
    std::cout << list2.size() << std::endl << list2.maxElement() << std::endl << list2.isEmpty() << std::endl << std::endl;
    
    //list.clear();
    
    //list.swap(list2);
    
    std::cout << std::endl;
    
    
    
    
    std::cout << "list:" << std::endl;
    std::cout << list.size() << std::endl << list.maxElement() << std::endl << list.isEmpty() << std::endl << std::endl;
    std::cout << "list2:" << std::endl;
    std::cout << list2.size() << std::endl << list2.maxElement() << std::endl << list2.isEmpty() << std::endl << std::endl;
    
    
}
