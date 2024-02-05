#include <vector>
#include <iostream>

#include "heap.hh"
#include "../code/Zufall.cc"

template <class T>
std::ostream& operator<< (std::ostream& stream, std::vector<T> v)
{
    for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
        stream << *it << " ";
    stream << std::endl;
    return stream;
}

int main(int argc, const char** argv) {
    Zufall z(87123);
    Heap<int> h;

    for (int i = 0; i < 10; i++) {
        int k = z.ziehe_zahl() % 100;
        std::cout << k << std::endl;
        h.push(k);
    }

    std::cout << std::endl;
    while (!h.empty()) {
        std::cout << h.top() << std::endl;
        h.pop();
    }

    std::vector<int> v;
    for (int i = 0; i < 5; i++) v.push_back(i);
    std::cout << "v: " << v;
    std::cout << "size: " << v.size() << std::endl;
    int i = v.size();
    v.push_back(10);
    std::cout << v[i] << std::endl;

    return 0;
}