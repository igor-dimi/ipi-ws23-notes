#include <iostream>

struct List
{
    List* succ;
    int item;
};

void show(List* l)
{
    if (l != 0) {
        if (l->succ != 0) 
            std::cout << l->item << "<-";
        else std::cout << l->item;
        show(l->succ); 
    }
}

int main(int argc, char const *argv[])
{
    List* head = new List;
    head->item = 10;
    List* el = new List;
    List* el2 = new List;
    el->item = 11;
    el2->item = 12;
    el->succ = el2;
    head->succ = el;

    

    show(head);
    std::cout << std::endl;

    return 0;
}
