template <class T> 
class Array
{
    public :
        typedef T MemberType; // remember the type
        class Iterator 
        {
            private :
                T* p; 
                Iterator (T* q) {p = q;}
            public :
                Iterator () {p = 0;}
                bool operator!= (Iterator x) {return (p != x.p)}
                bool operator== (Iterator x) {return (p == x.p)}
                Iterator operator++ () {p++; return *this;}
                Iterator operator++ (int)
                {
                    Iterator tmp = *this;
                    ++*this;
                    return tmp;
                }
                T& operator* () const {return *p;}
                T* operator-> () const {return p;}
                friend class Array<T>; 
        };
        Iterator begin() const
        Iterator end() const
        Array(int m) //constructor
        Array(const Array<T>&) //copy constructor
        ~Array() //destructor
        int size () const; //size of the array, i.e. number of elements.
        T& operator[](int i) 
    private :
        int n; // number of elements
        T* p // pointer to the built-in array

};