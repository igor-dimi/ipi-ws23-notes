#include "../code/fcpp.hh"
#include <iostream>
#include <stdio.h>


int acc1 = 100;
int acc2 = 200;
void withdraw (int amount, int& acc)
{
    acc -= amount;
}

class Account
{
    public :
        Account(int init_balance);
        Account();
        ~Account();
        int get_balance();
        int withdraw(int amount);
    private :
        int balance;
};

Account::Account (int init_balance)
{
    balance = init_balance;
    print("Account initialized with ", balance, 0); 
}

Account::Account () {balance = 0;};

Account::~Account ()
{
    print("Account with the balance of ", balance, " deleted", 0);
}


int Account::get_balance () {return balance;};

int Account::withdraw (int amount)
{
    balance -= amount;
    return balance;
}

class Random
{
    public :
        Random (unsigned int seed);
        unsigned int get_number ();
    private :
        unsigned int seed;
};

Random::Random (unsigned int seed)
{
    this->seed = seed;
}

unsigned int Random::get_number ()
{
    unsigned int ia = 16807, im = 2147483657;
    unsigned int iq = 127773, ir = 2836;
    unsigned int k = seed / iq;
    seed = ia * ( seed - k * iq) - ir * k;
    if (seed < 0) seed += im;
    return seed;
}

class Experiment 
{
    public :
        Experiment (Random& r);
        int carry_out ();
    private :
        Random& rg;
        unsigned int gcd(unsigned int a, unsigned int b);
};

Experiment::Experiment (Random& r) : rg(r) {}

unsigned int Experiment::gcd (unsigned int a, unsigned int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int Experiment::carry_out ()
{
    unsigned int x1 = rg.get_number();
    unsigned int x2 = rg.get_number();
    return gcd(x1, x2) == 1 ? 1 : 0;
}

double montecarlo (Experiment& e, int N)
{
    int success = 0;
    for (int i = 0; i < N; i++) success += e.carry_out();
    return ((double) success) / ((double) N);
}

class A {
    private :
        int a;
    public :
        void set_a(int a);
        int get_a();
        A(int a);
};

class B {
    private :
        int b;
        A a;
    public :
        B (A a, int b);
        B(int a, int b);
        int get_b();
        int get_a();
        void set_a(int a);
};

A::A(int a) {this->a = a;};
int A::get_a() {return a;};
void A::set_a(int val) {a = val;};

B::B(A av, int b) : a(av) {this->b = b;};
B::B(int av, int b) : a(av) {this->b = b;};
int B::get_b() {return b;};
int B::get_a() {return a.get_a();};
void B::set_a(int val) {a.set_a(val);};

int summe() {return 0;}
int summe (int i) {return i; }
int summe (int i, int j) {return i + j;};
double summe (double a, double b) {return a + b;};

class Incrementer
{
    private :
        int increment;
    public :
        Incrementer (int n) {increment = n;}
        int eval (int n) {return n + increment;}
};

void loop (Incrementer& incrementer)
{
    for (int i = 1; i < 10; i++) print(incrementer.eval(i));
}

class Rational
{
    private :
        int n, d;
        int gcd (int a, int b);
    public :
        int get_numerator ();
        int get_denominator ();
        Rational (int num, int den);
        Rational (int num);
        Rational ();
        void print ();
        Rational operator+ (Rational q);
        Rational operator- (Rational q);
        Rational operator* (Rational q);
        Rational operator/ (Rational q);
};

int Rational::get_denominator() {return d;}
int Rational::get_numerator () {return n;}
void Rational::print () {::print(n, "/", d, 0);}
int Rational::gcd (int a, int b) {return (b == 0) ? a : gcd (b, a % b);}

Rational::Rational (int n, int d)
{
    int g = gcd (n, d);
    if (g != 0) {
        this->n = n/g;
        this->d = d/g;
    }
    else {
        this->n = n;
        this->d = d;
    }
}

Rational::Rational(int n) {
    // n / 1 == n;
    this->n = n;
    d = 1;
}

Rational::Rational () {
    // 0 / 1 == 0;
    n = 0;
    d = 1;
}

Rational Rational::operator+ (Rational q) 
{
    return Rational (n * q.d + d * q.n, d * q.d);
}

Rational Rational::operator- (Rational q) 
{
    return Rational (n * q.d - d * q.n, d * q.d);
}

Rational Rational::operator* (Rational q)
{
    return Rational(n * q.n, d * q.d);
}

Rational Rational::operator/ (Rational q)
{
    return Rational(n * q.d, d * q.n);
}





int main ()
{
    Account a1(100), a2(200);
    print(a1.get_balance(), a2.get_balance(), 0);
    print(a1.withdraw(50), a2.withdraw(75), 0);
    Account* ap = new Account(1000);
    print(ap->get_balance());
    print(ap->withdraw(100));
    Account& a3 = *ap;
    print(a3.get_balance());
    a3.withdraw(30);
    print(ap->get_balance());
    delete ap;


    Random rand(93267);
    Experiment exp(rand);



    print(sqrt(6.0 / montecarlo(exp, 100000)));

    A a(10);
    print(a.get_a());

    B b(a, 5);
    print(b.get_a());
    b.set_a(2);
    print(a.get_a());
    print(b.get_a());

    B b2(11, 12);

    print(b2.get_a(), b2.get_b(), 0);

    // int summe() {return 0;}
    // int summe (int i) {return i; }
    // int summe (int i, int j) {return i + j;};
    // double summe (double a, double b) {return a + b;};

    int i[3];
    double x[2];
    short c = 5;

    i[0] = summe();
    i[1] = summe(3);
    i[2] = summe(i[0], i[1]);
    x[0] = summe(2.0, 3.0);
    x[1] = summe(x[0], 1.0);
    i[0] = summe(i[0], c);

    // class Incrementer
    // {
    //     private :
    //         int increment;
    //     public :
    //         Incrementer (int n) {increment = n;}
    //         int eval (int n) {return n + increment;}
    // };

    // void loop (Incrementer& incrementer)
    // {
    //     for (int i = 1; i < 10; i++) print(incrementer.eval(i));
    // }

    Incrementer inc(10);
    loop (inc);

    Rational p(12, 8), q(5, 3), r;

    p.print(); q.print(); r.print();
    r = (p + q * p) / (p * p);
    r.print();

    return 0;
}