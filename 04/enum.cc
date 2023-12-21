#include <stdio.h>
#include "../code/fcpp.hh"

enum state {initial, used, old, broken};

void print_state(state s){
    if (s == initial) print("new");
    if (s == used) print("used");
    if (s == old) print("old");
    if (s == broken) print("broken");
}

int main()
{
    print_state(old);
}