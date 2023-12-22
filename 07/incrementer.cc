#include "../code/fcpp.hh"

class Incrementer
{
    public: 
        Incrementer (int n) {increment = n;}
        int eval (int n) {return n + increment;}
    private:
        int increment;
};

void loop (Incrementer& inc)
{
    for (int i = 1; i < 10; i++) print(inc.eval(i));
}

int main()
{
    Incrementer inc(10);
    loop (inc);
}