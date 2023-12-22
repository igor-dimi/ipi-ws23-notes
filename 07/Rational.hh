
class Rational
{
    private:
        int numerator, denominator;
        int gcd (int a, int b);
    public:
        int get_numerator ();
        int get_denominator ();
        Rational (int numerator, int denominator);
        Rational (int num); //integer 
        Rational (); //Zero

        //output
        void print_rat();

        //operators
        Rational operator+ (Rational q);
        Rational operator- (Rational q);
        Rational operator* (Rational q);
        Rational operator/ (Rational q);

};