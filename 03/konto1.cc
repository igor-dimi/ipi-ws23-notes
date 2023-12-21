#include "../code/fcpp.hh"

double account; //global variable
void init_account(double amount) {account = amount};
double balance () {return account};
double withdraw (double amount)
{
    account -= amount;
    return amount;
}
int main()
{
    return 0;
}