#include "polynomial.hh"
// #include <iostream>

Polynomial::Polynomial (int n) : Array(n + 1, 0.0){}
float Polynomial::eval(float x)
{
    float sum = 0.0;
    for (int i = max_index(); i >= 0; i--)
        sum = sum * x + operator[](i);
    return sum;
}
int Polynomial::degree () {return max_index();};

Polynomial Polynomial::operator+ (Polynomial q)
{
    int n = degree(); //degree of the this polynomial
    if (q.degree() > n) n = q.degree();
    Polynomial r(n); //resulting polynomial
    for (int i = 0; i <= n; i++){
        if (i <= degree())
            r[i] += (*this)[i];
        if (i <= q.degree())
            r[i] += q[i];
    }
    return r;
}

// multiplication of polymomials
Polynomial Polynomial::operator* (Polynomial q)
{
    Polynomial r(degree() + q.degree()); //resutling polynomial
    for (int i = 0; i <= degree(); i++)
        for (int j = 0; j <= q.degree(); j++)
            r[i+j] += (*this)[i] * q[j];
    return r;
}

// void Polynomial::print ()
// {
//     if (degree() < 0) std::cout << 0;
//     else std::cout << (*this)[min_index()];
//     for (int i = min_index() + 1; i <= max_index(); i++)
//         std::cout << " + " << (*this)[i] << "*x^" << i;
// }

bool Polynomial::operator== (Polynomial q)
{
    if (q.degree() > degree()) {
        for (int i = 0; i <= degree(); i++)
            if ((*this)[i] != q[i]) return false;
        for (int i = degree() + 1; i <= q.degree(); i++)
            if (q[i] != 0.0) return false;
    } else {
        for (int i = 0; i <= q.degree(); i++)
            if ((*this)[i] != q[i]) return false;
        for (int i = q.degree() + 1; i<=degree(); i++)
            if ((*this)[i] != 0.0) return false;
    }
    return true;
}
