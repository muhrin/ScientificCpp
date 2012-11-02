#include <iostream>

int main()
{
  double G = 6.6738e-11;
  double massOfEarth = 5.9722e24;
  double massOfMoon = 7.3477e22;
  double r = 384400e3;
  double force;
  
  force = G * massOfEarth * massOfMoon / (r * r);
  
  std::cout << "Force between Earth and Moon is: "
            << force << "\n";

  return 0;
}
