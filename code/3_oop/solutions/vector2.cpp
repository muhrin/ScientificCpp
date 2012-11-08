#include <iostream>

class Vector2
{
public:

  Vector2()
  {
    x = 0.0;
    y = 0.0;
  }

  Vector2(const double x0, const double y0)
  {
    x = x0;
    y = y0;
  }

  double getX()
  { return x; }

  double getY()
  { return y; }

  Vector2 operator -(Vector2 toSub)
  {
    return Vector2(x - toSub.getX(), y - toSub.getY());
  }

private:
  double x, y;
};

int main()
{
  Vector2 r1, r2;
  Vector2 r12 = r2 - r1;

  return 1;
};
