

#include "Game.h"

#include <iostream>
#include <sstream>

#include "Draw.h"
#include "snake_game.h"


// HELPER FUNCTIONS ///
void preFrame()
{
  // Clear the screen
  clearScreen();
}

void postFrame()
{
  refreshScreen();
  customSleep(0.05);
}


// GAME CLASS IMPLEMENTATION ///
Game::Game(const Vector & dimensions):
myWorldDimensions(dimensions)
{
  reset();
}

bool Game::run()
{
  bool quit = false;
  myLastTickTime = clock();

  bool exitGame = false;
  while(!quit)
  {
    preFrame();
    // Get the last keypress
    myLastKeypress = getKey();

    updateElapsedTime();

    getWorld().preTick();
    getWorld().tick(*this);
    getWorld().postTick();
    getWorld().draw();
    drawInfo();

    postFrame();

    exitGame = (myLastKeypress == 'q');
    quit = myGameOverTriggered || exitGame;
  }

  doGameOver();
  return exitGame;
}

World & Game::getWorld()
{
  return *myWorld;
}

int Game::getLastKeypress()
{
  return myLastKeypress;
}

float Game::getElapsedTime()
{
  return myElapsedTime;
}

void Game::drawInfo()
{
  std::stringstream ss;
  ss << "Score: " << myScore << " Snake size: " << getWorld().getSnake().size();
  drawChars(0, getWorld().getDimensions().getY() + 1, ss.str().c_str());
}

int Game::getScore() const
{
  return myScore;
}

void Game::changeScore(const int changeBy)
{
  myScore += changeBy;
}

void Game::triggerGameOver()
{
  myGameOverTriggered = true;
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


void Game::reset()
{
  myGameOverTriggered = false;
  myWorld = new World(myWorldDimensions);
  myScore = 0;
}

void Game::doGameOver()
{
  std::stringstream ss;
  ss << "GAME OVER, Score: " << myScore;
  drawChars(
    (getWorld().getDimensions().getX() - ss.str().size()) / 2,
    getWorld().getDimensions().getY() / 2,
    ss.str().c_str()
  );
  refreshScreen();
  customSleep(5);
}




