# include "../code/fcpp.hh"

int gcd(int a, int b)
{
    return cond(b == 0, a, gcd(b, a % b));
}

int main(int argc, char** argv)
{
    return print(gcd(readarg_int(argc, argv, 1), readarg_int(argc, argv, 2)));
}