#ifndef PTR_H
#define PTR_H
template <class T>
class Pointer {
    struct Reference_cnt {
        int count;
        T* obj;
        Reference_cnt(T* q) {count = 1; obj = q;} // Constructor for the struct 
    };
    Reference_cnt* p;

    void report ()
    {
        std::cout << "refcnt = " << p->count << std::endl; 
    }
    void increment () 
    {
        p->count++;
        report ();
    }
    void decrement () 
    {
        p->count--;
        report();
        if (p->count == 0) {
            delete p->obj; // this notation doesn't cover cases when obj is an array
            delete p;
        }
    }

    public :
        Pointer () {p = 0;} // Default Constructor constructs an empty object 
        Pointer (T* q)  // constructor with a pointer to an Object of type T
        {
            p = new Reference_cnt(q); // The struct Reference_cnt is initialized 
            //with count == 1 and pointer to an object of type T
            report();
        }
        Pointer(const Pointer<T>& y) //Copy constructor
        {
            p = y.p;
            if (p != 0) increment();
        }
        ~Pointer()
        {
            if (p != 0) decrement();
        }
        Pointer<T>& operator= (const Pointer<T>& y)
        {
            if (p != y.p) {
                if (p != 0) decrement();
                p = y.p;
                if (p != 0) increment();
            }
            return *this;
        }
        T& operator* () {return *(p->obj);}
        T* operator-> () {return p->obj;}
};
#endif // !PTR_H
