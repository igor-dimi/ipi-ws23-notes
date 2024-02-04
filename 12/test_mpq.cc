#include "min_priority_queue.hh"
#include "min_priority_queue.cc"
#include "dl_list.hh"
#include "dl_list.cc"

int main(int argc, const char** argv) {
    MinPriorityQueue<int> mpq;
    int arr[5] = {1, 1, 2, 5, -2};
    for (int i = 0; i < 5; i++) mpq.push(arr[i]);
    mpq.show();
    mpq.pop();
    mpq.show();
    mpq.push(-99);
    mpq.show();
    while (!mpq.empty()) mpq.pop();
    mpq.show();
    return 0;
}