#include "../code/fcpp.hh"

struct list_el
{
    list_el* next;
    int value;
}

struct list
{
    int count;
    list_el* first;
}

void empty_list(list* l)
{
    l->first = 0;
    l->count = 0;
}

list_el* find(list l, int x)
{
    list_el* p;
    while (p){
        if (p->value == x) return p;
        p = p->next;
    }
    return 0;
}

void insert(list* l, list_el* loc, list_el* el)
{
    if (loc == 0){
        el->next = l->first;
        l->first = el;
        (l->count)++;
    } else {
        el->next = loc->next;
        loc->next = el;
        (l->count)++;
    }
}

