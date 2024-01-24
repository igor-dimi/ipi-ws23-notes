#include <iostream>
#include "../code/fcpp.hh"
#include <stdio.h>



class Person
{
    public:
        char favorite_color;
        Person(int age, int height, int weight);
        int get_age();
        int get_weight();
        int get_height();
        void increase_age(int amount);
        void change_weight(int amount);
        void smile();
    private:
        int age;
        int height;
        int weight;
        void some_function();
};

Person::Person(int age, int weight, int height)
{
    this->age = age;
    this->weight = weight;
    this->height = height;
}

void Person::increase_age(int amount) {this->age += amount;}
void Person::smile(){;} //for now we don't implement anything here, just an example.
void Person::some_function(){;};  //same here.


class Student : public Person
{
    public:
        void graduate();
    private :
        int year; //freshman, sophomore etc.. 
        bool graduated;
        

};

void Student::graduate()
{
    graduated = true;
}

void g(Person p)
{
    p.smile();
    p.age++;
}

void h(Student s)
{
    s.graduate();
    s.age++;
}

int main()
{
    Person p; 
    print(p.age, p.height, p.weight)
}
  