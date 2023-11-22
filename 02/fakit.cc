#include "../code/fcpp.hh"

int fakit(int res, int i, int n)
{
    return cond(i > n, 
                res, 
                print(i, res * i, fakit(res * i, i + 1, n)));
}

int fak(int n)
{
    return fakit(1, 1, n);
}

int main()
{
    return fak(5);
}