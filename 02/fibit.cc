#include "../code/fcpp.hh"

int fibit(int a, int b, int n)
{
    return cond(n == 0, b, fibit(a + b, a, n - 1));
}

int fib(int n)
{
    return fibit(1, 0, n);
}

int main(int argc, char** argv)
{
    return print(fib(readarg_int(argc, argv, 1)));
}