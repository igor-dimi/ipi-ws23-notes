#include "arr.hh"

class DynamicFloatArray : public Array
{
    private :
        int n; //number of elements
        int f; //first index value
        int l; //last index value
        float *p; //Pointer to the built in array
    public :
        virtual ~DynamicFloatArray();
        virtual float& operator[](int i);
        virtual int num_index();
        int min_index();
        int max_index();
        bool is_member(int i);
};

DynamicFloatArray::~DynamicFloatArray() {delete[] p;}
float& DynamicFloatArray::operator[](int i)
{
    if (i < f || i >= f + n) {
        //determine new size
        int ff, ll, nn;
        ff = f;
        ll = l;
        nn = n;
        if(i < f) {
            ff = i;
            nn = n + f - i;
        } else {
            ll = i;
            nn = i - f + 1;
        }
        //allocate new array
        float *q = new float[nn];
        // initialize and copy over
        for (int i = 0; i < nn; i++) q[i] = 0.0;
        for (int i = f; i < n; i++) q[i + f - ff] = p[i]; 
        // delete old array
        delete[] p;
        //remember new data;
        p = q;
        n = nn;
        f = ff;
    }
    return p[i - f];
}
int DynamicFloatArray::num_index() {return n;}
int DynamicFloatArray::min_index() {return f;}
int DynamicFloatArray::max_index() {return f + n - 1;}
bool DynamicFloatArray::is_member(int i) {return (i >= f) && (i < f + n);}