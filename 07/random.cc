#include "../code/fcpp.hh"

class Random {
    public: 
        Random (unsigned int begin);
        unsigned int get_number ();
    private:
        unsigned int x;
};

Random::Random (unsigned int begin)
{
    x = begin;
}

unsigned int Random::get_number()
{
    unsigned int ia = 16807, im = 2147483647;
    unsigned int iq = 127773, ir = 2836;
    unsigned int k = x/iq;
    x = ia * (x - k*iq) - ir*k;
    if (x < 0) x += im;
    return x;
}

class Experiment
{
    public:
        Experiment (Random& r);
        int carry_out ();
    private:
        Random& rg;
        unsigned int gcd(unsigned int a, unsigned int b);
};

Experiment::Experiment(Random& r) : rg(r) {};

unsigned int Experiment::gcd (unsigned int a, unsigned int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int Experiment::carry_out ()
{
    unsigned int x1 = rg.get_number();
    unsigned int x2 = rg.get_number();
    if (gcd(x1, x2) == 1) return 1;
    return 0;
}