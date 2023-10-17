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
    
    Array (const int size = 10, const ItemType &value = ItemType()); // Конструктор по умолчанию (заполнение одним числом)
    Array (const int size, const ItemType* array); // Конструктор по умолчанию (заполнение массивом)
    Array (const Array &other); // Конструктор копирования
    Array (Array &&other); // Конструктор перемещения
    
    ~Array(); // Деструктор
    
    
    void print() const; // Вывести массив
    
    void swap (Array &other); // Поменять местами два массива
    
    int searchInArray (const int value);
    
    int size() const; // Узнать размер массива
    void resize (int size); // Изменение размера массива
    
    bool insertInArray (const int index, const ItemType& value); // Вставка элемента в массив (по индексу)
    
    bool removeFromArrayIndex (const int index); // Удаление элемента из массива по индексу (аналогично вставке)
    bool removeFromArrayValue (const ItemType& value); // Удаление элемента из массива по значению (первое вхождение)
    bool removeFromArrayValueAll (const ItemType& value); // Удаление элементов из массива по значению (все)
    
    ItemType maxElement() const; // Найти максимальный элемент
    ItemType minElement() const; // Найти минимальный элемент
    
    void sortArray() const; // Сортировка массива
    
    
    // Перегрузки //-----
    
    Array &operator = (const Array &other); // Оператор присваивания
    Array &operator = (Array &&other); // Оператор присваивания по перемещению
    
    const ItemType &operator [] (const int index) const; // Перегрузка []

    Array operator + (const Array &other) const; // Сложение массивов (конкатенация) +
    Array &operator += (const Array &other); // Сложение массивов (конкатенация) +=
    
    bool operator == (const Array object) const; // Сравнение ==
    bool operator != (const Array object) const; // Сравнение !=
    
    
private:
    
    ItemType *m_array = nullptr;
    int m_size = 0;
    
};






template <typename Type>

std::ostream &operator << (std::ostream &stream, const Array<Type> &arr);



template <typename Type>

std::istream &operator >> (std::istream &stream, Array<Type> &arr);
