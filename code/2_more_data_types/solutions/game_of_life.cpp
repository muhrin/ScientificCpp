#include <iostream>
#include <time.h>
#include <cstdlib>

#ifdef WIN32
#  include <windows.h>
#  include <io.h>    // for _setmode()
#  include <fcntl.h> // for _O_U16TEXT
#else
#  include <unistd.h>
#  include <term.h>
#endif

const unsigned int WORLD_WIDTH = 80;
const unsigned int WORLD_HEIGHT = 22;
const unsigned int DEAD = 0;
const unsigned int ALIVE = 1;
const unsigned int NUM_STATES = 2;
//const wchar_t STATE_CHARS[NUM_STATES] = {' ',L'\x2588'};
const wchar_t STATE_CHARS[NUM_STATES] = {' ',0x2593};

// NOTICE: I'm breaking my own rules here and
// using a global vaiable!  Bad practice but the exercise
// is easier this way.  Later we'll learn enough to
// avoid this.
unsigned int world[WORLD_WIDTH][WORLD_HEIGHT];

void getSomeSleep(const unsigned int mseconds);
void clearScreen();

void drawWorld()
{
  clearScreen();
  // Loop over the world and print the dead or alive character
  for(unsigned int y = 0; y < WORLD_HEIGHT; ++y)
  {
    for(unsigned int x = 0; x < WORLD_WIDTH; ++x)
    {  std::wcout << STATE_CHARS[world[x][y]]; }
    std::wcout << std::endl;
  }
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

void init()
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
  // Initialise our world!
  init();

  bool running = true;
  while(running)
  {
    drawWorld();
    getSomeSleep(500);
    applyRules();
  }

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
  if(!cur_term)
  {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) return;
  }
  putp(tigetstr("clear"));
#endif
}
 
 
void getSomeSleep(const unsigned int mseconds)
{
  const clock_t goal = mseconds + clock();
  while (goal > clock());
}
