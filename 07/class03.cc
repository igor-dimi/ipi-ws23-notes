#include "../code/fcpp.hh"

int account1 = 100;
int account2 = 200;

int withdraw(int& account, int amount)
{
    return account -= amount;
}

class Account 
{
    public:
        Account();
        Account (int initial);
        ~Account();
        int get_balance();
        int withdraw(int amount);
        void deposit(int amount);
    private:
        int balance;

};

Account::Account() {balance = 0;}

Account::Account(int initial)
{
    balance = initial;
}
Account::~Account()
{
    print("deleting account!");
}

int Account::withdraw(int amount)
{
    return balance -= amount;
}

void Account::deposit(int amount) {balance += amount;}

int Account::get_balance()
{
    return balance;
}

Account global_acc(500);

class Random
{
    public:
        Random(unsigned int seed);
        unsigned int get_number();
    private:
        unsigned int seed;
};

Random::Random(unsigned int seed)
{
    this->seed = seed;
}

unsigned int Random::get_number()
{
    unsigned int ia = 16807, im = 2147483647;
    unsigned int iq = 127773, ir = 2836;
    unsigned int k = seed / iq;
    seed = ia * (seed - k * iq) - ir * k;
    if (seed < 0) seed += im;
    return seed;
}

class Experiment 
{
    public :
        Experiment (Random& r);
        int carry_out();
    private :
        Random& rg;
        unsigned int gcd (unsigned int a,
                          unsigned int b);
};

Experiment::Experiment(Random& rand) : rg(rand) {}

unsigned int Experiment::gcd (unsigned int a, unsigned int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int Experiment::carry_out()
{
    unsigned int a = rg.get_number();
    unsigned int b = rg.get_number();
    if (gcd (a, b) == 1) return 1;
    return 0;
}

double montecarlo (Experiment& e, int N)
{
    int success = 0;
    for (int i = 0; i < N; i++) success += e.carry_out();
    return ((double) success) / ((double) N);
}

class A
{
    public:
        A();
        A(int a);
        int get_a();
        void set_a(int a);
    private :
        int a;
};

A::A(){a = 0;}
A::A(int a){this->a = a;};
int A::get_a(){return a;}
void A::set_a(int a){this->a = a;};

class A2
{
    public:
        A2(int a);
        int get_a(void);
        void set_a(int a);
    private:
        int a;
};

A2::A2(int a) {this->a = a;}
int A2::get_a() {return a;}
void A2::set_a(int a) {this->a = a;}

class B 
{
    public:
        B(int b, int a);
        int get_b();
        int get_a();
        void set_b(int b);
        void set_a(int a);
    private:
        int b;
        A2 a;
};

B::B(int b, int a_in) : a(a_in) {this->b = b;}
int B::get_b(){return b;}
int B::get_a(){return a.get_a();}
void B::set_b(int b) {this->b =b;}
void B::set_a(int a_in) {a.set_a(a_in);}


int main()
{
    int account3 = 20;
    print(account1);
    print(withdraw(account1, 20));
    print(account3);
    print(withdraw(account3, 10));
    Account acc4(100);
    print(acc4.withdraw(20));
    print(global_acc.get_balance());
    Account* acc5 = new Account(100); 
    print(acc5->get_balance()); 
    Account* acc6 = &acc4;
    acc6->withdraw(30);
    print(acc6, acc4);
    Account& acc7(acc4);
    print("balance of acc 7: ", acc7.get_balance(), 0);
    Random r(93267);
    Experiment e(r);
    print(sqrt(6.0)/montecarlo(e, 1000));
    A a;
    A b(10);
    A& c(b);
    print("a of a: ", a.get_a(), 0);
    print("a of b: ", b.get_a(), 0);
    print("a of c: ", c.get_a(), 0);
    b.set_a(b.get_a() + 1);
    print("a of a: ", a.get_a(), 0);
    print("a of b: ", b.get_a(), 0);
    print("a of c: ", c.get_a(), 0);
    
    A2 a2(10);
    B b2(5, 12);

    print("a of a2", a2.get_a(), 0);
    print("a of b", b2.get_a(), 0);
    print("b of b", b2.get_b(), 0); 



    B& c2(b2);
    
    print(c2.get_a(), c2.get_b(), 0);

    c2.set_a(1000);
    print(b2.get_a());

    Account acc8;
    print("balance of acc 8: ", acc8.get_balance(), 0);

    Account acc_arr[10];

    for (int i = 0; i < 10; i++) print("account ", i, acc_arr[i].get_balance(), 0);
    for (int i = 0; i < 10; i++) acc_arr[i].deposit(i*i + 10);
    for (int i = 0; i < 10; i++) print("account ", i, acc_arr[i].get_balance(), 0);



}