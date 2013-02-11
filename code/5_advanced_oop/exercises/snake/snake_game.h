

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <ostream>
#include <string>
#include <ctime>

// CONSTANTS /////////////

// FORWARD DECLARES //////

// Classes //////////////

class Vector
{
public:
  Vector();
  Vector(const int x, const int y);

  Vector & operator +=(const Vector & toAdd);
  Vector & operator -=(const Vector & toSub);
  Vector & operator =(const Vector & rhs);
  bool operator ==(const Vector & rhs) const;
  bool operator !=(const Vector & rhs) const;

  int getX() const { return myX; }
  int getY() const { return myY; }

private:
  int myX, myY;
};

extern const Vector VEC_UP, VEC_DOWN, VEC_LEFT, VEC_RIGHT;

inline std::ostream & operator <<(std::ostream & os, const Vector & vector)
{
  os << vector.getX() << " " << vector.getY() << ::std::endl;
  return os;
}

inline void customSleep(const float secs)
{
  clock_t endTime = clock() + static_cast<clock_t>(secs * CLOCKS_PER_SEC);
  while(clock() < endTime) {}
}


#endif

