#pragma once

class Fraction {
public:
    Fraction SumFraction(Fraction b);
    Fraction DifFraction(const Fraction b);
    Fraction MultiFraction(const Fraction b);
    Fraction DivFraction(const Fraction b);
    void print();
    int numerator;
    int denominator;
};
