#include "../code/fcpp.hh"

int quadrat (int x)
{
    return x * x;
}

int main()
{
    print(quadrat(3) + quadrat(4));
    return 0;
}