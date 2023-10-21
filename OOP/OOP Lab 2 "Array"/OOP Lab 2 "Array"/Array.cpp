//
//  Array.cpp
//  OOP Lab 2 "Array"
//
//  Created by Antony Miroshnichenko on 17.10.2023.
//



#include <iostream>
#include <assert.h>

#include "Array.hpp"



// Фунуции класса Array //------------------------------------------------------------------------------------------------------------------------------





// Конструктор по умолчанию (заполнение одним числом)

template <typename ItemType>

Array <ItemType>::Array (const int size, const ItemType &value) {
    
    
    if (size < 0) {
        
        std::cerr << " Ошибка в конструкторе Array<ItemType>::Array : отрицательный размер, изменён на положительный." << std::endl;
        
        m_size = -size;
        
    }
    
    else {
        
        m_size = size;
        
    }

    
    m_array = new int[m_size];

    
    for (int i = 0; i < m_size; i++) {
        
        m_array[i] = value;
        
    }
    
}


 
 

// Конструктор по умолчанию (заполнение массивом)

template <typename ItemType>

Array<ItemType>::Array (const int size, const ItemType* array) {
    
    
    if (size < 0) {
        
        std::cerr << "Ошибка в конструкторе Array<ItemType>::Array : отрицательный размер, изменён на положительный." << std::endl;
        
        m_size = -size;
        
    }
    
    else {
        
        m_size = size;
        
    }
    
    
    m_array = new ItemType [m_size];
    
    
    for (int i = 0; i < m_size; i++) {
        
        m_array[i] = array[i];
        
    }
    
}



template <typename ItemType>

Array <ItemType>::Array (const Array &other)
    //: m_size(other.m_size)

{
        
    m_array = new int[other.m_size];

    for (int i = 0; i < other.m_size; ++i) {
        
        m_array[i] = other.m_array[i];
        
    }
        
}



template <typename ItemType>

Array <ItemType>::Array (Array &&other) {
    
    swap(other);
    
}



template <typename ItemType>

Array <ItemType>::~Array() {
    
    delete [] m_array;
    
}



// Вывести массив

template <typename ItemType>

void Array <ItemType>::print() const {
    
    std::cout << *this;
    
}



// Поменять местами два массива

template <typename ItemType>

void Array<ItemType>::swap(Array &other) {
    
    std::swap(m_array, other.m_array);
    std::swap(m_size, other.m_size);
    
}



// Поиск элемента (выводит индекс или -1, если элемент не найден)

template <typename ItemType>

int Array<ItemType>::search (const int value) {
    
    for (int i = 0; i < m_size; i++) {
        
        if (m_array[i] == value) {
            
            return i;
            
        }
        
    }
    
    return -1;
    
}





// Узнать размер массива

template <typename ItemType>

int Array<ItemType>::size() const {
    
    return m_size;
    
}



// Изменение размера массива

template <typename ItemType>

void Array<ItemType>::resize(int size) {
    
    if (size < 0) {
        
        std::cerr << " Ошибка в методе Array<ItemSize>::resize : отрицательный размер, изменён на положительный." << std::endl;
        
        size = -size;
        
    }

    Array res(size);

    int count = std::min(m_size, size);
    
    for (int i = 0; i < count; ++i) {
        
        res.m_array[i] = m_array[i];
        
    }

    res.swap(*this);
    
}



// Вставка элемента в массив (по индексу)

template <typename ItemType>

bool Array<ItemType>::insert (const int index, const ItemType& value) {
    
    
    if (index < 0 || index > m_size) {
        
        std::cerr << "Ошибка в методе Array<ItemType>::insertInArray : некорректный индекс." << std::endl;
        
        return false; // Возвращаем false при некорректном индексе
        
    }
    
    
    ItemType* updatedArray = new ItemType [m_size + 1]; // Выделяем новую память
        
    
    for (int i = 0, j = 0; i < m_size + 1; i++, j++) { // i идёт по новой памяти, j - по старой
        
        if (i == index) { // Как только натыкаемся на нужный индекс,
            
            updatedArray[i] = value; // вставляем туда value
            j--; // и, т.к. j проскочил в этот момент дальше, возвращаем его назад
            
        }
        
        else { // Иначе просто перекидываем элементы в новую память
            
            updatedArray[i] = m_array[j];
            
        }
        
    }
        
    
    delete [] m_array; // Очищаем старую память
    
    m_size++;
    
    m_array = updatedArray; // Переставляем указатель на новую память
    
    return true; // Всё успешно, возвращаем true
    
}



