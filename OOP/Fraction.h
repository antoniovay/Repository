#pragma once

class Fraction {
    
    
public:
    
    Fraction();  // Конструктор по умолчанию без аргементов
    Fraction(const int numerator, const int denomerator);  // Конструктор по умолчанию с аргементами
    
    ~Fraction() = default;
    
    Fraction sumFraction(Fraction b);  // Сумма дробей
    Fraction difFraction(Fraction b);  // Разность дробей
    Fraction multiFraction(Fraction b);  // Произведение дробей
    Fraction divFraction(Fraction b);  // Частное дробей
    
    Fraction operator + (const Fraction b); // Перегрузка суммы
    Fraction operator - (const Fraction b); // Перегрузка разности
    Fraction operator * (const Fraction b); // Перегрузка произведения
    Fraction operator / (const Fraction b); // Перегрузка частного
    
    void print();  // Вывод дроби
    
    void reduce();  // Сокращение дроби
        
    int getNumerator();  // Получить числитель
    int getDenominator();  // Получить знаменатель
        
    void setNumerator(int value);  // Установить числитель
    void setDenominator(int value);  // Установить знаменатель
    
    void scan();
    
    bool operator == (const Fraction b); // Перегрузка равенства
    bool operator != (const Fraction b); // Перегрузка неравенства
    bool operator > (const Fraction b); // Перегрузка операции "больше"
    bool operator < (const Fraction b); // Перегрузка операции "меньше"
    
    //Мои методы -------------------------------------------------------
    
    Fraction & operator ++ ();        // Перегрузка префиксного инкремента
    Fraction operator ++ (int value); // Перегрузка постфиксного инкремента
    Fraction & operator -- ();        // Перегрузка префиксного декремента
    Fraction operator -- (int value); // Перегрузка постфиксного декремента
    
    Fraction(double b); // Конструктор double -> Fraction
        
        
private:
    
    int m_numerator;
    int m_denominator;
    
};
