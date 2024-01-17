#include "../code/fcpp.hh"

// erzeugen einer leeren liste
// einfuegen von elementen an beliebiger Stelle
// Entfernen von Elementen
// Durchsuchen einer Liste

struct ListEl
{
    int val;
    ListEl* succ;
};

struct List
{
    int count;
    ListEl* head;
};

void make_empty_list(List* l)
{
    l->head = 0;
    l->count = 0;
}

ListEl* find(List l, int val)
{
    ListEl* el = l.head;
    while (el->val != val && el != 0) el = el->succ;
    // el->val == val || el == 0 <=> el->val != val => el == 0;
    return el;
}

void insert(List* l, ListEl* pos, ListEl* el)
{
    if (pos == 0){ //insert at the beginning of the list
        el->succ = l->head;
        l->head = el;
        l->count++;
    }
    else {
        el->succ = pos->succ;
        pos->succ = el;
        l->count++;
    }
}

