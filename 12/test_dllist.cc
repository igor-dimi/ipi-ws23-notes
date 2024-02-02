#include "dl_list.hh"
#include "dl_list.cc"
#include <iostream>
#include "../code/Zufall.cc"

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
    DL_list<int> l1, l2;
    for (int i = 0; i < 5; i++) l1.insert(l1.end(), i);
    for (int i = 0; i < 10; i++) l2.insert(l2.end(), z.ziehe_zahl()%100);

    std::cout << l1 << std::endl << l2 << std::endl;
    std::cout << l2.size() << std::endl;

    l1.clear();
    l1.insert(l1.end(), 10);


    std::cout << l1 << std::endl;
    std::cout << l1.size() << std::endl;

    std::cout << l2 << std::endl;
    l2.erase(l2.find(68));
    std::cout << l2 << std::endl;
    l2.erase(l2.find(57));
    std::cout << l2 << std::endl;

    // list of lists
    DL_list<DL_list<int>> ll;
    ll.insert(ll.end(), l1);
    ll.insert(ll.end(), l2);

    std::cout << ll << std::endl;

    std::cout << ll.size() << std::endl;

    return 0;
}
