#include "arr.cc"

class CheckedArray : public Array 
{
   public :
    CheckedArray (int n, float val);
    float& operator[](int i);
};