
#include "snake_game.h"

#include <cstdlib>
#include <iostream>
#include <time.h>

#include "Draw.h"
#include "Game.h"
#include "GameObjects.h"
#include "World.h"


const Vector VEC_UP(0, -1);
const Vector VEC_DOWN(0, 1);
const Vector VEC_LEFT(-1, 0);
const Vector VEC_RIGHT(1, 0);

Vector::Vector()
{
  myX = 0;
  myY = 0;
}

Vector::Vector(const int x, const int y)
{
  myX = x;
  myY = y;
}

Vector & Vector::operator +=(const Vector & toAdd)
{
  myX += toAdd.myX;
  myY += toAdd.myY;
  return *this;
}

Vector & Vector::operator -=(const Vector & toSub)
{
  myX -= toSub.myX;
  myY -= toSub.myY;
  return *this;
}

Vector & Vector::operator =(const Vector & rhs)
{
  myX = rhs.getX();
  myY = rhs.getY();
  return *this;
}

bool Vector::operator ==(const Vector & rhs) const
{
  return (myX == rhs.myX && myY == rhs.myY);
}

bool Vector::operator !=(const Vector & rhs) const
{
  return (myX != rhs.myX) || (myY != rhs.myY);
}

// HELPER FUNCTIONS //////
void init()
{
  initDraw();

  // Seed the random number generator
  srand(static_cast<unsigned int>(time(0)));
  rand();
}


void cleanUp()
{
  cleanUpDraw();

  std::cout << "Thanks for playing!\n";
}


// FUNCTION PROTOTYPES ////////////
void populateWorld(World & world);

int main()
{

  init();

  bool quit = false;
  while(!quit)
  {
    Game game;
    populateWorld(game.getWorld());
    quit = game.run();
  }

  cleanUp();

  return 0;
}

void populateWorld(World & world)
{
  world.insertObject(new Apple(world.getRandomPoint()));
  world.insertObject(new ObjectGenerator());
}


