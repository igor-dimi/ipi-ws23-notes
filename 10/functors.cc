#include <iostream>


class Function
{
    public :
        virtual ~Function() {};
        virtual int operator() (int) = 0; //pure virtual function
};

class Incrementer : public Function 
{
    private :
        int increment;
    public :
        Incrementer (int val) {increment = val;}
        int operator() (int n) {return n + increment;}
};

class Squarer : public Function
{
    public : 
        int operator() (int n) {return n * n;}
};

void loop (Function& func)
{
    for (int i = 1; i < 10; i++) std::cout << func(i) << " ";
    std::cout << std::endl;
}



int main()
{
    Incrementer inc(10);
    Squarer sq;
    loop(inc);
    loop(sq);
}