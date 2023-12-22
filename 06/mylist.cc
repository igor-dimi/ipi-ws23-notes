#include "../code/fcpp.hh"

struct List_el
{
    List_el* next;
    int value;
};

struct List
{
    int count;
    List_el* first;
};

void empty_list(List* l)
{
    l->first = 0;
    l->count = 0;
};

List_el* find(List l, int x)
{
    List_el* p;
    while (p){
        if (p->value == x) return p;
        p = p->next;
    }
    return 0;
}

void insert(List* l, List_el* loc, List_el* el)
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

List_el* remove(List* l, List_el* loc)
{
    List_el* p;
    if (loc == 0){
        p = l->first;
        if(p){
            l->first = p->next;
            (l->count)--;
        }
        return p;
    }
    p = loc->next;
    if(p){
        loc->next = p->next;
        (l->count)--;
    }
    return p;
}
