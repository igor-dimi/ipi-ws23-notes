#include "array.hh"
#include "array.cc"
#include <iostream>
#include "../code/Zufall.cc"
#include "dl_list.hh"
#include "dl_list.cc"

template <class T>
std::ostream& operator<< (std::ostream& stream, Array<T>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        stream << arr[i] << " ";
    return stream;
}

template <class T>
std::ostream& operator<< (std::ostream& stream, DL_list<T>& list)
{
    for (typename DL_list<T>::Iterator it = list.begin(); it != list.end(); it++) {
        if (it != list.begin()) stream << " ";
        stream << *it;
    }
    return stream;
}

int main(int argc, char const *argv[])
{
    Zufall z(87124);
    Array<int> a(5);
    DL_list<int> l;

    for (int i = 0; i < 5; i++) a[i] = z.ziehe_zahl() % 100;
    for (int i = 0; i < 5; i++) 
        l.insert(l.end(), z.ziehe_zahl() % 100);

    std::cout << a << std::endl;
    std::cout << l << std::endl;

    for (Array<int>::Iterator i = a.begin(); i != a.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    for (DL_list<int>::Iterator i = l.begin(); i != l.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    return 0;
}
