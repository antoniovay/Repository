//
//  Funcs.hpp
//  AaDS Lab 7 "Topological sort"
//
//  Created by Antony Miroshnichenko on 01.12.2023.
//



#pragma once



#include <iostream>
#include <list>

//#include "List.hpp"



class Graph {

    int V;
    std::list<int>* adj;

    
public:
    
    Graph(int V);
    
    void addEdge(int u, int v);
    void topologicalSortUtil(int v, std::vector<bool>& visited, std::vector<int>& stack);
    void topologicalSort();
    
};
