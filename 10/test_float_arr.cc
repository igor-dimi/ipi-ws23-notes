#include <iostream>

#include "arr.hh"
#include "list_float_arr.cc"
#include "dynamic_float_arr.cc"

void show(Array& f)
{
    for (int i = f.min_index(); i <= f.max_index(); i++)
        if (f.is_member(i) && f[i] != 0.0)
            std::cout << "+" << f[i] << "*x^" << i;
    std::cout << std::endl;
}

void mult(Array& a, Array& b, Array& c)
{
    for (int i = a.min_index(); i <= a.max_index(); i++)
        if (a.is_member(i)) a[i] = 0.0;
    
    // a = b * c
    for (int i = b.min_index(); i <= b.max_index(); i++)
        if (b.is_member(i))
            for (int j = c.min_index(); j <= b.max_index(); j++)
                if (b.is_member(j))
                    a[i + j] = a[i + j] + b[i]*c[j];
}

int main()
{
    DynamicFloatArray f1, g1;
    ListFloatArray f2, g2;

    f1[0] = 1.0; f1[100] = 1.0;
    f2[0] = 1.0; f2[100] = 1.0;

    mult(g1, f1, f1);
    mult(f1, g1, g1);
    mult(g1, f1, f1);
    mult(f1, g1, g1);

    mult(g2, f2, f2);
    mult(f2, g2, g2);
    mult(g2, f2, f2);
    mult(f2, g2, g2);
    
    show(f1);
    std::cout << std::endl;
    show(f2);
    
    return 0;
}