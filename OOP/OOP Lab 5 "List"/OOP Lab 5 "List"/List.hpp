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
    
    List(const int size = 0, const ItemType value = 0); // Конструктор по умолчанию
    List(Array<ItemType> &array); // Конструктор из Array
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
    void insert_after (ItemType key); // Добавление элемента после равного key
    
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
    
    void info(); // Информация о списке
    
    void sort(); // Сортировка
    
    
    // Перегрузки //---------------------------------------------------------------------------------------------------------------------------------
    
    List<ItemType> &operator = (const List<ItemType> &other);
    
    List<ItemType>::Node &operator [] (int i);
    const List<ItemType>::Node &operator [] (int i) const;
    
    bool operator == (const List<ItemType> &other);
    bool operator != (const List<ItemType> &other);
    
    List<ItemType> operator + (const List<ItemType> &list);
    List<ItemType> &operator += (const List<ItemType> &list);
    
    
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

List<ItemType>::List(Array<ItemType> &array) {
    
    m_head = new Node;
    
    m_size = 0;
    
    for (int i = 0; i < array.size(); i++) {
        
        push_back(array[i]);
        
    }
    
}



template <typename ItemType>

List<ItemType>::List(const List &other) {
    
    //m_head = new Node;
    
    m_size = 0;
    
    m_head = new Node;
    
    Node *p = other.m_head;
    
    while (p->m_next) {
        
        push_back(p->m_next->m_key);
        
        p = p->m_next;
        
    }
    
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

void List<ItemType>::insert_after (ItemType key) {
    
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
    
    if (m_size == 1)
        
        return m_head->m_next->m_key;
    
    ItemType maxElem = m_head->m_next->m_key;
    
    for (auto it = m_head->m_next; it; it = it->m_next) {
        
        if (it->m_key > maxElem)
            
            maxElem = it->m_key;
        
    }
    
    return maxElem;
    
}



template <typename ItemType>

ItemType List<ItemType>::min() {
    
    assert(!empty());
    
    if (m_size == 1)
        
        return m_head->m_next->m_key;
    
    ItemType minElem = m_head->m_next->m_key;
    
    for (auto it = m_head->m_next; it; it = it->m_next) {
        
        if (it->m_key < minElem)
            
            minElem = it->m_key;
        
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
    
    std::cout << "]" << std::endl << std::endl;
    
}



template <typename ItemType>

void List<ItemType>::enter() {
    
    std::cout << "Введите размер списка >> ";
    
    int sizeCopy;
    
    std::cin >> sizeCopy;
    
    /*
    if (sizeCopy < 0) {
        
        std::cerr << "Отрицательный размер - изменён на положительный" << std::endl;
        
        sizeCopy = -sizeCopy;
        
    }
    */
    
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



template <typename ItemType>

void List<ItemType>::info() {
    
    std::cout << "LIST_DATA:" << std::endl;
    std::cout << "size: " << size() << std::endl;
    std::cout << "max: " << max() << std::endl;
    std::cout << "min: " << min() << std::endl;
    std::cout << "empty?: " << empty() << std::endl;
    print();
    //std::cout << std::endl;
    
}



template <typename ItemType>

void List<ItemType>::sort() {
    
    List<ItemType> newList;
    
    while (!empty()) {
        
        newList.push_back(min());
        
        //std::cout << min() << std::endl;
        
        pop_after(find_key(min()));
        
    }
    
    this->swap(newList);
    
}



// Перегрузки //--------------------------------------------------------------------------------------------------------------------------------------



template <typename ItemType>

List<ItemType> &List<ItemType>::operator = (const List<ItemType> &other) {
    
    if (this == &other)
        
        return *this;
    
    clear();
    
    m_size = 0;
    
    Node *p = other.m_head;
    
    while (p->m_next) {
        
        push_back(p->m_next->m_key);
        
        p = p->m_next;
        
    }
    
    return *this;
    
}



template <typename ItemType>

List<ItemType>::Node &List<ItemType>::operator [] (int i) {
    
    return find_pos(i)->m_key;
    
}



template <typename ItemType>

const List<ItemType>::Node &List<ItemType>::operator [] (int i) const {
    
    return find_pos(i)->m_key;
    
}



template <typename ItemType>

bool List<ItemType>::operator == (const List<ItemType> &other) {
    
    if (m_size != other.m_size)
        
        return false;
    
    if (m_head == other.m_head)
        
        return true;
    
    Node *p = m_head;
    Node *po = other.m_head;
    
    while (p->m_next) {
        
        if (p->m_next->m_key != other.p->m_next->m_key)
            
            return false;
        
        p = p->m_next;
        po = po->m_next;
        
    }
    
    return true;
    
}



template <typename ItemType>

bool List<ItemType>::operator != (const List<ItemType> &other) {
    
    return !(*this == other);
    
}



template <typename ItemType>

List<ItemType> List<ItemType>::operator + (const List<ItemType> &other) {
    
    List<ItemType> result = List(*this);
    
    result += other;
    
    return result;
    
}



template <typename ItemType>

List<ItemType> &List<ItemType>::operator += (const List<ItemType> &other) {
    
    Node *p = other.m_head;
    
    while (p->m_next) {
        
        this->push_back(p->m_next->m_key);
        
        p = p->m_next;
        
    }
    
    return *this;
    
}











template <typename ItemType>

std::ostream &operator << (std::ostream &stream, const List<ItemType> &other) {
    
    stream << "[";
    
    typename List<ItemType>::Node *p = other.m_head->m_next;
    
    while (p->next != nullptr) {
        
        stream << p->m_key;
        
        p = p->m_next;
        
    }
    
    stream << "]";
    
    return stream;
    
}



template <typename ItemType>

std::istream &operator >> (std::istream &stream, List<ItemType> &other) {
    
    typename List<ItemType>::Node *p = other.m_head->m_next;
    
    while (p->m_next != nullptr) {
        
        
        
    }
    
    return stream;
    
}




