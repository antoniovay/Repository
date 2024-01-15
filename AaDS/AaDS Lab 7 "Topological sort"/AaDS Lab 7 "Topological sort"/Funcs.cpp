//
//  Funcs.cpp
//  AaDS Lab 7 "Topological sort"
//
//  Created by Antony Miroshnichenko on 01.12.2023.
//



#include "Funcs.hpp"


Graph::Graph(int V) {
    
    this->V = V;
    
    adj = new std::list<int>[V];
    
}



void Graph::addEdge(int u, int v) {
    
    adj[u].push_back(v);
    
}



void Graph::topologicalSortUtil(int v, std::vector<bool>& visited, std::vector<int>& stack) {
    
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        
        if (!visited[*i]) {
            
            topologicalSortUtil(*i, visited, stack);
            
        }
        
    }
    
    stack.push_back(v);
    
}



void Graph::topologicalSort() {
    
    std::vector<bool> visited(V, false);
    std::vector<int> stack;

    
    for (int i = 0; i < V; i++) {
        
        if (!visited[i]) {
            
            topologicalSortUtil(i, visited, stack);
            
        }
        
    }

    
    while (!stack.empty()) {
        
        std::cout << stack.back() << " ";
        
        stack.pop_back();
        
    }
    
}
