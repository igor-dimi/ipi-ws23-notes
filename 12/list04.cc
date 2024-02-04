#include <iostream>


class List
{
    struct Element
    {
        Element* succ;
        int item;
        // Element(int _item){item = _item; succ = 0;}
    };

    private :
        Element* head;
        int count;
        int find(int item);
    public :
        List();
        ~List();
        void insert(int item, int pos);
        void remove(int pos);
        int size() {return count;}
        int& operator[] (int i);
        int get_item(int pos);
        virtual void show();
        virtual void show_size();
        bool empty() {return count == 0;}
};

List::List()
{
    head = 0;
    count = 0;
}

List::~List()
{
    while (count > 0) {
        remove(count-1);
    }
}

void List::insert(int _item, int _pos)
{
    Element* el = new Element;
    el->item = _item;
    el->succ = 0;
    
    if (count == 0) { //list is empty, ignore _pos and insert at the beginning
        head = el;
    }

    else if (_pos == -1) {//insert before first element
        el->succ = head;
        head = el;
    }
    else {
        _pos %= count;
        Element* location = head;
        int pos = 0;

        while (pos != _pos) {
            location = location->succ;
            pos++;
        }
        el->succ = location->succ;
        location->succ = el;
    }
    count++;
}

void List::remove(int _pos)
{
    if (count > 0) {
        if (_pos > 0) {
            _pos %= count;
            Element* location = head;
            Element* location_prev = head;
            int pos = 0;
            while (pos != _pos) {
                location = location->succ;
                pos++;
            }
            while (location_prev->succ != location)
                location_prev = location_prev->succ;
            location_prev->succ = location->succ;
            delete location;
        } else if (_pos == 0) {
            Element* p = head;
            head = head->succ;
            delete p;
        }
        count--;
    }    
}

int& List::operator[] (int i)
{
    int pos = 0;
    Element* el = head;
    while (pos != i % count) {
        el = el->succ;
        pos++;
    }
    return el->item;
}

int List::get_item(int i)
{
    int pos = 0;
    Element* el = head;
    while (pos != i % count) {
        el = el->succ;
        pos++;
    }
    return el->item;
}

void List::show()
{

    if (count != 0) {
        Element* el = head;
        while (el != 0) {
            if (el->succ != 0) std::cout << el->item << "->";
            else std::cout << el->item;
            el = el->succ;
        }
    }
}

void List::show_size()
{
    std::cout << "size: " << size() << std::endl;
    std::cout << "list: "; show();
    std::cout << std::endl;
}



void remove_first (List& l) {l.remove(0);}
void remove_last (List& l) {l.remove(l.size()-1);}


class Stack : private List
{
    public: 
        Stack() : List() {}
        void pop() {List::remove(size()-1);}
        void push(int item) {List::insert(item, size() - 1);}
        int top() {return this->List::operator[](List::size() - 1);}
        int size() {return List::size();}
        void show() {List::show();} 
        void show_size();
        bool empty() {return List::empty();}

};

void Stack::show_size()
{
    std::cout << "size: " << size() << std::endl;
    std::cout << "stack: "; show();
    std::cout << std::endl;
}


int main(int argc, char const *argv[])
{
    List l;
    std::cout << l.size() << std::endl;
    l.show_size();
    l.insert(10, -1);
    l.show_size();
    std::cout << std::endl;
    // l.insert(10, -1);
    for (int i = 0; i < 5; i++) l.insert(i, -1);
    l.show_size();
    std::cout << std::endl;
    l.insert(-3,2);
    l.show_size();
    std::cout << std::endl;

    l.remove(3);
    l.show_size();
    std::cout << std::endl;


    l.remove(1);
    l.show_size();

    l.remove(0);
    l.show_size();

    while(!l.empty()) l.remove(0);
    l.show_size();

    for (int i = 0; i < 10; i++) l.insert(i, -1);
    l.show_size();
    remove_first(l);
    l.show_size();
    remove_last(l);
    l.show_size();

    std::cout << l[3] << std::endl;

    // List l2;
    // l2.insert(10, -1);
    // l2.show();
    // l2.insert(10, 20);
    // std::cout << l2.size() << std::endl;

    // List l3;
    // std::cout << l2.size() << std::endl;

    Stack s1;
    for (int i = 0; i < 10; i++) s1.push(i);
    s1.show_size();

    s1.pop();
    s1.show_size();
    for (int i = 0; i < 2; i++) s1.pop();
    s1.show_size();
    while (!s1.empty()) s1.pop();
    s1.show_size();
    s1.push(-2);
    s1.push(-4);
    s1.show_size();
    return 0;
}
