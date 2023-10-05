#include <iostream>
#include "Fraction.h"




Fraction::Fraction() {   // Конструктор по умолчанию без аргементов
    
    m_numerator = 1;
    m_denominator = 1;
    
}



Fraction::Fraction(const int numerator, const int denomerator) {   // Конструктор по умолчанию с аргементами
    
    this -> m_numerator = numerator;

    //другие решения

    /*
    1)
    //е
    this -> numerator = numerator;

    2)
    : numerator(numerator);
    */

    //одни поля класса можно инициализиоровать через другие
    //: numerator(n),
    // denominator(numerator);
    
    if (denomerator != 0) {
        
        this -> m_denominator = denomerator;
        
    }
    
    else {
        
        std::cerr << " В Fraction::Fraction ошибка: denominator = 0, будет исправлен на 1" << std::endl;
        
        this -> m_denominator = 1;
        
    }

}



Fraction Fraction::sumFraction(Fraction b) const {   // Сумма дробей
    
    Fraction s;
    
    s.m_numerator = m_numerator * b.m_denominator + m_denominator * b.m_numerator;
    s.m_denominator = m_denominator * b.m_denominator;
    
    return s;
    
}



Fraction Fraction::difFraction(Fraction b) const {   // Разность дробей
    
    Fraction s;
    
    s.m_numerator = m_numerator * b.m_denominator - m_denominator * b.m_numerator;
    s.m_denominator = m_denominator * b.m_denominator;
    
    return s;
    
}



Fraction Fraction::multiFraction(Fraction b) const {   // Произведение дробей
    
    Fraction s;
    
    s.m_numerator = m_numerator * b.m_numerator;
    s.m_denominator = m_denominator * b.m_denominator;
    
    return s;
    
}



Fraction Fraction::divFraction(Fraction b) const {   // Частное дробей
    
    Fraction s;
    
    if (b.m_numerator == 0) {
        
        s.m_numerator = 0; s.m_denominator = 0;
        
    }
    
    else {
        
        s.m_numerator = m_numerator * b.m_denominator;
        s.m_denominator = m_denominator * b.m_numerator;
        
    }
    
    return s;
}



Fraction Fraction::operator + (const Fraction b) const { // Перегрузка суммы
    
    return sumFraction(b);
    
}



Fraction Fraction::operator - (const Fraction b) const { // Перегрузка разности
    
    return difFraction(b);
    
}



Fraction Fraction::operator * (const Fraction b) const { // Перегрузка произведения
    
    return multiFraction(b);
    
}



Fraction Fraction::operator / (const Fraction b) const { // Перегрузка частного
    
    return divFraction(b);
    
}



void Fraction::print() const {   // Вывод дроби
    
    std::cout << m_numerator << '/' << m_denominator << std::endl;
    
}



void Fraction::reduce() {   // Сокращение дроби
    
    if (m_numerator != 0) {
        
        int a = m_numerator;
        int b = m_denominator;
        
        while (a!=b) {
            
            if (a > b)
                a = a - b;
            else
                b = b - a;
            
        }
        
        //std::cout << a;
        
        m_numerator = m_numerator/a;
        m_denominator = m_denominator/a;
        
    }
    
    else {
        
        m_denominator = 1;
        
    }
    
}



int Fraction::getNumerator() const {   // Получить числитель
    
    return m_numerator;
    
}



int Fraction::getDenominator() const {   // Получить знаменатель
    
    return m_denominator;
    
}
    


void Fraction::setNumerator(const int value) {   // Установить числитель
    
    m_numerator = value;
    
}



void Fraction::setDenominator(const int value) {   // Установить знаменатель
    
    if (value == 0) {
        
        std::cerr << "Ошибка: в методе setDenominator задаётся знаменатель = 0" << std::endl;
        
    }
    
    else 
        
        m_denominator = value;
    
}



void Fraction::scan() {
    
    std::cout << "Введите числитель >> ";
    std::cin >> m_numerator;
    
    std::cout << "Введите знаменатель >> ";
    std::cin >> m_denominator;
    
    while (m_denominator == 0) {
        
        std::cout << "Ошибка: знаменатель равен нулю. Введите знаменатель снова >> ";
        std::cin >> m_denominator;
        
    }
    
}



bool Fraction::operator == (const Fraction b) const { // Перегрузка равенства
    
    return ( (m_numerator == b.m_numerator) && (m_denominator == b.m_denominator) );
    
}



bool Fraction::operator != (const Fraction b) const { // Перегрузка неравенства
    
    return !( (m_numerator == b.m_numerator) && (m_denominator == b.m_denominator) );
    
}



bool Fraction::operator > (const Fraction b) const { // Перегрузка операции "больше"
    
    return ( (m_numerator * b.m_denominator) > (b.m_numerator * m_denominator) );
    
}



bool Fraction::operator < (const Fraction b) const { // Перегрузка операции "меньше"
    
    return ( (m_numerator * b.m_denominator) < (b.m_numerator * m_denominator) );
    
}



// Мои методы ----------------------------------------------------------------------------------------



Fraction & Fraction::operator ++ () { // Перегрузка префиксного инкремента
    
    m_numerator ++;
    if (m_denominator != -1) {
        
        m_denominator++;
        
    }
    
    return *this;
    
}



Fraction Fraction::operator ++ (int value) { // Перегрузка постфиксного инкремента
    
    Fraction elder(*this);
    
    operator ++ ();
    
    return elder;
    
}



Fraction & Fraction::operator -- () { // Перегрузка префиксного декремента
    
    m_numerator --;
    if (m_denominator != 1) {
        
        m_denominator--;
        
    }
    
    return *this;
    
}



Fraction Fraction::operator -- (int value) { // Перегрузка постфиксного декремента
    
    Fraction elder(*this);
    
    operator -- ();
    
    return elder;
    
}

Fraction::Fraction(double b) { // Конструктор double -> Fraction
    
    int count = 0;
    
    while ( b != (int)b ) {
        
        b*=10;
        
        count++;
        
    }
    
    this -> m_numerator = b;
    
    this -> m_denominator = pow(10, count);
    
    this -> reduce();
    
}
