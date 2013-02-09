

#include "snake.h"

#include <iostream>

#include "Game.h"

const char Snake::SEGMENT_CHAR = '*';

Snake::Snake(const unsigned int startingSize, const unsigned int maxSize, const float staringSpeed):
mySize(startingSize),
myNumSegmentsResize(0),
myMaxSize(maxSize),
mySegments(new Vector[myMaxSize]),
myDistTravelledSinceMoved(0.0),
myDirection(RIGHT),
mySpeed(staringSpeed)
{
  // Set up the initial position
  Vector segmentPos(5, 5);
  for(unsigned int i = 0; i < mySize; ++i)
  {
    mySegments[i] = segmentPos;
    segmentPos -= myDirection;
  }
}

Snake::~Snake()
{
  delete [] mySegments;
}

void Snake::tick(Game & game)
{
  myDistTravelledSinceMoved += game.getElapsedTime() * mySpeed;

  if(game.getLastKeypress() == KEY_UP)
    myDirection = UP;
  else if(game.getLastKeypress() == KEY_DOWN)
    myDirection = DOWN;
  else if(game.getLastKeypress() == KEY_LEFT)
    myDirection = LEFT;
  else if(game.getLastKeypress() == KEY_RIGHT)
    myDirection = RIGHT;

  // Get the integer distance travelled, only move if it is more than 0
  const int distTravelled = static_cast<int>(myDistTravelledSinceMoved);
  if(distTravelled > 0)
  {
    for(int i = 0; i < distTravelled; ++i)
      move();
    myDistTravelledSinceMoved -= static_cast<float>(distTravelled);
    resize();
  }
}

void Snake::draw()
{
  // Draw each segment
  for(int i = 0; i < mySize; ++i)
  {
    mvprintw(mySegments[i].getY(), mySegments[i].getX(), &SEGMENT_CHAR);
  }
}

void Snake::move()
{
  if(myNumSegmentsResize > 0)
    mySegments[mySize] = mySegments[mySize - 1];

  // Move body pieces
  for(int i = mySize - 1; i > 0; --i)
  {
    mySegments[i] = mySegments[i - 1];
  }
  // Move the head
  mySegments[0] += myDirection;

  if(myNumSegmentsResize != 0)
  {
    mySize += myNumSegmentsResize;
    myNumSegmentsResize -= (myNumSegmentsResize > 0) ? 1 : -1;
  }
}

void Snake::resize(const int numSegments)
{
  if(mySize > 1 && mySize != myMaxSize)
    myNumSegmentsResize += numSegments;
}

