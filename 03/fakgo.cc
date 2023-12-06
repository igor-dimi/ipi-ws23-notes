#include "../code/fcpp.hh"

int fakgo(int n)
{
    int i = 0;
    int f = 1;
    //f == i!
    loop: if (i == n) return f;
    f = f * (i + 1);
    i++;
    goto loop;
}

int main(int argc, char **argv)
{
    return print(
        readarg_int(argc, argv, 1)
    );
}
