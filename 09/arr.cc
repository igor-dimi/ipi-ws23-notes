#include "arr.hh"

Array::Array(int n, float val)
{
    this->n = n;
    arr = new float[n];
    for (int i = 0; i < n; i++) arr[i] = val;
}

Array::~Array () {delete[] arr;};
int Array::num_index () {return n;}
int Array::min_index () {return 0;}
int Array::max_index () {return n - 1;}
bool Array::is_member(int i) {return (i >= 0 && i < n);}
float& Array::operator[] (int i) {return arr[i];}
Array::Array(const Array& a)
{
    n = a.n;
    arr = new float[n];
    for (int i = 0; i < n; i++)
        arr[i] = a.arr[i];
}
Array& Array::operator= (const Array& a)
{
    if (&a != this) {
        if (n != a.n) {
            delete [] arr;
            n = a.n;
            arr = new float[n];
        }
        for (int i = 0; i < n; i++) arr[i] = a.arr[i];
    }
    return *this;
}
