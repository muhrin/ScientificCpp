double force(const double mass1, const double mass2, const double r)
{
  const double G = 6.6738e-11;
  return G * mass1 * mass2 / (r * r);
}

int main()
{
  const double massEarth = 5.9722e24;
  const double massSun = 1.9891e30;
  const double massMars = 6.4185e23;

  const double forceEarthSun = force(massEarth,  massSun, rEarthSun);
  const double forceEarthMoon = force(massEarth, massOfMoon, rEarthMoon);
  const double forceEarthMars = force(massEarth, massMars, rEarthMars);

  std::cout << "Forces:\n";
  std::cout << "Earth-Sun:  " << forceEarthSun << "\n";
  std::cout << "Earth-Moon: " << forceEarthMoon << "\n";
  std::cout << "Earth-Mars: " << forceEarthMars << "\n";
}

