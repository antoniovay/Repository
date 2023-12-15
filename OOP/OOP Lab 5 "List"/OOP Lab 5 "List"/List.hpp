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

class List
{
    
public:
    
    class Node;
    
    friend std::ostream &operator << (std::ostream &stream, const List<ItemType> &other);
    friend std::istream &operator >> (std::istream &stream, List<ItemType> &other);
    
    
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
    
    List<ItemType>::Node *findKey(ItemType key); // Поиск в списке по ключу.
    List<ItemType>::Node *findPos(int pos); // Поиск в списке по позиции pos
    
    void addToHead (ItemType key); // Добавление элемента в голову списка
    void addToTail (ItemType key); // Добавление элемента в хвост списка
    void addAfter (ItemType key, Node *pos); // Добавление элемента после заданного
    void addAfterValue (ItemType key); // Добавление элемента после равного key
    
    void delHead (); // Удаление головы
    void delTail (); // Удаление хвоста
    void delAfter (Node *pos) ; // Удаление элемента после заданного узла
    void delFirstValue(ItemType key); // Удаление элемента равного key
    
    ItemType maxElement();
    ItemType minElement();
    
    bool isEmpty(); // Проверка пустоты списка
    
    void clear(); // Очистка списка
    
    
    // Перегрузки //---------------------------------------------------------------------------------------------------------------------------------
    
    
private:
    
    Node *m_head;
    
};





template <typename ItemType>

class List<ItemType>::Node
{
    
    friend std::ostream &operator << (std::ostream &stream, const List<ItemType> &other);
    friend std::istream &operator >> (std::istream &stream, List<ItemType> &other);
    
    friend class List;
    
    ItemType m_key;
    Node *m_next = nullptr;
    
};








template <typename ItemType>

List<ItemType>::List() {
    
    m_head = new Node;
    
    
    
    m_head->m_next = 0;
    
}



template <typename ItemType>

List<ItemType>::List(const int size, const ItemType value) {
    
    m_head = new Node;
    
    for (int i = size; i > 0; i--) {
        
        addToTail(value);
        
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
    
    Node *p = m_head;
    
    while (p->m_next) {
        
        size++;
        
        p = p->m_next;
        
    }
    
    return size;
    
}



template <typename ItemType>

void List<ItemType>::swap(List &other) {
    
    std::swap(m_head, other.m_head);
    
}



template <typename ItemType>

List<ItemType>::Node *List<ItemType>::findKey(ItemType key) {
    
    if (m_head->m_next->m_key == key)
        
        return m_head;
    
    
    Node *p=m_head->m_next;
    
    while (p->m_next != nullptr && p->m_next->m_key != key)
        
        p=p->m_next;
    
    if (p->m_next == nullptr)
        
        return nullptr;
    
    else return p;
    
}



template <typename ItemType>

List<ItemType>::Node *List<ItemType>::findPos(int pos) {
    
    Node *p = m_head->m_next;
    
    int i = 1;
    
    while ((p->m_next != nullptr) && (i < pos-1)) {
        
        i++;
        
        p=p->m_next;
        
    }
    
    assert(p->m_next != nullptr);
    
    return p;
    
}



template <typename ItemType>

void List<ItemType>::addToHead (ItemType key) {
    
    addAfter (key, m_head);
    
}



template <typename ItemType>

void List<ItemType>::addToTail (ItemType key) {
    
    Node *p = m_head;
    
    while (p->m_next)
        
        p=p->m_next;
    
    addAfter(key, p);
    
}



template <typename ItemType>

void List<ItemType>::addAfter (ItemType key, Node *pos) {
    
    Node *q = new Node;
    
    q->m_key = key;
    
    q->m_next = pos->m_next;
    
    pos->m_next = q;
    
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
    
    assert(m_head->m_next != nullptr);
    
    
    Node *p = m_head;
            
    while (p->m_next->m_next != 0) p = p->m_next;
    
    delAfter (p);
    
}



template <typename ItemType>

void List<ItemType>::delAfter (Node *pos) {
    
    assert(pos->m_next != nullptr);
    
    
    Node *q = pos->m_next;
    
    pos->m_next = q->m_next;
    
    delete q;
    
}



template <typename ItemType>

void List<ItemType>::delFirstValue(ItemType key) {
    
    delAfter(findKey(key));
    
}



template <typename ItemType>

ItemType List<ItemType>::maxElement() {
    
    if (m_head->m_next == nullptr)
        
        return 404;
    
    ItemType maxElem = m_head->m_key;
    
    Node *p = m_head->m_next;
    
    while (p->m_next != nullptr) {
        
        if (p->m_key > maxElem)
            
            maxElem = p->m_key;
        
        p = p->m_next;
        
    }
    
    return maxElem;
    
}



template <typename ItemType>

ItemType List<ItemType>::minElement() {
    
    if (m_head->m_next == nullptr)
        
        return 404;
    
    ItemType minElem = m_head->m_key;
    
    Node *p = m_head->m_next;
    
    while (p->m_next != nullptr) {
        
        if (p->m_key < minElem)
            
            minElem = p->m_key;
        
        p = p->m_next;
        
    }
    
    return minElem;
    
}



template <typename ItemType>

bool List<ItemType>::isEmpty() {
    
    if (m_head->m_next == nullptr)
        
        return true;
    
    return false;
    
}



template <typename ItemType>

void List<ItemType>::clear() {
    
    while (m_head->m_next)
        
        delHead ();
    
}



/*

template <typename ItemType>

std::ostream &operator << (std::ostream &stream, const List<ItemType> &other) {
    
    stream << "[";
    
    Node *p = m_head->m_next;
    
    while (p->next != nullptr) {
        
        stream << p->m_key;
        
        p = p->m_next;
        
    }
    
    stream << "]";
    
    return stream;
    
}



template <typename ItemType>

std::istream &operator >> (std::istream &stream, List<ItemType> &other) {
    
    Node *p = m_head->m_next;
    
    while (p->m_next != nullptr) {
        
        
        
    }
    
    return stream;
    
}



*/
