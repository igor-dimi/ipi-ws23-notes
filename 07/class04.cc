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

    return 0;
}