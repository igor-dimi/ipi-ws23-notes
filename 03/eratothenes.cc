#include "../code/fcpp.hh"

const int n = 50;
bool prim[n]; 

int main()
{
    //initialize
    prim[0] = false;
    prim[1] = false;
    for (int i = 2; i < n; i++) prim[i] = true;

    //sieb
    for (int i = 2; i <= sqrt((double) n); i++)
        if (prim[i])
            for (int j = 2; i*j < n; j++)
                prim[i*j] = false;

    //output
    int m = 0;
    for (int i = 0; i < n; i++)
        if (prim[i]) print(i);
    return 0;
}