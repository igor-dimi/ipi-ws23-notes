#include <iostream>

class A 
{
    private :
        int x;
    public :
        A(int val);
        void increase (int val);
        int get();
};

//Implementation of A
A::A(int val){x = val;}
void A::increase(int val) {x *= val;}
int A::get() {return x;}

class B
{
    private :
        int y;
        A a;
    public :
        B(int val, A a);
        int get_y();
        int get_a();
        void increase_a(int val) {a.increase(val);}
};

B::B(int val, A obj) : a(obj) {y = val;}
int B::get_y() {return y;}
int B::get_a() {return a.get();}

class C
{
    private :
        int y;
        A& a;
    public :
        C(int val, A& a);
        int get_y();
        int get_a();
};


C::C(int val, A& obj) : a(obj) {y = val;}
int C::get_y() {return y;}
int C::get_a() {return a.get();}


int main()
{
    A a(10);
    std::cout << a.get() <<std::endl;
    a.increase(3);
    std::cout << a.get() <<std::endl;
    B b(2, a);
    std::cout << b.get_a() << " " << b.get_y() << std::endl;
    b.increase_a(10);
    std::cout << "after increasing object b: \n";
    std::cout << "b: " << b.get_a() << " " << b.get_y() << std::endl;
    std::cout << "a: " << a.get() <<std::endl;
    a.increase(3);
    std::cout << "after increasing object a: \n";
    std::cout << "b: " << b.get_a() << " " << b.get_y() << std::endl;
    std::cout << "a: " << a.get() <<std::endl;
    C c(-5, a);
    std::cout << "c: " << c.get_a() << " " << c.get_y() << std::endl;
    a.increase(20);
    std::cout << "a: " << a.get() <<std::endl;
    std::cout << "c: " << c.get_a() << " " << c.get_y() << std::endl;
    std::cout << "b: " << b.get_a() << " " << b.get_y() << std::endl;

}
