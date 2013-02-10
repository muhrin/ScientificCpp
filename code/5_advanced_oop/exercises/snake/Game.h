

#ifndef GAME_H
#define GAME_H

#include <time.h>

#include "World.h"

class Game
{
public:

  Game(const Vector & dimensions = Vector(80,20));

  bool run();

  World & getWorld();
  int getLastKeypress();
  float getElapsedTime();
  int getScore() const;
  void changeScore(int changeBy);
  void triggerGameOver();

private:

  int myScore;

  void updateElapsedTime();
  void drawInfo();
  void reset();
  void doGameOver();

  bool myGameOverTriggered;
  const Vector myWorldDimensions;
  clock_t myLastTickTime;
  float myElapsedTime;
  World * myWorld;
  int myLastKeypress;
};


#endif

