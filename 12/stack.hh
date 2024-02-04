#include "dl_list.hh"

template <class T>
class Stack : private DL_list<T>
{
    public :
        // Default Constructors & assignment is ok.
        bool empty() {return DL_list<T>::empty();}
        void push (T item) 
        {
            // this->insert(DL_list<T>::begin(), item);
            this->insert(DL_list<T>::begin(), item);
        }
        T top() {return *DL_list<T>::begin();}
        void pop () {this->erase(DL_list<T>::begin());}
        void show() {DL_list<T>::show();}
};

