#include "list.hh"
#include "list.cc"
#include <iostream>

int main(int argc, const char** argv) {

    List<int> list;    

    list.insert(0, 17);
    list.insert(0, 25);
    list.insert(0, 17);

    for (List<int>::Link* l = list.first(); l != 0; l = l->next())
        std::cout << l->item << std::endl;

    int i = 2;
    for (List<int>::Link* l = list.first(); l != 0; l = l->next()) {
        l->item = i;
        i *= 2;
    }

    std::cout << std::endl;

    for (List<int>::Link* l = list.first(); l != 0; l = l->next())
        std::cout << l->item << std::endl;

    return 0;
}