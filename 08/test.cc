#include "float_arr02.cc"
#include "../code/fcpp.hh"
#include <stdio.h>

namespace A {
    int n = 1;
    int m = m;
}

namespace B {
    int n = 2;
    class X {};
}

namespace C {
    double x;
    int f(double x) {return x;}
    namespace D {
        double x, y;
    }
}

namespace C {
    double y;
}

int main()
{
    FloatArr a(15, 1.0);
    FloatArr b = a;
    FloatArr c(b);

    // for (int i = 0; i < 3; i++) print(a[i], b[i], c[i], 0);

    for (int i = a.min_index(); i <= a.max_index(); i++) a[i] = i;
    for (int i = a.min_index(); i <= a.max_index(); i++) b[i] = a[i] * i;

    // for (int i = 0; i < 3; i++) print(a[i], b[i], c[i], 0);
    // print("");
    // for (int i = 0; i < 3; i++) print(a[i]);
    // print("");
    // for (int i = 0; i < 3; i++) print(b[i]);
    // print("");
    // b = a;
    // for (int i = 0; i < 3; i++) print(b[i]);
    // print("");

    // A::n = B::n + 3;
    // C::D::y = 2.0;
    // print(C::D::y);

    // int n;
    // double x;
    // std::cin >> n; // cin.operator>>(n);
    // std::cin >> x;
    // std::cout << n << " " << x << std::endl;

    std::cout << a << std::endl << b << std::endl << c << std::endl;


    return 0; // 
}

