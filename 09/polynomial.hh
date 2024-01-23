#include "arr.hh"

class Polynomial : public Array { //class Polynomial inherits from class Array
    public :
        Polynomial (int n); //Constructor for a polynom of degree n
    int degree (); //degree of the polynom
    float eval (float x);  //evaluation of the polynom at a value x
    Polynomial operator+ (Polynomial q); //Addition of two polynoms;
    Polynomial operator* (Polynomial q); //Multiplication of two polynoms;
    bool operator== (Polynomial q); //equivalence of two polynomials
    void print(); //print out a polynom
};