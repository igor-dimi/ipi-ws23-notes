#ifndef SET_H
#define SET_H
#include "dl_list.hh"
template <class T>
class Set : private DL_list<T>
{
    public: 
        // default constructor & assignment is ok
        typedef typename DL_list<T>::Iterator Iterator;
        Iterator begin();
        Iterator end();

        bool empty();
        bool member (T item);
        void insert (T item);
        void remove (T item);
        void show();
};


#endif