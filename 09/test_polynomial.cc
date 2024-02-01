#include "polynomial.cc"

int main()
{
    Polynomial p(2), q(3);
    Polynomial r(0);

    p[0] = 1.0;
    p[1] = 1.0;
    p[2] = 3.0;
    q[0] = -3.0;
    q[1] = 4.0;
    q[2] = 2.5;
    q[3] = 1.5;

    r = p * q;
    p.print();
    std::cout << std::endl;
    q.print();
    std::cout << std::endl;
    r.print();
    std::cout << std::endl;
    std::cout << r.eval(-3) << std::endl;
    
    return 0;
}