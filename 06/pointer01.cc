#include "../code/fcpp.hh"

int n = 3;

int main()
{
    int m = 5;
    print(n, m, 0);
    int* x = &m;
    *x = 4;
    x = &n;
    *x = 13;
    print(n, m, 0);

    return 0;
}