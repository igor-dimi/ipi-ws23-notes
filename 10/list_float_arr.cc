#include "arr.hh"

class ListFloatArray : public Array
{
    private :
        struct FloatListElem // local structure
        {
            FloatListElem* succ;
            int index;
            float value;
        };
        FloatListElem* insert(int i, float val); //insert new el at the beginning
        FloatListElem* find (int i);
        int n; // number of elements
        FloatListElem* head; // Beginning of the list
    public :
        ListFloatArray(); // Empty Array / list
        ~ListFloatArray(); //
        virtual float& operator[](int i);
        virtual int num_index();
        virtual int min_index(); 
        virtual int max_index();
        virtual bool is_member(int i);

};

//Insert an element with index i, coefficienet value val at the beginning
ListFloatArray::FloatListElem* ListFloatArray::insert(int i, float val)
{
    FloatListElem* q = new FloatListElem;

    q->index = i;
    q->value = val;
    q->succ = head;
    head = q;
    n++;
    return q;
}

//Find the address of the element with index i
ListFloatArray::FloatListElem* ListFloatArray::find(int i)
{
    for (FloatListElem* q = head; q != 0; q = q->succ)
        if(q->index == i) return q;
    return 0;
}

// Constructor, initialize everything empty
ListFloatArray::ListFloatArray()
{
    n = 0;
    head = 0;
}

// Destructor, delete all list elements
ListFloatArray::~ListFloatArray()
{
    FloatListElem* q;
    FloatListElem* p;
    q = p = head; //both q and p are initially the first element

    while (p != 0) {
        q = p;
        p = q->succ;
        delete q;
    }
}

float& ListFloatArray::operator[](int i)
{
    FloatListElem* r = find(i);
    if (r == 0) r = insert(i, 0.0);
    return r->value;
}

int ListFloatArray::num_index() {return n;}
int ListFloatArray::min_index()
{
    if (head == 0) return 0;
    int min = head->index;
    for (FloatListElem* q = head->succ; q != 0; q = q->succ)
        if (q->index < min) min = q->index;
    return min;
}

int ListFloatArray::max_index()
{
    if (head == 0) return 0;
    int max = head->index;
    for (FloatListElem* q = head->succ; q != 0; q = q->succ)
        if (q->index > max) max = q->index;
    return max;
}

bool ListFloatArray::is_member(int i) {return (find(i) != 0);}