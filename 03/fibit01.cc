#include "../code/fcpp.hh"

int fib(int n)
{
    int i = 0; // i <= n
    int a = 1;
    int b = 0; 
    //a == fib(i+1), b == fib(i), i <= n
    while (i < n){
        a = a + b; //a == fib(i + 2)
        b = a - b; //b == fib(i + 2) - fib(i) == fib(i + 1)
        i++;
    } // b == fib(i) && i == n
    return b;
}

int main(int argc, char **argv)
{
    return print(
        fib(readarg_int(argc, argv, 1))
    );
}
