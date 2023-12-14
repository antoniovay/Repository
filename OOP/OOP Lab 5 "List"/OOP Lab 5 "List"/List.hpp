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



template <typename ItemType>

class Node
{
    
    
    
    ItemType key;
    Node *next = nullptr;
    
};



template <typename ItemType>

class List
{
    
public:
    
    
    
    // Методы //-------------------------------------------------------------------------------------------------------------------------------------
    
    List(); // Конструктор пустого списка
    List(const int size = 10, const ItemType value = 0); // Конструктор по умолчанию
    List(Array<ItemType> &other); // Конструктор из Array
    List(const List &other); // Конструктор копирования
    
    ~List() { // Деструктор
        
        clear();
        
        delete m_head;
        
    }
    
    int size(); // Получение размера
    
    void swap(List &other);
    
    Node<ItemType> *findKey(ItemType key); // Поиск в списке по ключу.
    Node<ItemType> *findPos(int pos); // Поиск в списке по позиции pos
    
    void addToHead (ItemType key); // Добавление элемента в голову списка
    void addToTail (ItemType key); // Добавление элемента в хвост списка
    void addAfter (ItemType key, Node<ItemType> *pos); // Добавление элемента после заданного
    void addAfterValue (ItemType key); // Добавление элемента после равного key
    
    void delHead (); // Удаление головы
    void delTail (); // Удаление хвоста
    void delAfter (Node<ItemType> *pos) ; // Удаление элемента после заданного узла
    void delFirstValue(ItemType key); // Удаление элемента равного key
    
    int maxElement();
    int minElement();
    
    bool isEmpty(); // Проверка пустоты списка
    
    void clear(); // Очистка списка
    
    
    // Перегрузки //---------------------------------------------------------------------------------------------------------------------------------
    
    
private:
    
    Node<ItemType> *m_head;
    
};









template <typename ItemType>

List<ItemType>::List() {
    
    m_head = new Node<ItemType>;
    
    m_head->next = 0;
    
}



template <typename ItemType>

List<ItemType>::List(const int size, const ItemType value) {
    
    m_head = new Node<ItemType>;
    
    for (int i = size; i > 0; i++) {
        
        addAfter(value, m_head);
        
    }
    
}



template <typename ItemType>

List<ItemType>::List(Array<ItemType> &other) {
    
    
    
}



template <typename ItemType>

List<ItemType>::List(const List &other) {
    
    
    
}



template <typename ItemType>

int List<ItemType>::size() {
    
    int size = 0;
    
    Node<ItemType> *p = m_head;
    
    while (p->next)
        
        size++;
    
    return size;
    
}



template <typename ItemType>

void List<ItemType>::swap(List &other) {
    
    std::swap(m_head, other.head);
    
}



template <typename ItemType>

Node<ItemType> *List<ItemType>::findKey(ItemType key) {
    
    if (m_head->next->key == key) 
        
        return m_head;
    
    
    Node<ItemType> *p=m_head->next;
    
    while (p->next != nullptr && p->next->key != key)
        
        p=p->next;
    
    if (p->next == nullptr)
        
        return nullptr;
    
    else return p;
    
}



template <typename ItemType>

Node<ItemType> *List<ItemType>::findPos(int pos) {
    
    Node<ItemType> *p = m_head->next;
    
    int i = 1;
    
    while ((p->next != nullptr) && (i < pos-1)) {
        
        i++;
        
        p=p->next;
        
    }
    
    assert(p->next != nullptr);
    
    return p;
    
}



template <typename ItemType>

void List<ItemType>::addToHead (ItemType key) {
    
    addAfter (key, m_head);
    
}



template <typename ItemType>

void List<ItemType>::addToTail (ItemType key) {
    
    Node<ItemType> *p = m_head;
    
    while (p->next) 
        
        p=p->next;
    
    AddAfter(key, p);
    
}



template <typename ItemType>

void List<ItemType>::addAfter (ItemType key, Node<ItemType> *pos) {
    
    Node<ItemType> *q = new Node<ItemType>;
    
    q->key = key;
    
    q->next = pos->next;
    
    pos->next = q;
    
}



template <typename ItemType>

void List<ItemType>::addAfterValue (ItemType key) {
    
    addAfter(key, findKey(key));
    
}



template <typename ItemType>

void List<ItemType>::delHead () {
    
    delAfter (m_head);
    
}



template <typename ItemType>

void List<ItemType>::delTail () {
    
    assert(m_head->next != nullptr);
    
    
    Node<ItemType> *p = m_head;
            
    while (p->next->next != 0) p = p->next;
    
    delAfter (p);
    
}



template <typename ItemType>

void List<ItemType>::delAfter (Node<ItemType> *pos) {
    
    assert(pos->next != nullptr);
    
    
    Node<ItemType> *q = pos->next;
    
    pos->next = q->next;
    
    delete q;
    
}



template <typename ItemType>

void List<ItemType>::delFirstValue(ItemType key) {
    
    delAfter(findKey(key));
    
}



template <typename ItemType>

int List<ItemType>::maxElement() {
    
    ItemType maxElem = m_head->key;
    
    Node<ItemType> *p = m_head->next;
    
    while (p->next != nullptr) {
        
        if (p->key > maxElem)
            
            maxElem = p->key;
        
    }
    
}



template <typename ItemType>

int List<ItemType>::minElement() {
    
    ItemType maxElem = m_head->key;
    
    Node<ItemType> *p = m_head->next;
    
    while (p->next != nullptr) {
        
        if (p->key < maxElem)
            
            maxElem = p->key;
        
    }
    
}



template <typename ItemType>

bool List<ItemType>::isEmpty() {
    
    if (m_head->next == nullptr)
        
        return true;
    
    return false;
    
}



template <typename ItemType>

void List<ItemType>::clear() {
    
    while (m_head->next) 
        
        delHead ();
    
}
