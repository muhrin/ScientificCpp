#include <iostream>
#include <time.h>
#include <cstdlib>

#define USE_NCURSES

#ifdef WIN32
#  include <windows.h>
#  include <io.h>    // for _setmode()
#  include <fcntl.h> // for _O_U16TEXT
#endif

#ifdef USE_NCURSES && WIN32
#  include <ncurses.h>
#else
#  include <curses.h>
#endif

const unsigned int WORLD_WIDTH = 60;
const unsigned int WORLD_HEIGHT = 22;
const unsigned int NUM_STATES = 2;
const unsigned int DEAD = 0;
const unsigned int ALIVE = 1;
const char STATE_CHARS[NUM_STATES] = {' ','O'};

// NOTICE: I'm breaking my own rules here and
// using a global vaiable!  Bad practice but the exercise
// is easier this way.  Later we'll learn enough to
// avoid this.
unsigned int world[WORLD_WIDTH][WORLD_HEIGHT];

void getSomeSleep(const double mseconds);
void clearScreen();
void init();
void cleanUp();

void drawWorld()
{
  clearScreen();
  // Loop over the world and print the dead or alive character
  for(unsigned int y = 0; y < WORLD_HEIGHT; ++y)
  {
    for(unsigned int x = 0; x < WORLD_WIDTH; ++x)
    {
#ifdef WIN32
      std::cout << STATE_CHARS[world[x][y]];
#else
      mvprintw(y, x, STATE_CHARS[world[x][y]]);
#endif
    }
#ifdef WIN32
    std::cout << std::endl;
#endif
  }
#ifndef WIN32
  refresh();
#endif
}

unsigned int getLeftState(
  const unsigned int x,
  const unsigned int y)
{
  if(x <= 0)
    return DEAD;
  else
    return world[x - 1][y];
}

unsigned int getRightState(
  const unsigned int x,
  const unsigned int y)
{
  if(x >= WORLD_WIDTH - 1)
    return DEAD;
  else
    return world[x + 1][y];
}

unsigned int getUpState(
  const unsigned int x,
  const unsigned int y)
{
  if(y <= 0)
    return DEAD;
  else
    return world[x][y-1];
}

unsigned int getDownState(
  const unsigned int x,
  const unsigned int y)
{
  if(y >= WORLD_HEIGHT - 1)
    return DEAD;
  else
    return world[x][y+1];
}

unsigned int getUpLeftState(
  const unsigned int x,
  const unsigned int y)
{
  if(x <= 0 || y <= 0)
    return DEAD;
  else
    return world[x-1][y-1];
}

unsigned int getUpRightState(
  const unsigned int x,
  const unsigned int y)
{
  if(x >= WORLD_WIDTH - 1 || y <= 0)
    return DEAD;
  else
    return world[x+1][y-1];
}

unsigned int getDownRightState(
  const unsigned int x,
  const unsigned int y)
{
  if(x >= WORLD_WIDTH - 1 || y >= WORLD_HEIGHT - 1)
    return DEAD;
  else
    return world[x+1][y+1];
}

unsigned int getDownLeftState(
  const unsigned int x,
  const unsigned int y)
{
  if(x <= 0 || y >= WORLD_HEIGHT - 1)
    return DEAD;
  else
    return world[x-1][y+1];
}

unsigned int getNumLivingNeighbours(
  const unsigned int x,
  const unsigned int y)
{
  unsigned int livingNeighbours = 0;
  if(getLeftState(x, y) == ALIVE)
      ++livingNeighbours;

  if(getRightState(x, y) == ALIVE)
      ++livingNeighbours;

  if(getUpState(x, y) == ALIVE)
    ++livingNeighbours;

  if(getDownState(x, y) == ALIVE)
    ++livingNeighbours;

  if(getUpLeftState(x, y) == ALIVE)
    ++livingNeighbours;

  if(getUpRightState(x, y) == ALIVE)
    ++livingNeighbours;

  if(getDownLeftState(x, y) == ALIVE)
    ++livingNeighbours;

  if(getDownRightState(x, y) == ALIVE)
    ++livingNeighbours;

  return livingNeighbours;
}

