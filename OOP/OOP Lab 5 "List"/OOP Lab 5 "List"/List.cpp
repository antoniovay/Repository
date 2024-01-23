//
//  List.cpp
//  OOP Lab 5 "List"
//
//  Created by Antony Miroshnichenko on 30.11.2023.
//



#ifndef ARE_TEMPLATE_LIST_METHODS_DEFINED
#define ARE_TEMPLATE_LIST_METHODS_DEFINED



#include "List.hpp"



template <typename ItemType>

List<ItemType>::List(const int size, const ItemType &value) {
    
    m_head = new Node;
    
    for (int i = size; i > 0; i--) {
        
        push_back(value);
        
    }
    
    m_size = size;
    
}



template <typename ItemType>

List<ItemType>::List(const Array<ItemType> &array) {
    
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

int List<ItemType>::size() const {
    
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

List<ItemType>::Node *List<ItemType>::find_key_prev(const ItemType &key) {
    
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

List<ItemType>::Node *List<ItemType>::find_pos_prev(int pos) {
    
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

List<ItemType>::Node *List<ItemType>::find_key(const ItemType &key) {
    
    return find_key_prev(key)->m_next;
    
}



template <typename ItemType>

List<ItemType>::Node *List<ItemType>::find_pos(int pos) {
    
    return find_pos_prev(pos)->m_next;
    
}



template <typename ItemType>

void List<ItemType>::push_front (const ItemType &key) {
    
    insert_after (key, m_head);
    
}



template <typename ItemType>

void List<ItemType>::push_back (const ItemType &key) {
    
    Node *p = m_head;
    
    while (p->m_next)
        
        p=p->m_next;
    
    insert_after(key, p);
    
}



template <typename ItemType>

void List<ItemType>::insert_after (const ItemType &key, Node *pos) {
    
    Node *q = new Node;
    
    q->m_key = key;
    
    q->m_next = pos->m_next;
    
    pos->m_next = q;
    
    m_size++;
    
}



template <typename ItemType>

void List<ItemType>::insert_after (const ItemType &key) {
    
    insert_after(key, find_key_prev(key));
    
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

void List<ItemType>::pop_after(const ItemType &key) {
    
    pop_after(find_key_prev(key));
    
}



template <typename ItemType>

ItemType List<ItemType>::max() const {
    
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

ItemType List<ItemType>::min() const {
    
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

bool List<ItemType>::empty() const {
    
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

void List<ItemType>::print() const {
    
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

void List<ItemType>::info() const {
    
    if (empty()) {
        
        std::cout << "[List is empty]" << std::endl;
        
        return;
        
    }
    
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
        
        pop_after(find_key_prev(min()));
        
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
    
    assert(i >= 0 && i < m_size);
    
    return find_pos_prev(i)->m_key;
    
}



template <typename ItemType>

const List<ItemType>::Node &List<ItemType>::operator [] (int i) const {
    
    assert(i >= 0 && i < m_size);
    
    return find_pos_prev(i)->m_key;
    
}



template <typename ItemType>

bool List<ItemType>::operator == (const List<ItemType> &other) const {
    
    if (m_size != other.m_size)
        
        return false;
    
    if (m_head == other.m_head)
        
        return true;
    
    Node *p = m_head;
    Node *po = other.m_head;
    
    while (p->m_next) {
        
        if (p->m_next->m_key != po->m_next->m_key)
            
            return false;
        
        p = p->m_next;
        po = po->m_next;
        
    }
    
    return true;
    
}



template <typename ItemType>

bool List<ItemType>::operator != (const List<ItemType> &other) const {
    
    return !(*this == other);
    
}



template <typename ItemType>

List<ItemType> List<ItemType>::operator + (const List<ItemType> &other) const {
    
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
    
    while (p) {
        
        stream << p->m_key;
        
        p = p->m_next;
        
        stream << (p ? " " : "");
    }
    
    stream << "]";
    
    return stream;
    
}



template <typename ItemType>

std::istream &operator >> (std::istream &stream, List<ItemType> &other) {
    
    typename List<ItemType>::Node *p = other.m_head->m_next;
    
    while (p) {
        
        stream >> p->m_key;
        
        p = p->m_next;
        
    }
    
    return stream;
    
    
}



#endif
