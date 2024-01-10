#include <iostream>
#include "Rational.hh"
#include "Rational.cc"

std::ostream&
operator<< (std::ostream& s, Rational q)
{
    s << q.get_numerator() << "/" << q.get_denominator();
    return s;
}

int main()
{
    int n;
    std::cin >> n; //
    double  x;
    std::cin >> x;
    std::cout << n;
    std::cout << " ";
    std::cout << x;
    std::cout << std::endl;
    std::cout << n << " " << x << std::endl;

    Rational p(3, 4), q(5, 2);

    std::cout << p << " " << q << std::endl;
    std::cout << (p + q * p) * p * p << std::endl;

}