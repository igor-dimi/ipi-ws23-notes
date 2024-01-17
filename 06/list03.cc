#include "../code/fcpp.hh"
#include <stdio.h>

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

ListEl* remove_list(List* l, ListEl* pos)
{
    ListEl* el;
    if (pos == 0){ //remove from the beginning
        el = l->head;
        if (el != 0) {
            l->head = l->head->succ;
            l->count--;
        }
    }
    else {
        el = pos->succ;
        if (el != 0) {
            pos->succ = pos->succ->succ;
            l->count--;
        }
    }
    return el;
}

void print_list_el(ListEl* el)
{
    if (el == 0) return;
    printf("%d", el->val);
    printf("->");
    print_list_el(el->succ);
    // print(el->val);
    // print("->");
    // print_list_el(el->succ);
    
}

void print_list(List* l)
{
    if (l->head == 0) return;
    print_list_el(l->head);
}

int main()
{
    List l;
    ListEl le1;
    ListEl le2;
    ListEl le3;
    ListEl le4;
    ListEl le5;
    le1.val = 10;
    le2.val = 13;
    le3.val = 7;
    le4.val = 20;
    le5.val = 17;
    make_empty_list(&l);
    insert(&l, 0, &le1); 
    insert(&l, 0, &le2);
    insert(&l, 0, &le3);
    insert(&l, 0, &le4);
    ListEl* loc = find(l, 7);
    insert(&l, loc, &le5);
    ListEl* loc2 = find(l, 17);
    remove_list(&l, loc2);
    print_list(&l);
    print("");
    return 0;
}

