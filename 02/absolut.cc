#include "../code/fcpp.hh"

int absolut (int x)
{
    return cond( x <= 0, -x, x);
}

int main ()
{
    print(absolut(-3));
    return 0;
}