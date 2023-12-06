#include "../code/fcpp.hh"

int absolut(int x)
{
    if (x < 0) return -x;
    return x;
}

int main(int argc, char **argv)
{
    return print(
        absolut(readarg_int(argc, argv, 1))
    );
}