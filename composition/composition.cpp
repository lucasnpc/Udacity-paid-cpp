#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
#define PI 3.14159;
// Define Line Class
class LineSegment {
public:
    double length;
    LineSegment(double _lenght) : length(_lenght) {}
};

// Define Circle subclass
class Circle {
    LineSegment& radius_;
public:
    Circle(LineSegment& radius) : radius_(radius) {};
    double Area() { return pow(Circle::radius_.length, 2) * PI; }
};

// Define public setRadius() and getArea()

// Test in main()
int main()
{
    LineSegment radius{ 3 };
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}