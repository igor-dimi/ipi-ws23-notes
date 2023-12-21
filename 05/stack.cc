#include "../code/fcpp.hh"

typedef int element_type;

const int SIZE = 1000;

element_type stack[SIZE];
int top = 0; 

bool is_empty(){return top == 0;}

void push(element_type e) {stack[top++] = e;}

element_type pop () {return stack[--top];}


int main()
{
    push(4);
    push(5);
    push(10);
    while (!is_empty()) print(pop());
}