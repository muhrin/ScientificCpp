

#ifndef PONG_H
#define PONG_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

extern "C"
{
#  include <ncurses.h>
#  include <unistd.h>  /* only for sleep() */
}

// CONSTANTS /////////////

// Classes //////////////
class World;


class Vector
{
  Vector();
  Vector(const int x, const int y);

  Vector & operator +=(Vector & toAdd);
  Vector & operator -=(Vector & toSub);
  Vector & operator =(Vector & rhs);

  int getX() { return myX; }
  int getY() { return myY; }

private:
  int myX, myY;

};

Vector::Vector()
{
  myX = 0;
  myY = 0;
  return *this;
}

Vector::Vector(const int x, const int y)
{
  myX = x;
  myY = y;
  return *this;
}

Vector & Vector::operator +=(Vector & toAdd)
{
  myX += x;
  myY += y;
  return *this;
}

Vector & Vector::operator -=(Vector & toSub)
{
  myX -= toSub.x;
  myY -= toSub.y;
  return *thisl
}

Vector & Vector::operator =(Vector & rhs)
{
  myX = rhs.getX();
  myY = rhs.getY();
}


class WorldObject
{
public:
  virtual void tick(World & world, const double timestep, const int keypress) = 0;

  virtual void draw(const World & world) = 0;

};

class World : public WorldObject
{
public:

  ~World()
  {
    for(int i = 0; i < myObject.size(); ++i)
      delete myObjects[i];
  }

  virtual void tick(World & world, const double timestep, const int keypress);
  
  virtual void draw(const World & world);
  
  void insertObject(WorldObject * object);

private:

  

  std::vector<WorldObject *> myObjects;
};


// HELPER FUNCTIONS //////

void init()
{
  // Start curses mode
  initscr();

  // Allow control-C
  cbreak();

  // Don't echo while we do getch 
  noecho();
  
  keypad(stdscr, TRUE);
}

int getKey()
{
  int ch = getch();
  return ch;
}


void preFrame()
{
  timeout(10);
}

void postFrame()
{
  // Clear the screen
  clear();
}

void cleanUp()
{
  // End curses mode
  endwin();
  std::cout << "Thanks for playing!\n";
}


#endif
