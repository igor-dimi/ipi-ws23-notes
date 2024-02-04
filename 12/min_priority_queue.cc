#include "min_priority_queue.hh"
#include <iostream>

template<class T>
void MinPriorityQueue<T>::push(T item) {this->insert(DL_list<T>::begin(), item);}

template<class T>
typename DL_list<T>::Iterator
MinPriorityQueue<T>::find_minimum() 
{
    typename DL_list<T>::Iterator min = DL_list<T>::begin();
    for (typename DL_list<T>::Iterator i = DL_list<T>::begin(); i != DL_list<T>::end(); i++)
        if (*i < *min) min = i;
    return min;
}


template<class T>
inline void MinPriorityQueue<T>::pop()
{
    this->erase(find_minimum());
}

template<class T>
inline T MinPriorityQueue<T>::top() {return *find_minimum();}

template<class T>
void MinPriorityQueue<T>::show()
{
    for (typename DL_list<T>::Iterator it = DL_list<T>::begin(); it != DL_list<T>::end(); it++)
        std::cout << *it << "<-";
    std::cout << std::endl;
}





