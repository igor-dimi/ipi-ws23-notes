#include "../code/fcpp.hh"

// 1. globale variablen
// 2. lokale variablen
// 3. dynamische variablen
//      - new
//      - delete

struct Person
{
    int age;
    int height;
};

int f(int age, int height)
{
    Person* pp = new Person;
    pp->age = age;
    pp->height = height;
    delete pp;
    return pp->age;
}

int main()
{
    Person* pp = new Person;
    pp->age = 10;
    pp->height = 120;
    
    int n = pp->age;
    print(n);
    delete pp;
    print(pp->age);
    int m = f(10, 100);
    print(m);
    return 0;
}

