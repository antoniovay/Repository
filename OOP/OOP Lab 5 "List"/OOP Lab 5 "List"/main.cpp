//
//  main.cpp
//  OOP Lab 5 "List"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#include <iostream>

#include "List.hpp"



int main() {
    
    //Array<int> array = Array(10, 10);
    //List<int> list1 = List<int>(1, 10000);
    //List<int> list2 = List(array);
    //List<int> list = list2;
    
    
    List<int> list1 = List<int>(5, 1);
    List<int> list2 = List<int>(10, -1);
    
    List<int> list = list1 + list2;
    
    list.enter();
    
    list.info();
    list.print();
    
    list.sort();
    
    list.info();
    list.print();
    
}
