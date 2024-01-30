#include <iostream>

class Animal 
{
    public :
        virtual void eat();
        void move();
};

void Animal::eat() {std::cout << "animals eat somehow \n";}

void Animal::move() {std::cout << "animals move somehow\n";}

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

void Gazelle::eat() {std::cout << "gazelles eat grass\n";}  

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

    std::cout << "l.eat(): " << std::endl;
    l.eat();
    std::cout << "l.move(): " << std::endl;
    l.move();
    std::cout << std::endl;

    std::cout << "g.eat(): " << std::endl;
    g.eat();
    std::cout << "g.move(): " << std::endl;
    g.move();
    std::cout << std::endl;

    Animal* a1 = &l;
    Animal* a2 = &g;

    std::cout << "Animal* a1 = &l; a1->eat(): " << std::endl;
    a1->eat();
    std::cout << std::endl;

    std::cout << "Animal* a2 = &l; a2->eat(): " << std::endl;
    a2->eat();
    std::cout << std::endl;

    

    Animal& a3(l);
    Animal& a4(g);
    
    std::cout << "Animal& a3(l); a3.eat();" << std::endl;
    a3.eat();
    std::cout << std::endl;

    std::cout << "Animal& a4(l); a4.eat();" << std::endl;
    a4.eat();
    std::cout << std::endl;

    Animal a;

    // Testing f1
    std::cout << "definition of f1: void f1(Animal& a) {a.eat()}" << std::endl;
    std::cout << "calling f1\n";
    
    std::cout << "f1(l)" << std::endl;
    f1(l);

    std::cout << "f1(g)" << std::endl;
    f1(g);

    std::cout << "f1(a)" << std::endl;
    f1(a);

    std::cout << std::endl;

    // Testing f2
    std::cout << "definition of f2: void f2(Animal a) {a.eat()}" << std::endl;
    std::cout << "calling f2\n";

    std::cout << "f2(l)" << std::endl;
    f2(l);

    std::cout << "f2(g)" << std::endl;
    f2(g);

    std::cout << "f2(a)" << std::endl;
    f2(a);

    std::cout << std::endl;

    std::cout << "declaring Animal a5(l) and a6(g) and calling a5.eat() & a6.eat():\n";
    Animal a5(l);
    Animal a6(g);
    a5.eat();
    a6.eat();

    return 0;
    
}