#include "dl_list.hh"

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
