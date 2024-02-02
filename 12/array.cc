#include "array.hh"

//Iterator
template<class T>
typename Array<T>::Iterator Array<T>::begin() const
{return Iterator(p);}

template<class T>
typename Array<T>::Iterator Array<T>::end() const
{return Iterator(&(p[n]));}

// Constructor, Copy-constructor, Assignment and Destructor
template<class T>
Array<T>::Array(int m)
{
    n = m;
    p = new T[n];
}

// Copy-constructor
template<class T>
Array<T>::Array(const Array<T>& arr)
{
    n = arr.n;
    p = new T[n];
    for (int i = 0; i < n; i++) p[i] = arr.p[i];
}

// Assignment operator
template<class T> 
Array<T>& Array<T>::operator= (const Array<T>& arr)
{
    if(&arr != this) {
        if (n != arr.n) {
            delete[] p;
            n = arr.n;
            p = new T[n];
        }
        for (int i = 0; i < n; i++) p[i] = arr.p[i];
    }
    return *this;
}

// Destructor
template <class T>
Array<T>::~Array() {delete[] p;}

template <class T>
int Array<T>::size() const {return n;}

template<class T>
T& Array<T>::operator[](int i) {return p[i];}





