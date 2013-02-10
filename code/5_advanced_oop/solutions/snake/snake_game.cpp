
#include "snake_game.h"

#include <cstdlib>
#include <iostream>
#include <time.h>

#include "Game.h"
#include "GameObjects.h"
#include "World.h"


const Vector UP(0, -1);
const Vector DOWN(0, 1);
const Vector LEFT(-1, 0);
const Vector RIGHT(1, 0);

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
  // Start curses mode
  initscr();

  // Allow control-C
  cbreak();

  // Don't echo while we do getch 
  noecho();

  // Don't block on input
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);

  // Seed the random number generator
  srand(time(0));
  rand();
}


void cleanUp()
{
  // End curses mode
  endwin();
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


