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

int f()
{
    Rational* p = new Rational;
    p->numerator = 50;
    p->denominator = 40;
    delete p;
    return p->numerator;
}

int g()
{
    Rational* p = new Rational;
    p->numerator = 50;
    return p->numerator;
}
int main()
{
    int m;
    int* p = new int;
    *p = 10;
    print(*p);
    delete p;
    print(*p);
    int* q = new int[10];
    q[5] = 3;
    delete q;
    print(f());
    print(g());

}