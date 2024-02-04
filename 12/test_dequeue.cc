#include <iostream>
#include "dequeue.hh"
#include "dl_list.cc"

int main(int argc, char const *argv[])
{
    DeQueue<int> dq;
    for (int i = 0; i < 5; i++) dq.push_back(i);
    dq.show();
    std::cout << dq.pop_back() << std::endl;
    dq.show();
    std::cout << dq.pop_front() << std::endl;
    dq.show();
    std::cout << dq.front() << std::endl;
    // std::cout << dq.back() << std::endl;
    return 0;
}
