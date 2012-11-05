#include <iostream>
#include <cmath>

class Vector2
{
public:
  double length()
  { return std::sqrt(x * x + y * y); }

  void sub(const Vector2 toSub)
  { x -= toSub.x; y -= toSub.y; }

  void mul(const double k)
  { x *= k; y *= k; }

  double dot(const Vector2 b)
  { return x * b.x + y * b.y; }

  void printCoords()
  { std::cout<< x << " "<< y << "\n";}

  double x, y;
};

int main()
{
  Vector2 r1, r2;
  r1.x = 2; r1.y = 1;
  r2.x = 4; r2.y = 10;

  std::cout << "r1: ";
  r1.printCoords();
  std::cout << "r2: ";
  r2.printCoords();
  std::cout << "Performing r2.sub(r1)\n";
  r2.sub(r1);
  std::cout << "r2: ";
  r2.printCoords();

  return 0;
}
