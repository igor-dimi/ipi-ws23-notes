#include "../code/fcpp.hh"

int facf(int n)
{
    return cond(n <= 1, 1, n * facf(n - 1));
}

int main()
{
    print(facf(5));
    return 0;
}

