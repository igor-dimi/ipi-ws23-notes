#include "../code/fcpp.hh"

int fibfor(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++){ //a == fib(i) && b == fib(i + 1) && i <= n
    
        b = b + a; //b == fib(i + 2)
        a = b - a; //a == fib(i + 1)
    } //i == n;
    return a;
}

int main(int argc, char **argv)
{
    return print(
        fibfor(readarg_int(argc, argv, 1))
    );
}