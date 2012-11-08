
#ifndef SNAKE_H
#define SNAKE_H

#include "snake_game.h"

class Snake
{
public:

  virtual void tick(World & world, const double timestep, const int keypress);

  virtual void draw(const World & world);

private:
  const unsigned int maxSegments = 10;
  const unsigned int startingSegments = 3;
  const char segmentChar = '*';

  const Vector UP;
  const Vector DOWN;
  const Vector LEFT;
  const Vector RIGHT;

  void move();

  Vector myDirection;
  float mySpeed;
  unsigned int mySize;
  Vector mySegments[MAX_SEGMENTS];

};



#endif
