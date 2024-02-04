#ifndef QUE_H
#define QUE_H
#include "dl_list.hh"
#include <iostream>

template<class T>
class Queue : private DL_list<T> 
{
    public :
        // Default constructors & assignment are ok;
        bool empty () {return empty();}
        T front() {return *DL_list<T>::begin();}
        T back() {return *DL_list<T>::rbegin();}
        void push (T item) {this->insert(DL_list<T>::end(), item);}
        void pop () {this->erase(DL_list<T>::begin());}
        void show (); 
};

template <class T>
void Queue<T>::show()
{
    for (typename Queue::Iterator it = Queue<T>::begin(); it != Queue<T>::end(); it++)
        std::cout << *it << "<-";
    std::cout << std::endl;
}

#endif
