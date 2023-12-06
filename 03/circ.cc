#include "../code/fcpp.hh"

float circumference(double r)
{
    const double PI = 3.14159265;
    return 2 * r * PI;
}

int main(int argc, char **argv)
{
    return print(
        circumference(readarg_double(argc, argv, 1))
    );
}