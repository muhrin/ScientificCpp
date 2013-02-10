
#ifndef SNAKE_H
#define SNAKE_H

#include "snake_game.h"

#include <vector>

#include "WorldObject.h"

class Snake : public WorldObject
{
public:

  Snake(const unsigned int startingSize = 3, const float startingSpeed = 5.0);

  virtual void tick(Game & game);

  virtual void draw();

  // Get the position of the head of the snake
  const Vector & getHeadPos() const;

  // Get the number of segments that make up the snake
  unsigned int size() const;

  // Change the size of the snake (can be negative or positive)
  void resize(const int numSegments = 1);

private:
  static const char SEGMENT_CHAR[];

  void move();
  float calcSpeed() const;

  bool hasCollidedWithSelf() const;

  Vector myDirection;
  float myDistTravelledSinceMoved;
  float mySpeed;
  float myMinSpeed;
  float mySpeedStep;
  int myNumSegmentsResize;
  ::std::vector<Vector> mySegments;

};



#endif
