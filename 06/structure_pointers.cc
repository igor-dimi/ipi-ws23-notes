#include "../code/fcpp.hh"

struct Rational
{
    int numerator;
    int denominator;
};

int main()
{
    Rational q;
    Rational* p = &q;
    (*p).numerator = 5;
    p->denominator = 4;
    print(q.denominator, q.numerator, 0);
}