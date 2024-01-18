#include "../code/fcpp.hh"
#include <stdio.h>


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

struct Set
{
    List list;
};

Set* make_empty_set()
{
    Set* s = new Set;
    make_empty_list(&(s->list));
    return s;
}

bool is_el(Set* s, int val)
{
    for (ListEl* el = s->list.head; el != 0; el = el->succ)
        if (el->val == val) return true;
    return false;
}

void insert_in_set(Set* s, int val)
{
    if (!is_el(s, val)){
        ListEl* el = new ListEl;
        el->val = val;
        insert(&s->list, 0, el);
    }
}

void remove_from_set(Set* s, int val)
{
    if (s->list.head == 0) return;
    if (s->list.head->val == val){
        ListEl* el = remove_list(&s->list, 0);
        delete el;
        return;
    }
    // Search in list, always test the successor
    for (ListEl* el = s->list.head; el->succ != 0; el = el->succ)
        if (el->succ->val == val){
            ListEl* p = remove_list(&s->list, el);
            delete p;
            return;
        }
    
}

void print_set(Set* s)
{
    printf("{");
    for (ListEl* el = s->list.head; el != 0; el = el->succ)
        // print(el->val);
        printf("%d, ", el->val);
    printf("}");
}



int main()
{
    Set* s = make_empty_set();
    // insert_in_set(s, 10);
    // insert_in_set(s, 11);
    // insert_in_set(s, 20);
    // insert_in_set(s, 19);
    // print_set(s); 
    // print("");
    // remove_from_set(s, 11);
    // print_set(s);
    // print("");
    // for (int i = 3; i < 100000; i *= 5)
    //     insert_in_set(s, (17137 * i) % 47);
    // print_set(s);
    // print("");

    int user_input;
    do {
        //print set
        print("count:", s->list.count, 0);
        printf("set: "); print_set(s);
        print("");

        //print menu option
        print("[1] add element");
        print("[2] remove element");
        print("[3] exit");

        //scan user input & perform operation
        scanf("%d", &user_input);
        switch(user_input) {
            case 1 :
                int val1;
                scanf("%d", &val1);
                insert_in_set(s, val1);
                break;
            case 2 :
                int val2;
                scanf("%d", &val2);
                remove_from_set(s, val2);
                break;
            case 3 :
                break;
            default :
                print("invalid menu option!");
                break;
        }
        
    } while(user_input != 3);

}