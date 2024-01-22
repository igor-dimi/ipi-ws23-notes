#include "../code/fcpp.hh"

class Rational 
{
    private:
        int n, d;
        int gcd (int a, int b);
    public:
        int get_numerator();
        int get_denominator();

        Rational (int n, int d);
        Rational (int n);
        Rational ();

        Rational operator+ (Rational q);
        Rational operator- (Rational q);
        Rational operator* (Rational q);
        Rational operator/ (Rational q);

        void print ();
};

int Rational::get_numerator () {return n;}
int Rational::get_denominator () {return d;}
int Rational::gcd (int a, int b) {return (b == 0) ? a : gcd (b, a % b);}
void Rational::print () { ::print(n, "/", d, 0);}

Rational::Rational (int n, int d)
{
    int t = gcd(n, d);
    if (t != 0) {
        this->n = n/t;
        this->d = d/t;
    } else {
        this->n = n;
        this->d = d;
    }
}

Rational::Rational (int n) 
{
    this->n = n;
    d = 1;
}

Rational::Rational()
{
    n = 0;
    d = 1;
}

Rational Rational::operator+ (Rational q)
{
    return Rational( n * q.d + q.n * d, 
                        d * q.d);
}


Rational Rational::operator- (Rational q)
{
    return Rational( n * q.d - q.n * d, 
                        d * q.d);
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
    Rational p(3, 4), q(5, 3), r;
    p.print(); q.print();
    r = p + q;
    r.print();

    return 0;
}

