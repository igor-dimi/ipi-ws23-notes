#include <iostream>

struct Element
{
    Element* succ;
    int item;
};

struct List
{
    Element* head;
    int count;
};

void init_list(List* l)
{
    l->head = 0;
    l->count = 0;
}

//Insertion *after* Element pointed by 'location'
void insert(List* l, Element* location, Element* el)
{
    if (location == 0){
        el->succ = l->head;
        l->head = el;
    } else {
        el->succ = location->succ;
        location->succ = el;
    }
    l->count++;
}

// Deletion *after* the Element pointed by 'location'
Element* remove(List* l, Element* location)
{
    Element* el; // to be returned element;
    if (location == 0) {
        el = l->head;
        if (el != 0) {
            l->head = l->head->succ;
            l->count--;
        }
    }
    else {
        el = location->succ;
        if (el != 0) {
            location->succ = location->succ->succ;
            l->count--;
        }
    }
    return el;
}

Element* find(List* l, int val)
{
    Element* el = l->head;
    while (el != 0) {
        if (el->item == val) return el;
        el = el->succ;
    }
    return el;
}

void show(Element* el)
{
    if (el != 0) {
        if (el->succ != 0)
            std::cout << el->item << "->";
        else std::cout << el->item;
        show(el->succ);
    }
}

void show_list(List* l)
{
    std::cout << "count: " << l->count << std::endl << "list: ";
    show(l->head); 
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    List* l = new List;
    init_list(l);

    Element* el1 = new Element;
    Element* el2 = new Element;
    Element* el3 = new Element;
    Element* el4 = new Element;

    el1->item = 1;
    el2->item = 2;
    el3->item = 3;
    el4->item = 4;

    insert(l, 0, el1);
    insert(l, 0, el2);
    insert(l, 0, el3);
    insert(l, 0, el4);

    show_list(l);
    std::cout << std::endl;

    remove(l, find(l, 3));
    show_list(l);

    remove(l, find(l, 4));
    show_list(l);

    remove(l, find(l, 1));
    show_list(l);

    remove (l, 0);
    show_list(l);

    remove (l, 0);
    show_list(l);



    return 0;
}