void initWorld()
{
  // Seed the random number generator to make sure we have
  // a different one each time
  srand((unsigned int)time(0));

  for(unsigned int x = 0; x < WORLD_WIDTH; ++x)
  {
    for(unsigned int y = 0; y < WORLD_HEIGHT; ++y)
      world[x][y] = rand() % NUM_STATES;
  }

#ifdef WIN32
  _setmode(_fileno(stdout), _O_U16TEXT);
#else

#endif
}

void applyRules()
{
  unsigned int numNeighbours;
  unsigned int tempWorld[WORLD_WIDTH][WORLD_HEIGHT];

  for(unsigned int x = 0; x < WORLD_WIDTH; ++x)
  {
    for(unsigned int y = 0; y < WORLD_HEIGHT; ++y)
    {
      numNeighbours = getNumLivingNeighbours(x, y);
      if(world[x][y] == ALIVE)
      {
        //1. Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.
        //2. Any live cell with more than three live neighbors dies, as if by overcrowding.
        if(numNeighbours < 2 || numNeighbours > 3)
          tempWorld[x][y] = DEAD;
        else
          tempWorld[x][y] = ALIVE;
        //3. Any live cell with two or three live neighbors lives on to the next generation.
      }
      else
      {
        //4. Any dead cell with exactly three live neighbors becomes a live cell.
        if(numNeighbours == 3)
          tempWorld[x][y] = ALIVE;
        else
          tempWorld[x][y] = DEAD;
      }

      // Mutate step, every so often randomly mutate a dead to alive
      if(rand() % 1000 > 997)
      {
        if(tempWorld[x][y] == DEAD)
          tempWorld[x][y] = ALIVE;
      }
    }
  }
  // Copy over the temporary world to the real world!:
  for(unsigned int x = 0; x < WORLD_WIDTH; ++x)
  {
    for(unsigned int y = 0; y < WORLD_HEIGHT; ++y)
      world[x][y] = tempWorld[x][y];
  }
}

int main()
{
  init();
  // Initialise our world!
  initWorld();

  bool running = true;
  while(running)
  {
    drawWorld();
    //getSomeSleep(30);
    applyRules();
  }
  cleanUp();
}

void init()
{
#ifdef WIN32

#else
  // Start curses mode
  initscr();

  // Allow control-C
  cbreak();
#endif
}

void cleanUp()
{
  // End curses mode
  endwin();
  std::cout << "Thanks for playing!\n";
}

void clearScreen()
{
#ifdef WIN32
 COORD topLeft = {0, 0};
 DWORD cCharsWritten, dwConSize;
 CONSOLE_SCREEN_BUFFER_INFO cInfo;
            HANDLE hConsoleOutput = GetStdHandle((DWORD)-11);

 // Get the number of character cells in the current buffer
 GetConsoleScreenBufferInfo(hConsoleOutput, &cInfo);
 dwConSize = cInfo.dwSize.X * cInfo.dwSize.Y;

 // Fill the whole screen with blank chars
// FillConsoleOutputCharacter(hConsoleOutput, (TCHAR)' ', dwConSize, topLeft, &cCharsWritten);

 // Get the current text attribute
 GetConsoleScreenBufferInfo(hConsoleOutput, &cInfo);

 // Set the buffer's attributes accordingly
 FillConsoleOutputAttribute(hConsoleOutput, cInfo.wAttributes, dwConSize, topLeft, &cCharsWritten);

 // Put the cursor at its home coordinates
 SetConsoleCursorPosition(hConsoleOutput, topLeft);
#else
  clear();
#endif
}
 
 
void getSomeSleep(const double mseconds)
{
  const double tics = (double)CLOCKS_PER_SEC * mseconds / 1000.0;
  const clock_t goal = (unsigned int)tics + clock();
  while (goal > clock());
}
