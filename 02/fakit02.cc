#include "../code/fcpp.hh"

int fakit(int res, int n)
{
    return cond(
        n > 1,
        fakit(res * n, n - 1),
        res
    );
}

int fak(int n)
{
    return fakit(1, n);
}

int main(int argc, char** argv)
{ 
    return print(fak(readarg_int(argc, argv, 1)));
}
