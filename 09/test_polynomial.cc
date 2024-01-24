#include "polynomial.cc"
#include <iostream>

int main()
{
    Polynomial p(2), q(10);
    p[0] = 1.0;
    p[1] = 1.0;
    p.print();
}