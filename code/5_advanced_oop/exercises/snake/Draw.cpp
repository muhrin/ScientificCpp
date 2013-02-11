

#include "Draw.h"

extern "C"
{
#  include <curses.h>
//#  include <ncurses.h> // If above doesn't work, comment out line above and uncomment this one
}


const int SKEY_UP = KEY_UP;
const int SKEY_DOWN = KEY_DOWN;
const int SKEY_LEFT = KEY_LEFT;
const int SKEY_RIGHT = KEY_RIGHT;

void initDraw()
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
}

void cleanUpDraw()
{
  // End curses mode
  endwin();
}


void drawChars(const unsigned int x, const unsigned int y, const char * const toDraw)
{
  mvprintw(y, x, toDraw);
}

void clearScreen()
{
  clear();
}

void refreshScreen()
{
  refresh();
}

int getKey()
{
  return getch();
}
