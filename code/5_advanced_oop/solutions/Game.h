

#ifndef GAME_H
#define GAME_H

#include <time.h>

#include "World.h"

class Game
{
public:

  Game(const unsigned int worldWidth = 80, const unsigned int worldHeight = 40);

  void run();

  int getLastKeypress();
  float getElapsedTime();

private:

  void updateElapsedTime();

  clock_t myLastTickTime;
  float myElapsedTime;
  World myWorld;
  int myLastKeypress;
};


#endif

