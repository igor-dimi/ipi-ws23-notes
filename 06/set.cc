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

void create_list(List* l)
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


struct Set
{
    List list;
};

Set* create_set()
{
    Set* s = new Set;
    create_list(&(s->list));
    return s;
}

bool is_el(Set* s, int x)
{
    for (List_el* p = (s->list).first; p; p = p->next)
        if (p->value == x) return true;
    return false;
}

void insert_el(Set* s, int el)
{
    if(!is_el(s, el)){
        List_el* p = new List_el;
        p->value = el;
        insert(&(s->list), 0, p);
    }
}

void remove_el(Set*s, int el)
{
    if ((s->list).first == 0) return;
    if ((s->list).first->value == el){
        List_el* p = remove(&(s->list), 0);
        delete p;
        return;
    }
    //search in the list, test the successor of the current element
    //apply the list removing operation on the current element, thus deleting the necessary value
    for (List_el* p = (s->list).first; p; p = p->next)
        if (p->next->value == el){
            List_el* q = remove(&(s->list), p);
            delete q;
            return;
        }
}

void print_set(Set* s)
{
    print("(");
    for (List_el* p = (s->list).first; p; p = p->next)
        print("--", p->value, 0);
    print(")");
}

int main()
{
    Set* s = create_set();
    print_set(s);
    for (int i = 1; i < 12; i++) insert_el(s, i);
    print_set(s);
    for (int i = 5; i < 15; i++) remove_el(s, i);
    print_set(s);
    return 0;
}