// Удаление элемента из массива по индексу (аналогично вставке)

template <typename ItemType>

bool Array<ItemType>::removeAtIndex (const int index) {
    
    
    if (index < 0 || index > m_size) {
        
        std::cerr << "Ошибка в методе Array<ItemType>::insertInArray : некорректный индекс." << std::endl;
        
        return false; // Возвращаем false при некорректном индексе
        
    }
    
    
    ItemType* updatedArray = new ItemType [m_size - 1];
    
    
    for (int i = 0, j = 0; i < m_size - 1; i++, j++) {
        
        if (i == index) {
            
            j++;
            
        }
        
        else {
            
            updatedArray[i] = m_array[j];
            
        }
        
    }
    
    
    delete [] m_array;
    
    m_size--;
    
    m_array = updatedArray;
    
    return true; // Всё успешно, возвращаем true
    
}



// Удаление элемента из массива по значению (первое вхождение)

template <typename ItemType>

bool Array<ItemType>::removeAtValue (const ItemType& value) {
    
    
    ItemType* updatedArray = new ItemType [m_size - 1];
    
    int flag = 0;
    
    
    for (int i = 0, j = 0; i < m_size - 1; i++, j++) {
        
        if (m_array[i] == value && flag == 0) {
            
            j++;
            
            flag = 1;
            
        }
        
        else {
            
            updatedArray[i] = m_array[j];
            
        }
        
    }
    
    
    if (flag) {
        
        delete [] m_array;
        
        m_size--;
        
        m_array = updatedArray;
        
        return true; // Всё успешно, возвращаем true
        
    }
    
    else {
        
        delete [] updatedArray;
        
        return false; // Элемент не найден, возвращаем false
        
    }
    
}



// Удаление элементов из массива по значению (все)

template <typename ItemType>

bool Array<ItemType>::removeAtValueAll (const ItemType& value) {
    
    int flag = 0;
        
    
        for (int i = 0; i < m_size; i++) {
            
            if (m_array[i] == value) {
                
                flag = removeAtIndex(i);
                
                i--;
                
            }
            
        }
        
    
    if (flag) {
        
        return true; // Всё успешно, возвращаем true
        
    }
            
    else {
        
        return false; // Элемент не найден, возвращаем false
        
    }
    
    
}



// Найти максимальный элемент

template <typename ItemType>

ItemType Array<ItemType>::maxElement() const {
    
    int indexMaxElement = 0;
    
    ItemType maxElement = m_array[0];
    
    
    for (int i = 0; i < m_size; i++) {
        
        if (m_array[i] > maxElement) {
            
            maxElement = m_array[i];
            
            indexMaxElement = i;
            
        }
        
    }
    
    
    return indexMaxElement;
    
}



// Найти минимальный элемент

template <typename ItemType>

ItemType Array<ItemType>::minElement() const {
    
    int indexMinElement = 0;
    
    ItemType minElement = m_array[0];
    
    for (int i = 0; i < m_size; i++) {
        
        if (m_array[i] < minElement) {
            
            minElement = m_array[i];
            
            indexMinElement = i;
            
        }
        
    }
    
    return indexMinElement;
    
}



// Сортировка массива

template <typename ItemType>

void Array<ItemType>::sort() const {
    
    for (int i = 0; i < m_size - 1; i++) {
        
        for (int j = 0; j < m_size - 1 - i; j++) {
            
            if (m_array[j] > m_array[j + 1]) {
                
                swap (m_array[j], m_array[j + 1]);
                
            }
            
        }
    }
}



template <typename ItemType> typename

Array<ItemType>::Iterator Array<ItemType>::begin() {
    
    return Iterator(this, 0);
    
}



template <typename ItemType> typename

