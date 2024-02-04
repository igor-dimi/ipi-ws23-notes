#include <cassert>
#include <iostream>

#include "stack.hh"
#include "dl_list.cc"

// template <class T>
// std::ostream& operator<< (std::ostream& stream, DL_list<T>& list)
// {
//     for (typename DL_list<T>::Iterator it = list.begin(); it != list.end(); it++) {
//         if (it != list.begin()) stream << " ";
//         stream << *it;
//     }
//     return stream;
// }

int main(int argc, char const *argv[])
{
    Stack<int> s1;
    for (int i = 1; i <= 5; i++) s1.push(i);
    std::cout << s1.empty() << std::endl;
    // s1.push(10);
    // s1.push(20);
    s1.show(); std::cout << std::endl;

    // std::cout << s1.top() << std::endl;


    // std::cout << s1.top() << " " << std::endl;

    // Stack<int> s2(s1);
    // while (!s2.empty()) {
    //     std::cout << s2.top() << std::endl;
    //     s2.pop();
    // } 

    return 0;
}
