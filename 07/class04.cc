#include <iostream>
#include <stdio.h>
#include "../code/fcpp.hh"

class A
{
    private:
        int a;
    public :
        A(int a);
        int get_a();
        void set_a(int a);
};

A::A(int a) {this->a = a;}
int A::get_a() {return a;}
void A::set_a(int a) {this->a = a;}

A f(int a)
{
    A obj = A(a);
    return obj;
};

int& f2(int& a)
{
    return a;
}

int main()
{
    A a = f(3);
    A b = f(10);
    A c = f(20);
    c = a;
    A& d = a; //d --> a;
    A& e(b); //e --> b;

    print(a.get_a(), b.get_a(), 0);
    print(c.get_a());
    d.set_a(20);
    print(d.get_a(), a.get_a(), 0);
    e.set_a(100);
    print(e.get_a(), b.get_a(), 0);

    float* p = new float[10];
    for (int i = 0; i < 10; i++) p[i] = i;
    float* q = new float[12];
    for (int i = 0; i < 12; i++) q[i] = 2*i;

    delete [] p;
    p = q;

    for (int i = 0; i < 12; i++) print(p[i]);

    int b3 = 20;
    int& a3 = b3;
    f2(a3) = 20;
    print("b3: ", b3, 0);
    
    return 0;
}