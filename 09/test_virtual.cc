#include <iostream>

class Animal 
{
    public :
        virtual void eat();
        void move();
};

void Animal::eat() {std::cout << "animals eat somehow \n";}

void Animal::move() {std::cout << "animals moves somehow\n";}

class Lion : public Animal
{
    public:
        void eat();
};

void Lion::eat() {std::cout << "lions eat meat\n";}

class Gazelle : public Animal
{
    public :
        void eat();
};

void Gazelle::eat() {std::cout << "gazelle's eat grass\n";}

void f1(Animal& a)
{
    a.eat();
}

void f2(Animal a)
{
    a.eat();
}

int main()
{
    Lion l;
    Gazelle g;
    // Animal& a1(l);
    // Animal& a2(g);

    // a1.eat();
    // a2.eat();

    // Animal a;
    // a.eat();
    // a.move();

    l.eat();
    l.move();
    g.eat();
    g.move();

    Animal* a1 = &l;
    Animal* a2 = &g;

    a1->eat();
    a2->eat();
    

    Animal& a3(l);
    Animal& a4(g);
    a3.eat();
    a4.eat();

    Animal a;


    std::cout << std::endl;
    std::cout << "calling f1\n";
    
    f1(l);
    f1(g);
    f1(a);

    std::cout << std::endl;
    std::cout << "calling f2\n";

    f2(l);
    f2(g);
    f2(a);

    std::cout << std::endl;
    std::cout << "declaring Animal a5(l) and a6(g) and calling a5.eat() & a6.eat():\n";
    Animal a5(l);
    Animal a6(g);
    a5.eat();
    a6.eat();

    return 0;
    
}