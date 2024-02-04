#include <iostream>
#include "queue.hh"
#include "dl_list.cc"

int main(int argc, char const *argv[])
{
    Queue<int> q;
    for (int i = 1; i < 5; i++) q.push(i);
    q.show(); 
    q.pop();
    q.show(); 
    q.push(11);
    q.show();
    for (int i = 1; i < 3; i++) q.pop();
    q.show();

    return 0;
}
