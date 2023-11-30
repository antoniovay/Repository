//
//  List.hpp
//  OOP Lab 5 "List"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#pragma once



#include <iostream>
#include <assert.h>
#include <vector>

#include "Array.hpp"



class Node
{
    
    int key;
    Node *next = nullptr;
    
};



template <typename ItemType>

class List
{
    
public:
    
    // Методы //-------------------------------------------------------------------------------------------------------------------------------------
    
    List(const int size = 10, const ItemType value = 0); // Конструктор по умолчанию
    List(Array<ItemType> &other); // Конструктор из Array
    List(const List &other); // Конструктор копирования
    
    ~List() { // Деструктор
        
        clear();
        
        delete head;
        
    }
    
    int size(); // Получение размера
    
    void swap(List &other);
    
    Node *findKey(int key); // Поиск в списке по ключу.
    Node *findPos(int pos); // Поиск в списке по позиции pos
    
    void addToHead (int key); // Добавление элемента в голову списка
    void addToTail (int key); // Добавление элемента в хвост списка
    void addAfter (int key, int pos); // Добавление элемента после заданного
    void addAfterValue (int key); // Добавление элемента после равного key
    
    void delHead (); // Удаление головы
    void delTail (); // Удаление хвоста
    void delAfter (int pos) ; // Удаление элемента после заданного узла
    void delFirstValue(int key); // Удаление элемента равного key
    
    int maxElement();
    int minElement();
    
    bool isEmpty(); // Проверка пустоты списка
    
    void clear(); // Очистка списка
    
    
    // Перегрузки //---------------------------------------------------------------------------------------------------------------------------------
    
    
private:
    
    Node *head;
    
};









template <typename ItemType>

List<ItemType>::List(const int size, const ItemType value) {
    
    
    
}



template <typename ItemType>

List<ItemType>::List(Array<ItemType> &other) {
    
    
    
}



template <typename ItemType>

List<ItemType>::List(const List &other) {
    
    
    
}



template <typename ItemType>

int size() {
    
    
    
}