Array<ItemType>::Iterator Array<ItemType>::end() {
    
    return Iterator(this, m_size);
    
}



template <typename ItemType> typename

Array<ItemType>::ConstIterator Array<ItemType>::begin() const {
    
    return ConstIterator(this, 0);
    
}



template <typename ItemType> typename

Array<ItemType>::ConstIterator Array<ItemType>::end() const {
    
    return ConstIterator(this, m_size);
}



template <typename ItemType> typename

Array<ItemType>::Iterator Array<ItemType>::insertBeforeIterator(Iterator iter, const ItemType& value) {
    
    insert(iter.m_pos, value);
    
    iter.m_pos++;
    
    return iter;
    
}



template <typename ItemType> typename

Array<ItemType>::Iterator Array<ItemType>::removeInRange (const Iterator begin, const Iterator end) {
    
    assert(end.m_pos >= begin.m_pos);
    
    Array updatedArray(m_size + begin.m_pos - end.m_pos, -1);
    
    Iterator iterOfUpdatedArray = updatedArray.begin();
    
    for (auto iter = this->begin(); iter != this->end(); iter++) {
        
        if (iter.m_pos < begin.m_pos || iter.m_pos >= end.m_pos) {
            
            (*iterOfUpdatedArray) = (*this)[iter.m_pos];
            
            iterOfUpdatedArray++;
            
        }
        
        else {
            
            iter += end.m_pos - begin.m_pos - 1;
            
        }
        
    }
    
    swap(updatedArray);
    
    return iterOfUpdatedArray;
    
}






// Перегрузки //-----



// Оператор присваивания

template <typename ItemType>

Array<ItemType> &Array<ItemType>::operator = (const Array &other) {
    
    /*
        Array &Array::operator=(Array other)
        {
            swap(other);
            return *this;
        }
    */

    if (this == &other) {
        
        return *this;
        
    }

    if (m_size != other.m_size) {
        
        m_size = other.m_size;
        
        delete[] m_array;
        
        m_array = new int[m_size];
        
    }

    for (int i = 0; i < m_size; ++i) {
        
        m_array[i] = other.m_array[i];
        
    }

    return *this;
    
}



// Оператор присваивания по перемещению

template <typename ItemType>

Array<ItemType> &Array<ItemType>::operator = (Array &&other) {
    
    swap(other);
    
    return *this;
    
}



// Перегрузка []

template <typename ItemType>

ItemType &Array<ItemType>::operator [] (const int index) {
    
    assert(index >= 0 && index < m_size); // Остановка программы при неправильном индексе
    
    return m_array[index];
    
}



// Перегрузка [] для const

template <typename ItemType>

const ItemType &Array<ItemType>::operator [] (const int index) const {
    
    assert(index >= 0 && index < m_size); // Остановка программы при неправильном индексе
    
    return m_array[index];
    
}



// Сложение массивов (конкатенация) +

template <typename ItemType>

Array<ItemType> Array<ItemType>::operator + (const Array &other) const {
    
    Array res(m_size + other.m_size);
    
    for (int i = 0, j = 0; i < res.m_size; i++) {
        
        if (i < m_size) {
            
            res[i] = m_array[i];
            
        }
        
        else {
            
            res[i] = other.m_array[j];
            
            j++;
            
        }
        
    }
    
    return res;
    
}



// Сложение массивов (конкатенация) +=

template <typename ItemType>

Array<ItemType> &Array<ItemType>::operator += (const Array &other) {
    
    Array res = *this + other;
    
    swap(res);
    
    return *this;
    
}



// Сравнение ==

template <typename ItemType>

bool Array<ItemType>::operator == (const Array other) const {
    
    if (m_size != other.m_size) {
        
        return false;
        
    }
    
    
    for (int i = 0; i < m_size; i++) {
        
        if (m_array[i] != other.m_array[i]) {
            
            return false;
            
        }
        
    }
    
    return true;
    
}



// Сравнение !=

template <typename ItemType>

bool Array<ItemType>::operator != (const Array other) const {
    
    return !(*this == other);
    
}



// Добавление элемента в конец массива

template <typename ItemType>

