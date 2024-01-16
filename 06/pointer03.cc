#include <stdio.h>
#include "../code/fcpp.hh"

int n = 3;

char* alphabet()
{
    char arr[27];
    for (int i = 0; i < 26; i++) arr[i] = i + 65;
    arr[26] = 0;
    return arr;
}

int main(int argc, char** argv)
{
    int m = 5;
    int* x = &m;
    *x = 4;
    print(*x);
    x = &n;
    *x = 13;
    print(*x);

    int n = 3;
    int m2 = 5;
    int* x2 = &n;
    int** y = &x2;
    int***z = &y;

    *&n = 10;
    print(n);

    int n3 = 3;
    int& rn = n3;
    int m3 = n3;

    rn = 5;
    print(n3);

    m3 = 6;
    print(m3, n3, 0);

    int f[5]; 
    int* p = f;
    p[0] = 4;
    *(p + 2) = 3;
    print(f[0], f[2], 0);
    p = &(f[3]); // equivalent zu p = f + 3;
    p[0] = 18;
    print(f[3]);
    p[1] = 19;
    print(f[4]);

    print(argc);
    for (int i = 0; i < argc; i++) print(argv[i]);

    char* arr = alphabet();
    for (int i = 0; i < 26; i++) print(arr[i]);



    return 0;
}