#ifndef PONG_H
#define PONG_H

#include <iostream>
#include <string>
#include <sstream>

extern "C"
{
#  include <ncurses.h>
#  include <unistd.h>  /* only for sleep() */
}

// CONSTANTS /////////////
extern const int XMIN;
extern const int XMAX;
extern const int YMIN;
extern const int YMAX;
extern const char BALL[];
extern const int PADDLE_SIZE;
extern const int PADDLE_HALF_SIZE;
extern const char PADDLE[];
extern const double BALL_VEL;

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

void drawPaddle(const int xPos, const int yPos)
{
  const int x0 = xPos - PADDLE_HALF_SIZE;
  mvprintw(yPos, x0, PADDLE);
  refresh();
}

void drawBall(const int xPos, const int yPos)
{
  mvprintw(yPos, xPos, BALL);
  refresh();
}

void drawScore(
  const unsigned int topPlayerScore,
  const unsigned int bottomPlayerScore)
{
  std::stringstream ss;
  ss << "Score: ";
  ss << topPlayerScore << " - " << bottomPlayerScore;
  std::string scoreString = ss.str();

  // Print the score
  mvprintw(YMAX + 1, XMAX / 2 - scoreString.length() / 2, scoreString.c_str());
  refresh();
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

void reset(int & topPaddleX, int & bottomPaddleX, double & ballX, double & ballY)
{
  mvprintw(YMAX/2,XMAX/2,"RESETTING");
  topPaddleX = XMAX / 2;
  bottomPaddleX = XMAX / 2;

  ballX = XMAX / 2;
  ballY = YMAX / 2;
  sleep(2);
}

#endif
