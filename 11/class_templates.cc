#include <iostream>

template <class T> class Array
{
    private:
        int n;
        T* arr; //pointer to array of type T
    public :
        Array(int n, T val);
        Array(const Array<T>&);
        Array<T>& operator= (const Array<T>&);
        ~Array();

        T& operator[](int i);
        int num_index();
        int min_index();
        int max_index();
        bool is_member(int i);
};

// Destructor
template <class T> 
Array<T>::~Array() {delete[] arr;}

// Constructor
template <class T>
Array<T>::Array(int _n, T val)
{
    n = _n;
    arr = new T[n];
    for (int i = 0; i < n; i++) arr[i] = val;
}

// Copy-constructor
template <class T>
Array<T>::Array(const Array<T>& a)
{
    n = a.n;
    arr = new T[n];
    for (int i = 0; i < n; i++) arr[i] = a.arr[i];
}

// Assignment operator
template<class T> 
Array<T>& Array<T>::operator= (const Array<T>& a)
{
    if (&a != this) {
        if (n != a.n) {
            delete [] arr;
            n = a.n;
            arr = new T[n];
        }
        for (int i = 0; i < n; i++) arr[i] = arr.p[i];
    }
    return *this;
}

template <class T>
T& Array<T>::operator[] (int i)
{
    return arr[i];
}

template<class T>
inline int Array<T>::num_index() {return n;}

template <class T>
inline int Array<T>::min_index() {return 0;}

template <class T>
inline int Array<T>::max_index() {return n - 1;}

template <class T>
inline bool Array<T>::is_member(int i) {return (i >= 0 && i < n);}

template <class T>
std::ostream& operator<< (std::ostream& stream, Array<T>& a)
{
    for (int i = a.min_index(); i <= a.max_index(); i++)
        stream << a[i] << " ";
    stream << std::endl;
    return stream;
}

int main()
{
    // not everyone has the same path in life ...
    Array<int>a(10, 1);
    Array<float>b(5, 0.3);
    std::cout << a << b;
    return 0;
}