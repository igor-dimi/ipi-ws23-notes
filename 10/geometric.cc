#include <iostream>
#include <cmath>

const double pi = 3.1415926536;

class Shape
{
    public :
        virtual ~Shape() {};
        virtual double area () = 0;
        virtual double diameter () = 0;
        virtual double circumference () = 0;
        double circumference_to_area();
};

double Shape::circumference_to_area() {return circumference() / area();}

class Circle : public Shape 
{
    private:
        double radius;
    public: 
        Circle (double r);
        virtual double area ();
        virtual double diameter();
        virtual double circumference();
};
//Implementation of Cricle's methods
Circle::Circle(double r) {radius = r;}
double Circle::area() {return pi * radius * radius;}
double Circle::diameter() {return 2 * radius;}
double Circle::circumference() {return pi * diameter();}

class Rectangle : public Shape 
{
    private:
        double a, b;
    public :
        Rectangle (double _a, double _b);
        virtual double area();
        virtual double diameter();
        virtual double circumference();
};
// Implementation of Rectangles methods
Rectangle::Rectangle(double _a, double _b) {a = _a; b = _b;}
double Rectangle::area() {return a * b;}
double Rectangle::diameter() {return sqrt(a*a + b*b);}
double Rectangle::circumference() {return 2*(a + b);}

int main()
{
    Rectangle square1(1.0, 1.0);
    Circle circle1(1.0);
    Circle circle2(1.0/sqrt(pi));

    std::cout << "square1: " << std::endl;
    std::cout << "circ to area: " << square1.circumference_to_area() << std::endl;
    std::cout << "area: " << square1.area() << std::endl;
    std::cout << std::endl;

    std::cout << "circle1: " << std::endl;
    std::cout << "circ to area: " << circle1.circumference_to_area() << std::endl;
    std::cout << "area: " << circle1.area() << std::endl;
    std::cout << std::endl;

    std::cout << "circle2: " << std::endl;
    std::cout << "circ to area: " << circle2.circumference_to_area() << std::endl;
    std::cout << "area: " << circle2.area() << std::endl;
    std::cout << std::endl;

    return 0;
}
