
#ifndef SNAKE_H
#define SNAKE_H

#include "snake_game.h"
#include "WorldObject.h"

class Snake : public WorldObject
{
public:

  Snake(const unsigned int startingSize = 3, const unsigned int maxSize = 20, const float startingSpeed = 5);
  virtual ~Snake();

  virtual void tick(Game & game);

  virtual void draw();

  void resize(const int numSegments = 1);

private:
  static const char SEGMENT_CHAR;

  void move();

  Vector myDirection;
  float myDistTravelledSinceMoved;
  float mySpeed;
  unsigned int mySize;
  const unsigned int myMaxSize;
  int myNumSegmentsResize;
  Vector * mySegments;

};



#endif
