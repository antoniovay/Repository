//
//  main.cpp
//  OOP Lab 6 "Set"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#include "Set.hpp"



int main() {
    
    
    
    Set set1, set2;
    
    set1 += 'a';
    set1 += 'b';
    set1 += 'c';
    set1 += 'd';
    set1 += 'e';
    /*
    set2 += 'f';
    set2 += 'b';
    set2 += 'c';
    set2 += 'g';
    set2 += 'h';
    
    std::cout << set1.power() << std::endl;
    
    set2 &= set1;
    
    std::cout << set1;
    std::cout << set2;
    
    std::cout << std::endl;
    
    Set set3, set4;
    
    set3 = set3 + 'a';
    set3 += 'b';
    set3 += 'c';
    set3 += 'd';
    set3 += 'e';
    
    std::cout << set3;
    
    set4 = ~set3;
    
    std::cout << set4;
    
    set3.inverse();
    
    std::cout << set3;
    
     
    //Set set5;
    */
    std::cin >> set1;
    
    std::cout << set1;
    
    std::cout << set1.power() << std::endl;
    
    
}
