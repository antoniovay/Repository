//
//  main.cpp
//  AaDS Lab 7 "Topological sort"
//
//  Created by Antony Miroshnichenko on 01.12.2023.
//



#include "Funcs.hpp"



int main() 
{
    
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    std::cout << "Topological sorted graph is: ";
    
    g.topologicalSort();
    
    std::cout << std::endl;

}
