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
}