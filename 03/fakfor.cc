#include "../code/fcpp.hh"

int fakfor(int n)
{
    int f = 1;
    for (int i = 0; i < n; i++) f = f * (i + 1);
    return f;
}

int main(int argc, char **argv)
{
    return print(
        fakfor(readarg_int(argc, argv, 1))
    );
}