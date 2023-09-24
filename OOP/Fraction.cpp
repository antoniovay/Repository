#include <iostream>
#include "Fraction.h"




Fraction::Fraction() {   // Конструктор по умолчанию без аргементов
    
    numerator = 1;
    denominator = 1;
    
}



Fraction::Fraction(const int numerator, const int denomerator) {   // Конструктор по умолчанию с аргементами
    
    this -> numerator = numerator;

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
        
        this -> denominator = denomerator;
        
    }
    
    else {
        
        std::cerr << " В Fraction::Fraction ошибка: denominator = 0, будет исправлен на 1" << std::endl;
        
        this -> denominator = 1;
        
    }

}



Fraction Fraction::sumFraction(Fraction b) {   // Сумма дробей
    
    Fraction s;
    
    s.numerator = numerator * b.denominator + denominator * b.numerator;
    s.denominator = denominator * b.denominator;
    
    return s;
    
}



Fraction Fraction::difFraction(Fraction b) {   // Разность дробей
    
    Fraction s;
    
    s.numerator = numerator * b.denominator - denominator * b.numerator;
    s.denominator = denominator * b.denominator;
    
    return s;
    
}



Fraction Fraction::multiFraction(Fraction b) {   // Произведение дробей
    
    Fraction s;
    
    s.numerator = numerator * b.numerator;
    s.denominator = denominator * b.denominator;
    
    return s;
    
}



Fraction Fraction::divFraction(Fraction b) {   // Частное дробей
    
    Fraction s;
    
    if (b.numerator == 0) {
        
        s.numerator = 0; s.denominator = 0;
        
    }
    
    else {
        
        s.numerator = numerator * b.denominator;
        s.denominator = denominator * b.numerator;
        
    }
    
    return s;
}



Fraction Fraction::operator + (const Fraction b) { // Перегрузка суммы
    
    return sumFraction(b);
    
}



Fraction Fraction::operator - (const Fraction b) { // Перегрузка разности
    
    return difFraction(b);
    
}



Fraction Fraction::operator * (const Fraction b) { // Перегрузка произведения
    
    return multiFraction(b);
    
}



Fraction Fraction::operator / (const Fraction b) { // Перегрузка частного
    
    return divFraction(b);
    
}



void Fraction::print() {   // Вывод дроби
    
    std::cout << numerator << '/' << denominator << std::endl;
    
}



void Fraction::reduce() {   // Сокращение дроби
    
    int a = numerator;
    int b = denominator;
    
    while (a!=b) {
        
        if (a > b)
            a = a - b;
        else
            b = b - a;
        
    }
    
    //std::cout << a;
    
    numerator = numerator/a;
    denominator = denominator/a;
    
}



int Fraction::getNumerator() {   // Получить числитель
    
    return numerator;
    
}



int Fraction::getDenominator() {   // Получить знаменатель
    
    return denominator;
    
}
    


void Fraction::setNumerator(int value) {   // Установить числитель
    
    numerator = value;
    
}



void Fraction::setDenominator(int value) {   // Установить знаменатель
    
    denominator = value;
    
}



void Fraction::scan() {
    
    std::cout << "Введите числитель >> ";
    std::cin >> numerator;
    
    std::cout << "Введите знаменатель >> ";
    std::cin >> denominator;
    
    while (denominator == 0) {
        
        std::cout << "Ошибка: знаменатель равен нулю. Введите знаменатель снова >> ";
        std::cin >> denominator;
        
    }
    
}



bool Fraction::operator == (const Fraction b) { // Перегрузка равенства
    
    return ( (numerator == b.numerator) && (denominator == b.denominator) );
    
}



bool Fraction::operator != (const Fraction b) { // Перегрузка неравенства
    
    return !( (numerator == b.numerator) && (denominator == b.denominator) );
    
}



bool Fraction::operator > (const Fraction b) { // Перегрузка операции "больше"
    
    return ( (numerator * b.denominator) > (b.numerator * denominator) );
    
}



bool Fraction::operator < (const Fraction b) { // Перегрузка операции "меньше"
    
    return ( (numerator * b.denominator) < (b.numerator * denominator) );
    
}



// Мои методы ----------------------------------------------------------------------------------------



Fraction & Fraction::operator ++ () { // Перегрузка префиксного инкремента
    
    numerator ++;
    if (denominator != -1) {
        
        denominator++;
        
    }
    
    return *this;
    
}



Fraction Fraction::operator ++ (int value) { // Перегрузка постфиксного инкремента
    
    Fraction elder(*this);
    
    operator ++ ();
    
    return elder;
    
}



Fraction & Fraction::operator -- () { // Перегрузка префиксного декремента
    
    numerator --;
    if (denominator != 1) {
        
        denominator--;
        
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
    
    this -> numerator = b;
    
    this -> denominator = pow(10, count);
    
    this -> reduce();
    
}
