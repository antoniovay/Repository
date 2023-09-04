#include <iostream>
#include "Fraction.h"

//Сумма дробей
Fraction Fraction::SumFraction(const Fraction b)
{
    Fraction s;
    s.numerator=numerator*b.denominator+denominator*b.numerator;
    s.denominator=denominator*b.denominator;
    return s;
}

//Произведение дробей
Fraction Fraction::MultiFraction(const Fraction b)
{
    Fraction s;
    s.numerator=numerator*b.numerator;
    s.denominator=denominator*b.denominator;
    return s;
}

//Печать
void Fraction::print()
{
    std::cout << numerator << '/' << denominator;
}
