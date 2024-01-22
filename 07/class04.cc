#include "../code/fcpp.hh"
#include <iostream>
#include <stdio.h>

class A
{
    private :
        int a;
    public :
        A();
        A(int a);
        int get_a();
        void set_a(int a);
};

A::A() {a = 0;}
A::A(int a) {this->a = a;}
int A::get_a(){return a;}
void A::set_a(int a){this->a = a;}

class B
{
    private :
        int b;
        A& obj;
    public :
        B(A& obj, int b);
        int get_b();
        int get_a();
        void set_b(int b);
        void set_a(int a);
};
B::B(A& obj_in, int b) : obj(obj_in) {this->b = b;}
int B::get_a() {return obj.get_a();}
int B::get_b() {return b;}
void B::set_a(int a) {obj.set_a(a);}
void B::set_b(int b) {this->b = b;}

A f(int a)
{
    A obj = A(a);
    return obj;
};

int& g(int& a)
{
    a = a + 1;
    return a;
}

int& h(int& a)
{
    int& b = a;
    return b;
}

int main()
{
    A obj1(10);
    print(obj1.get_a());
    B obj2(obj1, 20);
    print(obj2.get_b());
    print(obj2.get_a());
    obj1.set_a(-3);
    print(obj2.get_b());
    print(obj2.get_a());
    obj2.set_a(-177);
    print(obj1.get_a());
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
    
    int val = 10;
    print("val: ", val, 0);
    g(g(val));
    print("val: ", val, 0);
    int& ref = h(val);
    ref++;
    print("val: ", val, 0);
    print("ref: ", ref, 0);
    return 0;
}


