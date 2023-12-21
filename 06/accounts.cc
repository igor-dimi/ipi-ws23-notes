#include "../code/fcpp.hh"


int withdraw(int* account, int amount)
{
   return *account -= amount;
    
}

int withdraw2(int& account, int amount){return account -= amount;}

int main()
{
    int account1 = 100;
    int account2 = 200;
    print(withdraw(&account1, 25));
    print(withdraw(&account2, 35));
    print(withdraw2(account2, 15));
}