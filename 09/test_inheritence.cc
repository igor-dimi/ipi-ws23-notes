#include <iostream>

class A 
{
    private :
        int x;
    public :
        A(int val);
        int get_x();
        void set_x(int val);
};

A::A(int _x) {x = _x;}
int A::get_x() {return x;}
void A::set_x(int _x) {x = _x;}

class B : public A 
{
    private :
        int y;
    public :
        B(int _x, int _y);
        int get_y();
};

B::B(int _x, int _y) : A(_x) {y = _y;}
int B::get_y() {return y;}

int f(A a)
{
    return a.get_x() * 2;
}

int g(B b)
{
    return b.get_x() + b.get_y();
}

int main()
{
    A a(10);
    B b(3, 2);
    std::cout << a.get_x() << std::endl;
    std::cout << "b: " << b.get_x() << " " << b.get_y();
    std::cout << std::endl;
    b.set_x(-2);
    std::cout << "b: " << b.get_x() << " " << b.get_y();
    std::cout << std::endl;

    std::cout << f(a) << std::endl;
    std::cout << f(b) << std::endl;
    b.set_x(25);
    std::cout << g(b) << std::endl;
    // std::cout << g(a) << std::endl; is an error! 
    

    return 0;
}