#include "../code/fcpp.hh"

enum State {neu, used, old, broken};

void printState(State x)
{
    if (x == neu) print("new");
    if (x == used) print("new");
    if (x == old) print("old");
    if (x == broken) print("broken");
}

int main(){printState(old); return 0;}