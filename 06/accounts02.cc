#include "../code/fcpp.hh"

// int n = 3;
int account1 = 1000;
int account2 = 4000;

int withdraw(int* account, int amount)
{
    return *account -= amount;
}

void withdraw2(int& account, int amount)
{
    account -= amount;
}

int main()
{
    // int m = 5;
    // print("m: ", m, 0);
    // int* x = &m;
    // *x = 4;
    // print("m: ", m, 0);
    // print("n: ", n, 0);
    // x = &n;
    // *x = 13;
    // print("n: ", n, 0);
    print(withdraw(&account1, 300));
    print(withdraw(&account2, 300));
    int amount = 200;
    withdraw2(account2, 200);
    print(account2);

    int n = 3;
    int& r = n;
    int m = n;
    n--;
    
    print(r);
    print(n);
    print(m);

    r--;

    print(r);
    print(n);
    print(m);

    int f[5];
    for (int i = 0; i < 5; i++) f[i] = i;
    for (int i = 0; i < 5; i++) print(f[i]);

    int* p = f;
    *p = 10;
    for (int i = 0; i < 5; i++) print(f[i]);

    int& rf = *f;

    rf++;
    for (int i = 0; i < 5; i++) print(f[i]);

    return 0;
}