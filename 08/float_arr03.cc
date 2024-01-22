#include "../code/fcpp.hh"
#include <iostream>
#include <stdio.h>

class SimpleArr
{
    public:
        SimpleArr(int n, float f); //new array with n elements, i.e. I = [0,n-1] 
        SimpleArr(const SimpleArr&);
        SimpleArr& operator= (const SimpleArr&);
        ~SimpleArr();

        virtual float& operator[](int i);
        int num_index (); //cardinality of the index set
        int min_index ();
        int max_index ();
        bool is_member(int i);

    private:
        int n; //number of elements
        float* p; //built in array
};

SimpleArr::SimpleArr(int n, float f)
{
    this->n = n;
    try {
        p = new float[n];
    }
    catch (std::bad_alloc) {
        n = 0;
        throw;
    }
    for (int i = 0; i < n; i++) p[i] = f;
}

SimpleArr::~SimpleArr () {delete[] p;}

SimpleArr::SimpleArr (const SimpleArr& arr)
{
    n = arr.n;
    p = new float[n];
    for (int i = 0; i < n; i++) p[i] = arr.p[i];
}

SimpleArr& SimpleArr::operator= (const SimpleArr& arr)
{
    if (&arr != this) {
        if (n != arr.n) {
            delete [] p;
            n = arr.n;
            p = new float[n];
        }
        for (int i = 0; i < n; i++) p[i] = arr.p[i];
    }
    return *this;
}

int  SimpleArr::num_index () {return n;}
int SimpleArr::min_index () {return 0;}
int SimpleArr::max_index () {return n - 1;}
bool SimpleArr::is_member (int i) {return (i >= 0 && i < n);}
float& SimpleArr::operator[] (int i) {return p[i];}

std::ostream& operator<< (std::ostream& s, SimpleArr& arr)
{
    for (int i = arr.min_index(); i < arr.max_index(); i++)
        s << arr[i] << " ";
    s << arr[arr.max_index()];
    return s;
}

int main()
{
    SimpleArr a(10, 0.0);
    SimpleArr b(5, 13.0);

    // for (int i = b.min_index(); i <= b.max_index(); i++) 
    //     printf("%f ", b[i]);
    // printf("\n");

    std::cout << a << "\n" << b << "\n";

    // b = a;

    // for (int i = b.min_index(); i <= b.max_index(); i++) 
    //     printf("%f ", b[i]);
    // printf("\n");

    return 0;
}