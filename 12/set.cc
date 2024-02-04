#include "set.hh"
#include <iostream>

template<class T>
typename Set<T>::Iterator Set<T>::begin() {return DL_list<T>::begin();}

template<class T>
typename Set<T>::Iterator Set<T>::end() {return DL_list<T>::end();}

template<class T>
bool Set<T>::empty() {return DL_list<T>::empty();}

template<class T>
inline bool Set<T>::member(T item) {return DL_list<T>::find(item) != DL_list<T>::end();}

template<class T>
inline void Set<T>::insert (T item)
{
    if(!member(item)) DL_list<T>::insert(DL_list<T>::begin(), item);
}

template<class T>
inline void Set<T>::remove(T item)
{
    typename DL_list<T>::Iterator i = find(item);
    if(i != DL_list<T>::end()) erase(i);
}

template<class T>
void Set<T>::show()
{
    std::cout << "{";
    for (Iterator it = begin(); it != end(); it++)
        std::cout << *it << ", "; 
    std::cout << "}";
    std::cout << std::endl;
}


