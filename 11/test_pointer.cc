#include <iostream>
#include "pointer.hh"

int g (Pointer<int> p) {return *p;}

int main()
{
    // Pointer<int> q = new int(17);
    // std::cout << *q << std::endl;
    // int x = g(q);
    // std::cout << x << std::endl;
    // Pointer<int> z = new int(22);
    // q = z;
    // std::cout << *q << std::endl; 

    Pointer<int> q(new int(17));
    // std::cout << *q << std::endl;
    // int x = g(q);
    // std::cout << "x: " << x << std::endl;
    Pointer<int> z(new int(22));
    q = z;

    return 0;
}