Array<ItemType> Array<ItemType>::operator + (const ItemType& value) const {
    
    Array updatedArray(m_size + 1, 0);
    
    for (int i = 0; i < m_size - 1; i++) {
        
        updatedArray.m_array[i] = m_array[i];
        
    }
    
    updatedArray.m_array[m_size] = value;
    
    return updatedArray;
    
}



// Добавление элемента в конец массива

template <typename ItemType>

Array<ItemType> &Array<ItemType>::operator += (const ItemType& value) {
    
    *this = *this + value;
    
    return *this;
    
}








// Функции класса TemplateIterator //-----------------------------------------------------------------------------------------------------------------



template <typename ItemType>
template <typename IT, typename AT>

Array<ItemType>::TemplateIterator<IT, AT>::TemplateIterator(AT *array, const int pos)
    : m_array(array), m_pos(pos)
{}





template <typename ItemType>

template <typename IT, typename AT>

bool Array<ItemType>::TemplateIterator<IT, AT>::hasNext() const {
    
    return (m_pos < m_array->size());
    
}



template <typename ItemType>

template <typename IT, typename AT>

IT &Array<ItemType>::TemplateIterator<IT, AT>::operator * () {
    
    return m_array->operator[](m_pos);
    
}



template <typename ItemType>

template <typename IT, typename AT>

IT &Array<ItemType>::TemplateIterator<IT, AT>::operator [] (const int index) {
    
    return *(operator[](index));
    
}



template <typename ItemType>
template <typename IT, typename AT> typename
Array<ItemType>:: template TemplateIterator<IT, AT> &Array<ItemType>::TemplateIterator<IT, AT>::operator = (const int &value) {
    
    m_pos = value;
    return *this;
    
}



template <typename ItemType>

template <typename IT, typename AT>

Array<ItemType>::TemplateIterator<IT, AT> &Array<ItemType>::TemplateIterator<IT, AT>::operator ++ () {
    
    ++m_pos;
    
    return *this;
    
}



template <typename ItemType>

template <typename IT, typename AT>

Array<ItemType>::TemplateIterator<IT, AT> Array<ItemType>::TemplateIterator<IT, AT>::operator ++ (int) {
    
    Array<ItemType>::TemplateIterator<IT, AT> old(*this);
    
    ++m_pos;
    
    return old;
    
}



template <typename ItemType>

template <typename IT, typename AT>

Array<ItemType>::TemplateIterator<IT, AT> &Array<ItemType>::TemplateIterator<IT, AT>::operator -- () {
    
    --m_pos;
    
    return *this;
    
}



template <typename ItemType>

template <typename IT, typename AT>

Array<ItemType>::TemplateIterator<IT, AT> Array<ItemType>::TemplateIterator<IT, AT>::operator -- (int) {
    
    Array<ItemType>::TemplateIterator<IT, AT> old(*this);
    
    --m_pos;
    
    return old;
    
}



template <typename ItemType>

template <typename IT, typename AT>

bool Array<ItemType>::TemplateIterator<IT, AT>::operator == (const TemplateIterator &other) const {
    
    return (m_array == other.m_array && m_pos == other.m_pos);
    
}



template <typename ItemType>

template <typename IT, typename AT>

bool Array<ItemType>::TemplateIterator<IT, AT>::operator != (const TemplateIterator &other) const {
    
    return !( operator==(other) );
    
}






// Прочие функции //----------------------------------------------------------------------------------------------------------------------------------



// Поменять местами два элемента int

void swap (int &a, int &b) {
    
    int c = a;
    a = b;
    b = c;
    
}



// Потоковый вывод

template <typename ItemType>

std::ostream &operator << (std::ostream &stream, const Array<ItemType> &arr) {
    
    stream << '[';
    
    for (int i = 0; i < arr.size() - 1; ++ i) {
        
        stream << arr[i] << ", ";
        
    }
    
    stream << arr[arr.size() - 1] << "]" << std::endl;
    
    return stream;
    
}



// Потоковый ввод

template <typename ItemType>

std::istream &operator >> (std::istream &stream, Array<ItemType> &arr) {
    
    for (int i = 0; i < arr.size(); ++i) {
        
        stream >> arr[i];
        
    }
    
    return stream;
    
}



