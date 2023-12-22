#include "../code/fcpp.hh"

class Account
{
    public:
        Account(int initial_capital);
        Account();
        ~Account();
        int get_balance();
        int withdraw(int amount);
    private:
        int balance;
};

Account::Account (int initial_capital)
{
    balance = initial_capital;
    print("Account initiated with: ", balance, 0);
}

Account::Account(){balance = 0;}

Account::~Account ()
{
    print("Account with: ", balance, " terminated", 0);
}

int Account::get_balance () {return balance;}

int Account::withdraw (int amount)
{
    balance -= amount;
    return balance;
}

Account a0(300);

int main()
{
    Account a1(100), a2(200), a3;
    print(a1.withdraw(50), a2.withdraw(100), a3.get_balance(), 0);
}