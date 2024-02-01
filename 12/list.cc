#include "list.hh"

template <class T>
List<T>::~List()
{
    Link* p = _first;
    while (p != 0) {
        Link* q = p;
        p = p->next();
        delete q;
    }
}

template <class T>
void List<T>::insert (List<T>::Link* where , T item)
{
    Link* el = new Link(item);
    if (where == 0) {
        el->_next = _first;
        _first = el;
    } else {
        el->_next = where->_next;
        where->_next = el;
    }
}

template <class T>
void List<T>::remove (List<T>::Link* where)
{
    Link* p;
    if (where == 0) {
        p = _first;
        if (p != 0) _first = p->_next;
    }
    else {
        p = where->_next;
        if (p != 0) where->_next = p->_next;
    }
    delete p;
}

