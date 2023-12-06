#include "../code/fcpp.hh"

double my_abs(double x)
{
    if (x < 0) return -x;
    return x;
}

double root(double x)
{
    double y = 1.0;
    while (my_abs(y * y - x) > 1e-12)
        y = 0.5 * (y + x/y);
    return y;
}

int main(int argc, char **argv)
{
    return print(root(readarg_double(argc, argv, 1)));
}