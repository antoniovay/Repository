//
//  Array.hpp
//  OOP Lab 2 "Array"
//
//  Created by Antony Miroshnichenko on 17.10.2023.
//



#pragma once



#include <iostream>
#include <assert.h>



template <typename ItemType>

class Array {
    
public:
    
    template <typename IT, typename AT>
    
    class TemplateIterator;
    
    using Iterator = TemplateIterator<ItemType, Array>;
    using ConstIterator = TemplateIterator<const ItemType, const Array>;

    
public:
    
    Array (const int size = 10, const ItemType &value = ItemType()); // Конструктор по умолчанию (заполнение одним числом)
    Array (const int size, const ItemType* array); // Конструктор по умолчанию (заполнение массивом)
    Array (const Array &other); // Конструктор копирования
    Array (Array &&other); // Конструктор перемещения
    
    ~Array(); // Деструктор
    
    
    void print() const; // Вывести массив
    
    void swap (Array &other); // Поменять местами два массива
    
    int search (const int value);
    
    int size() const; // Узнать размер массива
    void resize (int size); // Изменение размера массива
    
    bool insert (const int index, const ItemType& value); // Вставка элемента в массив (по индексу)
    
    bool removeAtIndex (const int index); // Удаление элемента из массива по индексу (аналогично вставке)
    bool removeAtValue (const ItemType& value); // Удаление элемента из массива по значению (первое вхождение)
    bool removeAtValueAll (const ItemType& value); // Удаление элементов из массива по значению (все)
    
    ItemType maxElement() const; // Найти максимальный элемент
    ItemType minElement() const; // Найти минимальный элемент
    
    void sort() const; // Сортировка массива
    
    
    // Перегрузки //-----
    
    Array &operator = (const Array &other); // Оператор присваивания
    Array &operator = (Array &&other); // Оператор присваивания по перемещению
    
    ItemType &operator [] (const int index); // Перегрузка []
    const ItemType &operator [] (const int index) const; // Перегрузка [] для const
    
    Iterator begin(); // Итератор на начало
    Iterator end(); // Итератор на конец
    
    ConstIterator begin() const; // Константный итератор на начало
    ConstIterator end() const; // Константный итератор на конец
    
    Iterator insertBeforeIterator (Iterator iter, const ItemType& value);
    Iterator removeInRange (const Iterator begin, const Iterator end);

    Array operator + (const Array &other) const; // Сложение массивов (конкатенация) +
    Array &operator += (const Array &other); // Сложение массивов (конкатенация) +=
    
    bool operator == (const Array object) const; // Сравнение ==
    bool operator != (const Array object) const; // Сравнение !=
    
    Array<ItemType> operator + (const ItemType& value) const; // Добавление элемента в конец массива
    Array<ItemType> &operator += (const ItemType& value); // Добавление элемента в конец массива
    
    
private:
    
    ItemType *m_array = nullptr;
    int m_size = 0;
    
};



template <typename ItemType>
template <typename IT, typename AT>

class Array<ItemType>::TemplateIterator {
    
public:
    
    friend class Array;
    
    TemplateIterator(AT *array = nullptr, const int pos = 0);
    
    
    bool hasNext() const;
    
    IT &operator * ();
    
    IT &operator [] (const int offset);
    
    TemplateIterator &operator = (const int &value);
    
    TemplateIterator &operator ++ ();
    TemplateIterator operator ++ (int);
    
    TemplateIterator &operator -- ();
    TemplateIterator operator -- (int);
    
    bool operator == (const TemplateIterator &other) const;
    bool operator != (const TemplateIterator &other) const;


private:
    AT *m_array;
    int m_pos = -1;
};








template <typename ItemType>

std::ostream &operator << (std::ostream &stream, const Array<ItemType> &arr);



template <typename ItemType>

std::istream &operator >> (std::istream &stream, Array<ItemType> &arr);
