#include <stdio.h>
#include "../code/fcpp.hh"
#include <iostream>

struct Rational
{
    int n;
    int d;
};

int f()
{
    Rational* p = new Rational;
    p->n = 50;
    delete p;
    return p->n;
}

int g()
{
    Rational* p = new Rational;
    p->n = 50;
    return p->n;
}

Rational* h()
{
    Rational* p = new Rational;
    p->n = 40;
    p->d = 30;
    return p;
}

void f2(Rational q)
{
    q.n = 10;
    q.d = 10;
}

int main()
{

    int m;
    Rational* p2 = new Rational;
    p2->n = 4; p2->d = 5;
    Rational q;
    Rational* p = &q; 
    p->n = 5;
    (*p).d = 10;
    print(q.n);
    print(q.d);
    m = p2->n;
    print(m);
    delete p2;
    print(f());
    print(g());
    Rational* rp = h();
    print(rp->n, rp->d, 0);
    delete rp;
    print(rp->n, rp->d, 0);
    int* ip = new int;
    int& ip2 = *ip;
    ip2 = 10;
    print(ip2, *ip, 0);
    (*ip)++;
    print(ip2, *ip, 0);
    Rational q2;
    q2.n = 20;
    q2.d = 20;
    print(q2.n, q2.d, 0);
    f2(q2);
    print(q2.n, q2.d, 0);

    Rational* qp = &q2;
    qp->d--;
    print(q2.d);
    return 0;
}

