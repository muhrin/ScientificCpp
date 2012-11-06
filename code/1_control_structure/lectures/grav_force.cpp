#include <iostream>

double force(const double mass1, const double mass2, const double r)
{
  const double G = 0.001720298;
  return G * mass1 * mass2 / (r * r);
}

int main() {
  // Astronomical units
  const double massSun = 1.0, massEarth = 3.003e-6, massMars = 0.323e-6;

  const double rSunEarth = 1.0, rSunMars = 1.523;

  const double forceSunEarth = force(massSun, massEarth, rSunEarth);
  const double forceSunMars = force(massSun, massMars, rSunMars);

  std::cout << "Forces:\n";
  std::cout << "Sun-Earth:  " << forceSunEarth << "\n";
  std::cout << "Sun-Mars: " << forceSunMars << "\n";
}

