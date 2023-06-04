#include <assert.h>

// TODO: Define Point class
class Point{
    public:
      int x,y;
      Point(int n1, int n2) : x{n1}, y{n2}{};
      Point operator+(const Point& addend) const {
          return Point(x+addend.x,y+addend.y);
      }
};

// Test in main()
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}