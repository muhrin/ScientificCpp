
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
  const unsigned int colour)
{
  std::cout << x0 << " " << y0 << " " << x1 - x0 << " " << y1 - y0 << " " << colour << "\n";
}

void branch(
  const double x0,
  const double y0,
  const double len,
  const double angle,
  const double maxDepth,
  const unsigned int depth = 0)
{

  unsigned int color = 0; // branch color

  //if(len>3) // if its a long branch, make it brown. 
  //   color=BROWN;
  //else
  //   color=GREEN; // otherwise make it green. 

  // draw the 'branches' and 'leaves' as a simple lines. 
  // Get more fancy than this, please.

  const double x1 = x0 + len * cos(angle); 
  const double y1 = y0 + len * sin(angle);

  if(depth > 3)
    color = 255;

  printVector(x0, y0, x1, y1, color); // draw branch
 
  if(depth < maxDepth) // check that the tree isn't too long
  {
    const double childlength = CHILD_LEN_FRAC * len; //len * getRandom(0.0, 10.0);
    const double childangle = /*CHILD_ANGLE_FRAC * PI; */ getRandom(0.0, CHILD_ANGLE_FRAC);

    // Branch right
    branch(x1, y1, childlength, angle - childangle, maxDepth, depth + 1); 
    // Branch left
    branch(x1, y1, childlength, angle + childangle, maxDepth, depth + 1);
  }
  else
    return;
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
