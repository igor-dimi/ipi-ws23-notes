#include "float_arr02.hh"

FloatArr::FloatArr (int n, float val)
{
    this->n = n;
    try {
        p = new float[n];
    }
    catch (std::bad_alloc){
        n = 0;
        throw;
    }
    for (int i = 0; i < n; i++) p[i] = val;
}

FloatArr::~FloatArr() {delete[] p; }

int FloatArr::num_index () {return n;}

int FloatArr::min_index () {return 0;}

int FloatArr::max_index () {return n - 1;}

bool FloatArr::is_member(int i)
{
    return (i >= 0 && i < n);
}

float& FloatArr::operator[] (int i)
{
    return p[i];
}

FloatArr::FloatArr (const FloatArr& arr)
{
    this->n = arr.n;
    p = new float[n];
    for (int i = 0; i < n; i++) p[i] = arr.p[i];
}

FloatArr& FloatArr::operator= (const FloatArr& arr)
{
    if (&arr != this) {
        if ( this->n != arr.n) {
            delete[] p; 
            this->n = arr.n;
            p = new float[n];
        }
        for (int i = 0; i < n; i++) p[i] = arr.p[i];
    }
    return *this;
}

std::ostream& operator<< (std::ostream& os, FloatArr& arr)
{
    for (int i = arr.min_index(); i <= arr.max_index(); i++) os << arr[i] << " "; 
    return os;
}