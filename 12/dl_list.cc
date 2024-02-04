#include "dl_list.hh"
#include <cassert>
#include <iostream>

// implementing insertion **before** position pointed by 'it'. 
template<class T>
typename DL_list<T>::Iterator DL_list<T>::insert (Iterator it, T item)
{
    Element* el = new Element(item);
    if (empty()) { //list is empty
        assert(it.p == 0);
        head.p = tail.p = el;
    } else { // list is non empty
        el->next = it.p;
        if (it.p != 0) { //'it' doesn't point to end of list, insert before 'it'
            el->prev = it.p->prev;
            it.p->prev = el;
            // el->prev->next = el;
            if (head == it) head.p = el;
        } else { //it.p == 0, i.e. 'it' points to the end of list, insert el at the end
            el->prev = tail.p;
            tail.p->next = el;
            tail.p = el;
        }
    }
    return Iterator(el);
}


// Erase the list element at the position pointed by 'it'. 
template<class T>
void DL_list<T>::erase(Iterator it)
{
    if (it.p == 0) return;
    if (it.p->next != 0)
        it.p->next->prev = it.p->prev;
    if (it.p->prev != 0)
        it.p->prev->next = it.p->next;

    if (head == it) head.p = it.p->next;
    if (tail == it) tail.p = it.p->prev;

    delete it.p;
}

// append all elements of list to this list
template<class T>
void DL_list<T>::append(const DL_list<T>& list)
{
    for (Iterator it = list.begin(); it != list.end(); it++) 
        insert(end(), *it);

}

// is the list empty? 
template<class T>
bool DL_list<T>::empty() const {return begin() == end();}

// delete all lists elements, i.e. make list empty
template<class T>
void DL_list<T>::clear ()
{
    while (!empty()) erase(begin());
}

//Constructor 
template<class T> DL_list<T>::DL_list() {}

// copy constructor
template<class T> 
DL_list<T>::DL_list (const DL_list<T>& list) {append(list);}

// assignment operator
template<class T>
DL_list<T>& DL_list<T>::operator= (const DL_list<T>& list)
{
    if (this != &list) {
        clear();
        append(list);
    }
    return *this;
}

// Destructor 
template<class T> DL_list<T>::~DL_list() {clear();}

// Size method
template<class T> int DL_list<T>::size() const 
{
    int count = 0;
    for (Iterator it = begin(); it != end(); it++) count++;
    return count;
}



template<class T>
typename DL_list<T>::Iterator DL_list<T>::find(T item) const
{
    DL_list<T>::Iterator it = begin();
    while (it != end()) {
        if (*it == item) break;
        it++;
    }
    return it;
}

template<class T>
void DL_list<T>::show()
{
    for(DL_list::Iterator it = begin(); it != end(); it++) {
        if (it != end()) std::cout << *it << "->"; 
        else std::cout << *it;
    }
    std::cout << std::endl;
}