#pragma once

class Fraction {
    
    
public:
    
    Fraction();  // Конструктор по умолчанию без аргементов
    Fraction(const int numerator, const int denomerator);  // Конструктор по умолчанию с аргементами
    Fraction(double b); // Конструктор double -> Fraction
    
    ~Fraction() = default;
    
    Fraction sumFraction(Fraction b) const;     // Сумма дробей
    Fraction difFraction(Fraction b) const;     // Разность дробей
    Fraction multiFraction(Fraction b) const;   // Произведение дробей
    Fraction divFraction(Fraction b) const;     // Частное дробей
    
    Fraction operator + (const Fraction b) const; // Перегрузка суммы
    Fraction operator - (const Fraction b) const; // Перегрузка разности
    Fraction operator * (const Fraction b) const; // Перегрузка произведения
    Fraction operator / (const Fraction b) const; // Перегрузка частного
    
    void print() const;  // Вывод дроби
    
    void reduce();  // Сокращение дроби
        
    int getNumerator() const;  // Получить числитель
    int getDenominator() const;  // Получить знаменатель
        
    void setNumerator(const int value);  // Установить числитель
    void setDenominator(const int value);  // Установить знаменатель
    
    void scan();
    
    bool operator == (const Fraction b) const; // Перегрузка равенства
    bool operator != (const Fraction b) const; // Перегрузка неравенства
    bool operator > (const Fraction b) const; // Перегрузка операции "больше"
    bool operator < (const Fraction b) const; // Перегрузка операции "меньше"
    
    //Мои методы -------------------------------------------------------
    
    Fraction & operator ++ ();        // Перегрузка префиксного инкремента
    Fraction operator ++ (int value); // Перегрузка постфиксного инкремента
    Fraction & operator -- ();        // Перегрузка префиксного декремента
    Fraction operator -- (int value); // Перегрузка постфиксного декремента
    
   
private:
    
    int m_numerator;
    int m_denominator;
    
};
