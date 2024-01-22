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

int  SimpleArr::num_index () {return n;}
int SimpleArr::min_index () {return 0;}
int SimpleArr::max_index () {return n - 1;}
bool SimpleArr::is_member (int i) {return (i >= 0 && i < n);}
float& SimpleArr::operator[] (int i) {return p[i];}

int main()
{
    return 0;
}