#include <stdio.h>
#include "../code/fcpp.hh"

struct Person
{
    int age;
    int height;
};

int main()
{
    Person p;
    Person* pp = &p;
    (*pp).age = 10;
    pp->height = 100;

    print(pp->age, pp->height, 0);

    return 0;
}
