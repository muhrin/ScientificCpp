

#include "snake.h"

virtual void tick(World & world, const double timestep, const int keypress)
{
  // TODO: Do tick

}

void Snake::draw(const World & world)
{
  for(int i = 0; i < mySize; ++i)
  {
    mvprintw(mySegments[i].getY(), mySegments[i].getY(), segmentChar);
  }
}

void Snake::move()
{
  for(int i = 0; i < mySize - 1; ++i)
  {
    mySegments[i] = mySegments[i + 1];
  }
  mySegments[mySize - 1] += myDirection;
}

