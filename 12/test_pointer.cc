#include <iostream>

struct Element
{
    Element* succ;
    int item;
};

struct List
{
    Element* head;
};


void show (Element* el)
{
    if (el != 0) {
        if (el->succ != 0)
            std::cout << el->item << "<-";
        else std::cout << el->item;
        show(el->succ);
    }
}

void show_list(List* l) {show(l->head); std::cout << std::endl;}


int main(int argc, char const *argv[])
{

    List* l = new List;
    Element *el1 = new Element;
    Element *el2 = new Element;
    Element *el3 = new Element;
    el1->item = 1;
    el2->item = 2;
    el3->item = 3;
    l->head = el1;
    el1->succ = el2;
    el2->succ = el3;

    show_list(l);

    // std::cout << el1->item <<std::endl;

    el1->succ = el1->succ->succ;

    // std::cout << el1->succ->succ->item << std::endl;

    show_list(l);

    Element head1;
    head1.item = 10; 
    head1.succ = 0;

    Element e1;
    e1.succ = 0;
    e1.item = 11;

    head1.succ = &e1;

    std::cout << head1.item << std::endl;

    List list;
    list.head = &head1;
    List* lp = &list;


    // List list;
    // List* lp = &list;
    // lp->head = &head1;

    show_list(lp);

    
    return 0;
}
