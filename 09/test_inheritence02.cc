#include <iostream>

class X 
{
    private :
        int a;
        int b;
    public :
        int get_a() {return a;}
        int get_b() {return b;}
        void increase(int val) {a += val; b += val;}
        X(int _a, int _b) {a = _a; b = _b;}
        virtual void show();
        X() {a = 0; b = 0;};
};

void X::show()
{
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

class Y : public X
{
    private :
        int c;
    public :
        Y(int _a, int _b, int _c);
        Y();
        int get_c() {return c;}
        void show();

};

Y::Y(int _a, int _b, int _c) : X(_a, _b) {c = _c;}
Y::Y() : X() {}
void Y::show()
{
    X::show();
    std::cout << "c: " << c << std::endl;
}
int main(int argc, char const *argv[])
{
    X x;
    x.show();
    x.increase(10);
    x.show();
    x.increase(4);
    x.show();

    X x1(2, 3);
    x1.show();
    x1.increase(2);
    x1.show();

    std::cout << std::endl;
    std::cout << "y: " << std::endl;
    Y y1;
    y1.show();

    Y y2(1, 2, 3);
    y2.show();

    return 0;
}
