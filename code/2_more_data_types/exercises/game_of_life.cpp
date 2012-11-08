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
const unsigned int NUM_STATES = 2;
const unsigned int DEAD = 0;
const unsigned int ALIVE = 1;
// TODO: Feel free to play with different characters.  Here
// as you can see DEAD is a blank and ALIVE is a strange square
// character.  But it could be an asterix, a letter, whatever you want.
// In fact, if your terminal can handle it you can use any unicode character:
// http://en.wikipedia.org/wiki/Unicode_characters
// or perhaps some of the box drawing characters:
// http://en.wikipedia.org/wiki/Box_drawing_characters
// In these formats U+2228 = 0x2228 for us
const wchar_t STATE_CHARS[NUM_STATES] = {' ',0x2588};

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


// TODO: After you've done the exercise once and have the game of life working
// Try making the world periodic.  You can see below that each of the get<Direction>State
// functions give back a dead if the value is out of bounds.  Why not wrap it around
// the screen e.g.: if x goes greater than WORLD_WIDTH give the state of the cell at x = 0
// Do this for all the get<Direction>State functions.  The corners are tricky!
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
// TODO: Code up the following rules for what happens to cells
// 1. Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.
// 2. Any live cell with more than three live neighbors dies, as if by overcrowding.
// 3. Any live cell with two or three live neighbors lives on to the next generation.
// 4. Any dead cell with exactly three live neighbors becomes a live cell.
//
// Place the new states in tempWorld[x][y] which will then be copied over to the real world
// at the end 

// TODO: Once you've applied the rules above and tried the program.
// Put in a mutate step here:
// Randomly, with some probability, mutate this cell
// in tempWorld by bringing it back to life if it is dead.  Keep the probability
// low (say 1 in 300) or your world will look crazy!

    }
  }
// TODO: Copy over the temporary world to the real world!:
// Here you should loop over all values of x and y like above and copy over
// the state from the tempWorld to the world array.
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

// Some code for clearing the screen
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
 
// Some code to make sure the game doesn't run too fast!
void getSomeSleep(const unsigned int mseconds)
{
  const clock_t goal = mseconds + clock();
  while (goal > clock());
}
