
#include "snake_game.h"

#include <iostream>

#include "Game.h"


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

// HELPER FUNCTIONS //////
void init()
{
  // Start curses mode
  initscr();

  // Allow control-C
  cbreak();

  // Don't echo while we do getch 
  noecho();

  
  nodelay(stdscr, TRUE);
  
  keypad(stdscr, TRUE);
}


void cleanUp()
{
  // End curses mode
  endwin();
  std::cout << "Thanks for playing!\n";
}


int main()
{

  init();

  Game game;
  game.run();

  cleanUp();

  return 0;
}


