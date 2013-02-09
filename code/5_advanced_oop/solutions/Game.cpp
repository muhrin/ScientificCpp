

#include "Game.h"

#include <iostream>

#include "snake_game.h"


// HELPER FUNCTIONS ///
void preFrame()
{
  // Clear the screen
  clear();
}

void postFrame()
{
  refresh();
  customSleep(0.05);
}


int getKey()
{
  int ch = getch();
  return ch;
}

// GAME CLASS IMPLEMENTATION ///
Game::Game(const unsigned int width, const unsigned int height)
{}

void Game::run()
{
  bool quit = false;
  myLastTickTime = clock();

  while(!quit)
  {
    preFrame();
    // Get the last keypress
    myLastKeypress = getKey();

    updateElapsedTime();

    myWorld.tick(*this);
    myWorld.draw();

    postFrame();

  }
}

int Game::getLastKeypress()
{
  return myLastKeypress;
}

float Game::getElapsedTime()
{
  return myElapsedTime;
}

void Game::updateElapsedTime()
{
  if(myLastTickTime != 0)
  {
    const clock_t currentTime = clock();
    myElapsedTime = static_cast<float>(currentTime - myLastTickTime) / CLOCKS_PER_SEC;
    myLastTickTime = currentTime;
  }
  else
  {
    myLastTickTime = clock();
    myElapsedTime = 0.0;
  }
}
