//
//  List.hpp
//  OOP Lab 5 "List"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#ifndef IS_TEMPLATE_LIST_DECLARED
#define IS_TEMPLATE_LIST_DECLARED



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
    List(const Array<ItemType> &array); // Конструктор из Array
    List(const List &other); // Конструктор копирования
    
    ~List() { // Деструктор
        
        clear();
        
        delete m_head;
        
    }
    
    int size() const; // Получение размера
    
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
    
    ItemType max() const;
    ItemType min() const;
    
    bool empty() const; // Проверка пустоты списка
    
    void clear(); // Очистка списка
    
    void print() const; // Вывод списка
    void enter(); // Ввод списка
    
    void info() const; // Информация о списке
    
    void sort(); // Сортировка
    
    
    // Перегрузки //---------------------------------------------------------------------------------------------------------------------------------
    
    List<ItemType> &operator = (const List<ItemType> &other);
    
    List<ItemType>::Node &operator [] (int i);
    const List<ItemType>::Node &operator [] (int i) const;
    
    bool operator == (const List<ItemType> &other) const;
    bool operator != (const List<ItemType> &other) const;
    
    List<ItemType> operator + (const List<ItemType> &list) const;
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
    
    
    Node (const ItemType& key = ItemType(), Node* next = nullptr, Node* prev = nullptr) : m_next(next) {
        
        m_key = *new ItemType(key);
        
    }
    
    ~Node() {}
    
    
    ItemType m_key;
    Node *m_next = nullptr;
    
};




#include "List.cpp"

#endif









