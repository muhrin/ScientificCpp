#include <iostream>
#include <cstdlib>

double getRandom()
{
  return (double)rand() / (double)RAND_MAX;
}

int main()
{
  const unsigned int numParticles = 10;
  double positions[numParticles][3];  // positions x,y,z
  double masses[numParticles];
  double centreOfMass[3] = {0.0, 0.0, 0.0};

  for(int dim = 0; dim < 3; ++dim)
  {
    masses[dim] = getRandom();
    for(int i = 0; i < numParticles; ++i)
      positions[i][dim] = getRandom();
  }

  for(int i = 0; i < numParticles; ++i)
  {
    for(int dim = 0; dim < 3; ++dim)
    {
      centreOfMass[dim] += masses[i] * positions[i][dim] /
        numParticles;
    }
  }

  std::cout << "Centre of mass: " << centreOfMass[0] << " "
    << centreOfMass[1] << " " << centreOfMass[2] << "\n";
}
