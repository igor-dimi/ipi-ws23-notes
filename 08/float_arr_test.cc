#include "../code/fcpp.hh"
#include <iostream>
#include "float_arr.cc"

void show (FloatArr& fa)
{
    std::cout << "#( ";
    for (int i = fa.min_index(); i <= fa.max_index(); i++)
        std::cout << fa[i] << " "; 
    std::cout << ")" << std::endl;
}

int main()
{
    FloatArr a(10, 0.0);
    FloatArr b(5, 5.0);
    FloatArr c(b);

    show(a);
    show(b);
    show(c);

    for (int i = a.min_index(); i <= a.max_index(); i++)
        a[i] = i * b[i];
    
    show(a);
    b = a;
    show(b);

}