#include <new>
#include <iostream>

class FloatArr {
    public :
        FloatArr (int n, float val); //constructor
        FloatArr (const FloatArr&); //copy constructor
        FloatArr& operator= (const FloatArr&);
        ~FloatArr();
        virtual float& operator[](int i);
        int num_index();
        int min_index();
        int max_index();
        bool is_member (int i);
        friend std::ostream& operator << (std::ostream& os, FloatArr& arr);
    private :
        int n; //number of elements
        float* p;  //pointer to the built in array
};