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
    
    List(const int size = 10, const ItemType value = 0); // Конструктор по умолчанию
    List(Array<ItemType> &other); // Конструктор из Array
    List(const List &other); // Конструктор копирования
    
    ~List() { // Деструктор
        
        clear();
        
        delete m_head;
        
    }
    
    int size(); // Получение размера
    
    void swap(List &other);
    
    List<ItemType>::Node *find_key(ItemType key); // Поиск в списке по ключу.
    List<ItemType>::Node *find_pos(int pos); // Поиск в списке по позиции pos
    
    void push_front (ItemType key); // Добавление элемента в голову списка
    void push_back (ItemType key); // Добавление элемента в хвост списка
    void insert_after (ItemType key, Node *pos); // Добавление элемента после заданного
    void insert_after_key (ItemType key); // Добавление элемента после равного key
    
    void pop_front (); // Удаление головы
    void pop_back (); // Удаление хвоста
    void pop_after (Node *pos) ; // Удаление элемента после заданного узла
    void pop_after (ItemType key); // Удаление элемента равного key
    
    ItemType max();
    ItemType min();
    
    bool empty(); // Проверка пустоты списка
    
    void clear(); // Очистка списка
    
    void print(); // Вывод списка
    void enter(); // Ввод списка
    
    
    // Перегрузки //---------------------------------------------------------------------------------------------------------------------------------
    
    
    
    
private:
    
    Node *m_head;
    int m_size;
    
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

List<ItemType>::List(const int size, const ItemType value) {
    
    m_head = new Node;
    
    for (int i = size; i > 0; i--) {
        
        push_back(value);
        
    }
    
    m_size = size;
    
}



template <typename ItemType>

List<ItemType>::List(Array<ItemType> &other) {
    
    
    
}



template <typename ItemType>

List<ItemType>::List(const List &other) {
    
    m_size = other.m_size;
    
    std::swap(m_head, other.m_head);
    
}



template <typename ItemType>

int List<ItemType>::size() {
    
/*                   // Если без m_size
    int size = 0;
    
    Node *p = m_head;
    
    while (p->m_next) {
        
        size++;
        
        p = p->m_next;
        
    }
*/
    return m_size;
    
}



template <typename ItemType>

void List<ItemType>::swap(List &other) {
    
    std::swap(m_head, other.m_head);
    std::swap(m_size, other.m_size);
    
}



template <typename ItemType>

List<ItemType>::Node *List<ItemType>::find_key(ItemType key) {
    
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

List<ItemType>::Node *List<ItemType>::find_pos(int pos) {
    
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

void List<ItemType>::push_front (ItemType key) {
    
    insert_after (key, m_head);
    
}



template <typename ItemType>

void List<ItemType>::push_back (ItemType key) {
    
    Node *p = m_head;
    
    while (p->m_next)
        
        p=p->m_next;
    
    insert_after(key, p);
    
}



template <typename ItemType>

void List<ItemType>::insert_after (ItemType key, Node *pos) {
    
    Node *q = new Node;
    
    q->m_key = key;
    
    q->m_next = pos->m_next;
    
    pos->m_next = q;
    
    m_size++;
    
}



template <typename ItemType>

void List<ItemType>::insert_after_key (ItemType key) {
    
    insert_after(key, find_key(key));
    
}



template <typename ItemType>

void List<ItemType>::pop_front () {
    
    pop_after (m_head);
    
}



template <typename ItemType>

void List<ItemType>::pop_back () {
    
    assert(m_head->m_next != nullptr);
    
    
    Node *p = m_head;
            
    while (p->m_next->m_next != 0)
        
        p = p->m_next;
    
    pop_after (p);
    
}



template <typename ItemType>

void List<ItemType>::pop_after (Node *pos) {
    
    assert(pos->m_next != nullptr);
    
    
    Node *q = pos->m_next;
    
    pos->m_next = q->m_next;
    
    delete q;
    
    m_size--;
    
}



template <typename ItemType>

void List<ItemType>::pop_after(ItemType key) {
    
    pop_after(find_key(key));
    
}



template <typename ItemType>

ItemType List<ItemType>::max() {
    
    assert(!empty());
    
    
    ItemType maxElem = m_head->m_next->m_key;
    
    if (m_head->m_next->m_next == nullptr)
        
        return maxElem;
    
    Node *p = m_head->m_next->m_next;
    
    while (p->m_next != nullptr) {
        
        if (p->m_next->m_key > maxElem)
            
            maxElem = p->m_next->m_key;
        
        p = p->m_next;
        
    }
    
    return maxElem;
    
}



template <typename ItemType>

ItemType List<ItemType>::min() {
    
    assert(!empty());
    
    
    ItemType minElem = m_head->m_next->m_key;
    
    if (m_head->m_next->m_next == nullptr)
        
        return minElem;
    
    Node *p = m_head->m_next->m_next;
    
    while (p->m_next != nullptr) {
        
        if (p->m_next->m_key < minElem)
            
            minElem = p->m_next->m_key;
        
        p = p->m_next;
        
    }
    
    return minElem;
    
}



template <typename ItemType>

bool List<ItemType>::empty() {
    
    if (m_head->m_next == nullptr)
        
        return true;
    
    //if (!m_size) return true;
    
    return false;
    
}



template <typename ItemType>

void List<ItemType>::clear() {
    
    while (m_head->m_next)
        
        pop_front();
    
}



template <typename ItemType>

void List<ItemType>::print() {
    
    if (empty()) {
        
        std::cerr << "Error in print(): list is empty" << std::endl;
        
        return;
        
    }
    
    std::cout << "[ ";
    
    Node *p = m_head;
    
    while (p->m_next != nullptr) {
        
        std::cout << p->m_next->m_key << " ";
        
        p = p->m_next;
        
    }
    
    std::cout << "]" << std::endl;
    
}



template <typename ItemType>

void List<ItemType>::enter() {
    
    std::cout << "Введите размер списка >> ";
    
    int sizeCopy;
    
    std::cin >> sizeCopy;
    
    if (sizeCopy < 0)
        
        return;
    
    clear();
    
    if (sizeCopy)
        
        std::cout << "Введите элементы списка >> ";
    
    ItemType value;
    
    for (int i = 0; i < sizeCopy; i++) {
        
        std::cin >> value;
        
        //print();
        
        push_back(value);
        
    }
    
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
