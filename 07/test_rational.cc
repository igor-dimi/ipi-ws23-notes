#include "Rational.hh"
#include "Rational.cc"

int main()
{
    Rational p(3, 4), q(5, 3), r;

    p.print_rat(); q.print_rat();
    r = (p + q*p)*p*p;
    r.print_rat();

    Rational& s = q;
    s.print_rat();
    s.

    
    return 0;
}