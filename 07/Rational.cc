#include "../code/fcpp.hh"

int Rational::get_numerator (){return numerator;}
int Rational::get_denominator () {return denominator;};

void Rational::print_rat() {print(numerator, "/", denominator, 0);}

int Rational::gcd( int a, int b) {return (b == 0) ? a : gcd(b, a%b);}

//constructors
Rational::Rational (int numerator, int denominator)
{
    int d = gcd (numerator, denominator);
    if (d != 0){
        this->numerator = numerator / d;
        this->denominator = denominator / d;
    } else {
        this->numerator = numerator;
        this->denominator = denominator;
    }
}
Rational::Rational (int num)
{
    numerator = num;
    denominator = 1;
}

Rational::Rational () 
{
    numerator = 0;
    denominator = 1;
}

// Operatoren
Rational Rational::operator+ (Rational q) 
{
    return Rational (numerator * q.denominator + 
        q.numerator * denominator, 
        denominator * q.denominator);
}

Rational Rational::operator- (Rational q)
{
  return Rational (numerator * q.denominator - 
        q.numerator * denominator, 
        denominator * q.denominator);
}

Rational Rational::operator* (Rational q)
{
    return Rational(
        numerator * q.numerator, denominator * q.denominator
    );
}

Rational Rational::operator/ (Rational q)
{
    return Rational(
        numerator * q.denominator, denominator * q.numerator
    );
}

