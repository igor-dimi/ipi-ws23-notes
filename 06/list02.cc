#include <stdio.h>
#include "../code/fcpp.hh"
#include <iostream>

struct List_el
{
    List_el* succ;
    int val;
};

struct List
{
    int count;
    List_el* head;
};

void init_list(List* l)
{
    l->count = 0;
    l->head = 0;
}

void insert(List* l, List_el* loc, List_el* el)
{
    if (loc == 0){
        el->succ = l->head;
        l->head = el;
        (l->count)++;
    } 
    else {
        el->succ = loc->succ;
        loc->succ = el;
        (l->count)++;
    }
}

void remove(List* l, List_el* el)
{
    if (el == l->head){
        l->head = l->head->succ;
    }
    else { //find element before el;
        for (List_el* p = l->head; p != 0; p = p->succ)
            if (p->succ == el)
                p->succ = el->succ;
    }
    l->count--;
}

//returns the adderss of first element with the value 'val' in the list 'l'.
List_el* find(List l, int val)
{
    for (List_el* p = l.head; p != 0; p=p->succ)
        if (p->val == val) return p;
    return 0;
}

struct Set
{
    List list; 
};

Set* create_set()
{
    Set* s = new Set;
    init_list(&(s->list));
    return s;
}

bool exists(int val, Set* s)
{
    if(find(s->list, val))
        return true;
    return false;
}

void insert_in_set(Set* s, int val)
{
    if (!exists(val, s)){
        List_el* p = new List_el;
        p->val = val;
        insert(&(s->list), 0, p);
    }
}

void remove_from_set(Set* s, int val)
{
   List_el* el = find(s->list, val);
   if (el != 0) remove(&s->list, el);
   delete el;
}

void print_set(Set* s)
{
    print("{");
    for (List_el* p = s->list.head; p != 0; p=p->succ)
        print("  ", p->val, 0);
    print("}");
}

void print_menu()
{
    print("[1] add element");
    print("[2] remove element");
    print("[3] exit");
}

int main()
{
    Set* s = create_set();
    int input;

    do {
        print("");
        print("Set: ");
        print_set(s);
        print("");
        print_menu();
        print("");
        scanf("%d", &input);
        switch (input){
            int val;
            case 1 :
                scanf("%d", &val);
                insert_in_set(s, val);
                break;
            case 2 :
                scanf("%d", &val);
                remove_from_set(s, val);
                break;
            case 3 :
                break;
            default :
                print("invalid option");
        }
    } while (input != 3);
}
