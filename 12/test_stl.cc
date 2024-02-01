#include <iostream>
#include <vector>
#include <array>
#include <list>


template <typename T>
void show(const T& container)
{
    for (int i = 0; i < container.size(); i++) std::cout << container[i] << " ";
    std::cout << std::endl;
}

// template <typename T>
// void show2(const T& container)
// {
//     for (T::iterator it = x.begin(); x != x.end(); ++it)
//         std::cout << *it << " ";
//     std::endl;
// }

template <class T>
void fill(T& container)
{
    for (int i = 0; i < container.size(); i++) container[i] = i;
}

int main()
{
    std::vector<int> x(10, 1);
    for (int i = 0; i < x.size(); i++) std::cout << x[i] << " ";
    std::cout << std::endl;
    std::vector<int> y(0);

    for (int i = 0; i < 10; i++) y.push_back(i);
    std::cout << "size y: " << y.size() << std::endl;

    for (int i = 0; i < y.size(); i++) std::cout << y[i] << " ";
    std::cout << std::endl;

    std::array<int, 10> a;
    std::array<double, 5> b;

    std::cout << "size of a: " << a.size() << std::endl;
    std::cout << "size of b: " << b.size() << std::endl;

    std::list<int> l;
    for (int i = 0; i < 10; i++) l.push_back(i);

    fill(a);
    fill(b);

    show(x);
    show(y);
    show(a);
    show(b);
    // show(l);

    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        *it *= *it;
        
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        *it *= *it;

    std::list<int>::iterator it2 = l.begin();
    // ++it2;

    l.insert(it2, 18);

    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}