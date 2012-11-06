#include <iostream>

int main()
{
  const double pi = 3.1415926535;
  const double epsilon0 = 8.854187817e-12;
  const double forceConst = 1 / (4 * pi * epsilon0);

  double q1, q2, r, force;

  std::cout << "Enter charge1, charge2, distance: ";
  std::cin >> q1 >> q2 >> r;

  force = forceConst * q1 * q2 / (r * r);
  
  std::cout << "F = 1 / (4 pi epsilon0) q1 q2 / (r * r)\n";
  std::cout << "q1 = " << q1 << ", q2 = " << q2 << ", r = "
    << r << ", F = " << force << "\n";

  return 0;
}
