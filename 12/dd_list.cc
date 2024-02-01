#include "dd_list.hh"

template<class T>
typename DL_list<T>::Iterator DL_list<T>::insert (Iterator it, T item)
{
    Element* el = new Element(item);
    if (empty()) {
        assert(it.p == 0);
        head.p = tail.p = el;
    } else {
        el->next = it.p;
        if (it.p != 0) {
            el->prev = i.p->prev;
        }
    }
}


