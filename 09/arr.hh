class Array 
{
    public: 
        Array(int n, float val); //new array with s elements I = [0, s-1]
        Array(const Array& arr); //copy constructor
        Array& operator= (const Array& arr); //assignment operator
        ~Array(); //destructor
        virtual float& operator[] (int i); //indexed access to array elements
        int num_index (); //cardinality of the index set I, i.e. number of elements
        int min_index (); //smallest index;
        int max_index (); //largest index;
        bool is_member (int i); //is the index in the set
    private :
        int n; //number of elements
        float* arr; //pointer to the built-in array
};