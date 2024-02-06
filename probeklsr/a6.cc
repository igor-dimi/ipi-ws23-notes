#include <iostream>
#include <cmath>

class A
{
    private :
        int a;
        int b;
    public :
        int get_a() {return a;}
        int get_b() {return b;}
        void set_a(int _a) {a = _a;}
        void set_b(int _b) {b = _b;}
        virtual int norm() {return sqrt(a*a + b*b);}
        A() {a = 0; b = 0;};
        A(int _a, int _b) {a = _a; b = _b;}
        A& operator= (const A& obj);
        virtual void show();
};

void A::show() {std::cout << a << " " << b;}
A& A::operator=(const A& obj)
{
    a = obj.a;
    b = obj.b;
    return *this;
}

class B : public A 
{
    private :
        int c;
    public :
        int get_c() {return c;}
        void set_c(int _c) {c = _c;}
        int norm() {return abs(get_a()) + abs(get_b()) + abs(c);}
        B() {set_a(0); c = 0;};
        B(int _a, int _b, int _c);
        void show();

};

B::B(int _a, int _b, int _c) : A(_a, _b) {c = _c;}
void B::show() {A::show(); std::cout << " " << c;}



int main(int argc, char const *argv[])
{
    
    A ob1;
    std::cout << ob1.get_a() << " " << ob1.get_b() << std::endl;
    ob1.set_a(3); ob1.set_b(4);
    std::cout << ob1.get_a() << " " << ob1.get_b() << std::endl;
    A ob2(ob1);
    std::cout << ob2.get_a() << " " << ob2.get_b() << std::endl;
    A ob3;
    ob3 = ob1;
    std::cout << ob3.get_a() << " " << ob3.get_b() << std::endl;
    A& ob4(ob3);
    std::cout << ob4.get_a() << " " << ob4.get_b() << std::endl;
    ob4.set_a(-99);
    std::cout << ob3.get_a() << " " << ob3.get_b() << std::endl;
    std::cout << ob1.norm() << std::endl;
    B ob5(1, 2, 3);
    ob5.show(); std::cout << std::endl;
    ob4.show(); std::cout << std::endl;

    A ob6(ob5);

    ob6.show(); std::cout << std::endl;

    A& ob7(ob5);
    ob7.show(); std::cout << std::endl;

    A ob8(-1, -2);
    A ob9, ob10;
    ob10 = ob9 = ob8;
    ob9.show(); std::cout << std::endl;
    ob10.show(); std::cout << std::endl;

    return 0;
}
