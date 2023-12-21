#include "../code/fcpp.hh"

int gcd(int a, int b)
{
    return cond(b == 0, a, gcd(b, a % b));
}


struct Rational {
    int numerator;
    int denominator;
};

Rational create_rat (int numerator, int denominator)
{
    int g;
    Rational t;
    if (denominator < 0) { denominator = -denominator; numerator = -numerator;}
    g = gcd(std::abs(numerator), denominator);
    t.numerator = numerator / g;
    t.denominator = denominator /g; 
    return t;
}


Rational add(Rational p, Rational q)
{
    return create_rat(
        p.numerator * q.denominator +
        q.numerator * p.denominator,
        p.denominator * q.denominator
    );
};


Rational sub(Rational p, Rational q)
{
    return create_rat(
        p.numerator * q.denominator -
        q.numerator * p.denominator,
        p.denominator * q.denominator
    );
};


Rational mul(Rational p, Rational q)
{
    return create_rat(
        p.numerator * q.numerator,
        p.denominator * q.denominator
    );
};

Rational div(Rational p, Rational q)
{
    return create_rat(
        p.numerator * q.denominator,
        p.denominator * q.numerator
    );
};

void print_rat(Rational p){print(p.numerator, "/", p.denominator, 0);};

int main()
{
    Rational p = create_rat(3, 4);
    Rational q = create_rat(5, 3);
    print_rat(p); print_rat(q);

    Rational r1 = add(p, q);
    Rational r2 = sub(p, q);
    Rational r3 = mul(p, q);
    Rational r4 = div(p, q);

    print_rat(r1);
    print_rat(r2);
    print_rat(r3);
    print_rat(r4);


}

