#include <iostream>
#include "Fraction.h"

//Сумма дробей
Fraction Fraction::SumFraction(const Fraction b)
{
    Fraction s;
    s.numerator = numerator * b.denominator + denominator * b.numerator;
    s.denominator = denominator * b.denominator;
    return s;
}

//Разность дробей
Fraction Fraction::DifFraction(const Fraction b)
{
    Fraction s;
    s.numerator = numerator * b.denominator - denominator * b.numerator;
    s.denominator = denominator * b.denominator;
    return s;
}

//Произведение дробей
Fraction Fraction::MultiFraction(const Fraction b)
{
    Fraction s;
    s.numerator = numerator * b.numerator;
    s.denominator = denominator * b.denominator;
    return s;
}

//Частное дробей
Fraction Fraction::DivFraction(const Fraction b)
{
    Fraction s;
    if (b.numerator == 0) {s.numerator = 0; s.denominator = 0;}
    else{
        s.numerator = numerator * b.denominator;
        s.denominator = denominator * b.numerator;
    }
    return s;
}

//Печать
void Fraction::print()
{
    std::cout << numerator << '/' << denominator << std::endl;
}

