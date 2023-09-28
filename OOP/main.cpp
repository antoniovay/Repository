#include <iostream>
#include "Fraction.h"


int main()
{
    
    Fraction x;
    
    x.scan();
    std::cout << std::endl << "Дробь x, введённая с клавиатуры = ";
    x.print();
    std::cout << std::endl;
    
    
    Fraction s(1, 6), z(1, 6), r(0, 1);
    
    std::cout << "Дробь ";
    r.print();
    std::cout << " при сокращении превращается в ";
    r.reduce();
    r.print();
    std::cout << std::endl;
    
    
    std::cout << "Дробь s = ";
    s.print();
    std::cout << "Дробь z = ";
    z.print();
    std::cout << std::endl;
    
    
    Fraction a = s + z;
    Fraction c = s - z;
    Fraction b = s * z;
    Fraction d = s / z;
    
    
    std::cout << "Операции с дробями s и z:" << std::endl;
    
    std::cout << "Результат суммы ->          Дробь a = ";
    a.print();
    
    std::cout << "Результат разности ->       Дробь b = ";
    b.print();
    
    std::cout << "Результат произведения ->   Дробь c = ";
    c.print();
    
    std::cout << "Результат частного ->       Дробь d = ";
    d.print();
    
    std::cout << std::endl;
    
    
    std::cout << "(s == z) : " << (s == z) << std::endl;
    std::cout << "(s != z) : " << (s != z) << std::endl;
    std::cout << "(s > z) : " << (s > z) << std::endl;
    std::cout << "(s < z) : " << (s < z) << std::endl;
    
    const double dbl = 12.44;
    
    Fraction f(dbl);
    
    std::cout << std::endl << "Doudle " << dbl << " преобразуется в Fraction - ";
    
    f.print();
    std::cout << std::endl;
    
}
