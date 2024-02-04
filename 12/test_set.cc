#include "set.hh"
#include "set.cc"
#include "dl_list.cc"

int main(int argc, const char** argv) {
    Set<int> s, s2;
    int arr[5] = {1, 1, -2, 3, 0};
    for (int i = 0; i < 5; i++) s.insert(i);
    s.show();
    for (int i = 0; i < 10; i++) s2.insert(1);
    s2.show();
    return 0;
}
