#include "../code/fcpp.hh"

int fak(int n)
{
    int i = 1;
    int f = 1;
    //f == i! && i <= n + 1
    while (i < n){
        f = f * (i + 1); //f == (i + 1)!
        i++;
    } // i == n;
    return f;
}

int main(int argc, char **argv)
{
    return print(
        fak(readarg_int(argc, argv, 1))
    );
}