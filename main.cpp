#include <iostream>
#include "Fraction.h"


int main()
{
    Fraction s, z;
    s.numerator = -1;
    s.denominator = 2;
    z.numerator = 1;
    z.denominator = 2;
    Fraction a = s.SumFraction(z);
    Fraction b = s.MultiFraction(z);
    Fraction c = s.DifFraction(z);
    Fraction d = s.DivFraction(z);
    a.print();
    b.print();
    c.print();
    d.print();
}
