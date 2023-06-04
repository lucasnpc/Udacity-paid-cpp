// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>

// TODO: Define pi
#define PI 3.14159;

class Shape {
public:
  virtual double Area() const = 0;
  virtual double Perimeter() const = 0;
};

class Rectangle : public Shape {
public:
  Rectangle(double w, double h) {
    Rectangle::width_ = w;
    Rectangle::height_ = h;
  }
  double Area() const override { return width_ * height_; }
  double Perimeter() const override { return 2 * (width_ + height_); }

private:
  double width_;
  double height_;
};

class Circle : public Shape {
public:
  Circle(double r) { radius_ = r; }
  double Area() const override { return pow(radius_, 2) * PI; }
  double Perimeter() const override { return 2 * radius_ * PI; }

private:
  double radius_;
};

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}