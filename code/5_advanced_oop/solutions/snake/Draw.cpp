

#include "Draw.h"

extern "C"
{
#  include <ncurses.h>
}

#include "snake_game.h"


void draw(const unsigned int x, const unsigned int y, const char * toDraw)
{
  mvprintw(x, y, toDraw);
}

void draw(const Vector & pos, const char * toDraw)
{
  mvprintw(myPos.getY(), myPos.getX(), toDraw);
}
