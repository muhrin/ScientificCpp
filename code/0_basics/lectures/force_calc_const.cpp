#include <iostream>

int main()
{
  const double G = 6.6738e-11
  const double massOfEarth = 5.9722e24;
  const double massOfMoon = 7.3477e22;
  const double r = 384400e3;
  double force;
  
  force = G * massOfEarth * massOfMoon / (r * r);
  
  std::cout << "Force between Earth and Moon is: " << force << "\n";
            
  G = 7e-11; // WON'T COMPILE. WHAT KIND OF A UNIVERSE WOULD WE BE LIVING IN
             // IF G COULD VARY??

  return 0;
}
