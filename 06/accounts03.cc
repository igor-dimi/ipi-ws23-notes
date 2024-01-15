#include <iostream>
#include "../code/fcpp.hh"



int withdraw (int* account, int amount)
{ return *account -= amount;}   

int withdraw02(int& account, int amount)
{ return account -= amount;}

int main()
{
    int account1 = 100;
    int account2 = 200;

    print(withdraw(&account1, 25));
    print(withdraw(&account2, 25));

    print(withdraw02(account1, 25));
    print(withdraw02(account2, 25));
}