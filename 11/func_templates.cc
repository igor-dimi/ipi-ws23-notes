#include <iostream>
using namespace std;

class Incrementer
{
    private:
        int increment;
    public:
        Incrementer (int _increment) {increment = _increment;}
        int operator() (int n) {return n + increment;}
};

class Squarer 
{
    public : 
        int operator() (int n) {return n * n;}
};

template<class T>
void loop(T& func){
    for (int i = 1; i < 10; i++)
        cout << func(i) << " ";
    cout << endl;
}

int main()
{

    Incrementer inc(10); //incrementers that increments wiht 10
    Squarer sq;
    loop(inc);
    loop(sq);
    return 0;
}