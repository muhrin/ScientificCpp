#include <iostream>
#include <cmath>

double getRandom(const double x0, const double x1)
{
  const double range = x1 - x0;
  const double randNum = range * ((double)rand() / (double)RAND_MAX);
  return x0 + randNum;
}

double getRandom()
{
  return getRandom(0.0, 1.0);
}

int main()
{
  unsigned int numPoints;
  unsigned long totalPoints = 0, pointsInCircle = 0;
  double x, y, len;
  do
  {
    std::cout << "How many points do you want? ";
    std::cin >> numPoints;

    for(unsigned int i = 0; i < numPoints; ++i)
    {
      x = getRandom();
      y = getRandom();
      len = std::sqrt(x * x + y * y);
      std::cout << x << " " << y << "\n";
      if(len < 1.0)
        ++pointsInCircle;
    }
    totalPoints += numPoints;
  } while(numPoints != 0);

  const double pi = 4.0 * pointsInCircle / totalPoints;
  std::cout << "Pi is: " << pi << "\n";
}
