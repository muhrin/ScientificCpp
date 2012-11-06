
#include <iostream>
#include <cstdlib>
#include <cmath>

const double PI = 3.14159265358979323846264338327950288419716939937510;
const double CHILD_ANGLE_FRAC = PI / 5.0;
const double CHILD_LEN_FRAC = 2.0 / 3.0;


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

void printVector(
  const double x0,
  const double y0,
  const double x1,
  const double y1,
  const unsigned int colour = 0)
{
  std::cout << x0 << " " << y0 << " " << x1 - x0 << " " << y1 - y0 << " " << colour << "\n";
}

void branch(
  const double x0,              // Starting x
  const double y0,              // Starting y
  const double len,             // The length of this branch
  const double angle,           // The angle of this branch
  const double maxDepth,        // The maximum depth of the tree
  const unsigned int depth = 0  // The current depth
  )
{
  const double x1 /* TODO: = set to x0 + the correct x distance using angle and len */;
  const double y1 /* TODO: = set to y0 + the correct x distance using angle and len */;
                  // Pythagoras is your friend

  printVector(x0, y0, x1, y1); // draw branch


  // TODO: Here you want to make sure to not draw any more branches if the 
  // maximm depth has been reached..

  // TODO: Now, we want at least two branches: one left, one right
  // Use the recursive programming paradigm to do this
  // Choose a length and angle for the children.  You may want them to have the
  // same length as this branch or you may want them to get smaller.

  // TODO: You may want to create more than once branch.  Or introduce some
  // randomness to the lengths and angles to make your trees look more organic
}


int main()
{
  unsigned int maxDepth = 3;
  double startX, startY;
  const double startAngle = PI / 2.0;
  const double startLen = 25.0;

  do
  {
    startX = getRandom(0.0,100.0);
    startY = getRandom(0.0, 20.0);
    branch(startX, startY, startLen, startAngle, maxDepth);
    std::cin >> maxDepth;
  } while(maxDepth != 0);

  return 0;
}
