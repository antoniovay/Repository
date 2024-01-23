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
    
    
    /*
    List<int> list1 = List<int>(5, 1);
    List<int> list2 = List<int>(10, -1);
    
    List<int> list = list1 + list2;
    
    list.enter();
    
    list.info();
    //list.print();
    
    list.sort();
    
    list.info();
    //list.print();
    */
    
    
    /*
    List<int> list1(5, 1);
    List<int> list2(5, 2);
    List<int> list3(10, 1);
    List<int> list4(5, 1);
    
     std::cout << (list1 == list1);
     std::cout << (list1 == list2);
     std::cout << (list1 == list3);
     std::cout << (list1 == list4);
     std::cout << (list1 == list1);
     std::cout << (list2 == list1);
     std::cout << (list3 == list1);
     std::cout << (list4 == list1);
     std::cout << std::endl;
    */
    
    
    
    List<std::string> list1(3);
    
    std::cout << list1.size();
    std::cin >> list1;
    
    std::cout << list1;
    
    
}
