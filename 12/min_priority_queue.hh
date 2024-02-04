#ifndef MINPQ_H
#define MINPQ_H
#include "dl_list.hh"

template <class T>
class MinPriorityQueue : public DL_list<T> 
{
    private :
        typename DL_list<T>::Iterator find_minimum();
    public :
        // Default constructors & assignemnts are ok
        bool empty() {return DL_list<T>::empty();}
        void push(T item);
        void pop();
        T top();
        void show();
};

#endif