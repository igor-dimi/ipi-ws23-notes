#ifndef DEQ_H
#define DEQ_H
#include "dl_list.hh"
#include <iostream>

template <class T>
class DeQueue : private DL_list<T>
{
    public :
        // Default constructors & assignment is ok
        bool empty() {return DL_list<T>::empty();}
        void push_front(T item) {this->DL_list<T>::insert(DL_list<T>::begin(), item);}
        void push_back (T item) {this->DL_list<T>::insert(DL_list<T>::end(), item);}
        T pop_front();
        T pop_back();
        T front() {return *DL_list<T>::begin();}
        T back() {return *DL_list<T>::rend();}
        void show();
};

template <class T>
T DeQueue<T>::pop_front()
{
    typename DeQueue::Iterator it = DeQueue<T>::begin();
    T item = *it;
    this->erase(it);
    return item;
}

template <class T>
T DeQueue<T>::pop_back()
{
    typename DeQueue::Iterator it = DeQueue<T>::rbegin();
    T item = *it;
    this->erase(it);
    return item;
}

template <class T>
void DeQueue<T>::show()
{
    for (typename DeQueue::Iterator it = DeQueue<T>::begin(); it != DeQueue<T>::end(); it++)
        std::cout << *it << "<->";
    std::cout << std::endl;
}

#endif
