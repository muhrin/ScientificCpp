#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>


#ifdef WIN32
#  include <windows.h>
#  include <io.h>    // for _setmode()
#  include <fcntl.h> // for _O_U16TEXT
#endif

//#define USE_WCHAR

const unsigned int WORLD_WIDTH = 80;
const unsigned int WORLD_HEIGHT = 22;
const unsigned int NUM_STATES = 2;
#ifdef USE_WCHAR
const wchar_t DEAD = ' ';
const wchar_t ALIVE = 0x2588;
#else
const char DEAD = ' ';
const char ALIVE = 'O';
#endif
const bool ALLOW_MUTATE = false;
const unsigned int MAX_TICS = 50;

// NOTICE: I'm breaking my own rules here and
// using a global vaiable!  Bad practice but the exercise
// is easier this way.  Later we'll learn enough to
// avoid this.
char world[WORLD_WIDTH][WORLD_HEIGHT];

void getSomeSleep(const double mseconds);
void clearScreen();
void init();
void cleanUp();

void drawWorld()
{
  clearScreen();

#ifdef USE_WCHAR

  // Loop over the world and print the dead or alive character
  for(unsigned int y = 0; y < WORLD_HEIGHT; ++y)
  {
    for(unsigned int x = 0; x < WORLD_WIDTH; ++x)
    {  std::wcout << world[x][y]; }
    std::wcout << std::endl;
  }
#else
  // Loop over the world and print the dead or alive character
  for(unsigned int y = 0; y < WORLD_HEIGHT; ++y)
  {
    for(unsigned int x = 0; x < WORLD_WIDTH; ++x)
    {  std::cout << world[x][y]; }
    std::cout << std::endl;
  }
#endif
}

void saveWorld(const std::string & filename)
{
// TODO: Open the file 'filename' for writing.  You may need to use the
// string function c_str() to conver the string to a character array
// which is what the input file stream class takes as an argument.
// Check that the file is good to go.
// Now write out the entire array to the file remembering to put new
// lines after every row.  You can use the function above to see
// roughly how to do it.
// Finally when you're done, close the file but only if it was open.
}

void loadWorld(const std::string & filename)
{
// TODO: Open the file 'filename' for reading.  You may need to use the
// string function c_str() to conver the string to a character array
// which is what the input file stream class takes as an argument.
// Check that it is really open.
// Then use the lecture handout to read the file one line at
// at time.  For each line (i.e. row) keep track of which one
// we're at and don't let it go past WORLD_HEIGHT
// Copy the characters from the line one at a time into the world array
// at this row.  Be careful to only copy up to WORLD_WIDTH
// Once you're done, close the file.
} 

char getLeftState(
  const unsigned int x,
  const unsigned int y)
{
  if(x <= 0)
    return DEAD;
  else
    return world[x - 1][y];
}

char getRightState(
  const unsigned int x,
  const unsigned int y)
{
  if(x >= WORLD_WIDTH - 1)
    return DEAD;
  else
    return world[x + 1][y];
}

char getUpState(
  const unsigned int x,
  const unsigned int y)
{
  if(y <= 0)
    return DEAD;
  else
    return world[x][y-1];
}

char getDownState(
  const unsigned int x,
  const unsigned int y)
{
  if(y >= WORLD_HEIGHT - 1)
    return DEAD;
  else
    return world[x][y+1];
}

char getUpLeftState(
  const unsigned int x,
  const unsigned int y)
{
  if(x <= 0 || y <= 0)
    return DEAD;
  else
    return world[x-1][y-1];
}

char getUpRightState(
  const unsigned int x,
  const unsigned int y)
{
  if(x >= WORLD_WIDTH - 1 || y <= 0)
    return DEAD;
  else
    return world[x+1][y-1];
}

char getDownRightState(
  const unsigned int x,
  const unsigned int y)
{
  if(x >= WORLD_WIDTH - 1 || y >= WORLD_HEIGHT - 1)
    return DEAD;
  else
    return world[x+1][y+1];
}

char getDownLeftState(
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
  // Let's make life a bit easier
  using std::cout;
  using std::cin;
  using std::string;
  
  string filename;
#if USE_WCHAR
  std::wcout << "Please enter a file to load world from: ";
#else
  cout << "Please enter a file to load world from: ";
#endif
  cin >> filename;

  if(filename != "rand")
  {
    loadWorld(filename);
  }
  else
  {
    // Seed the random number generator to make sure we have
    // a different one each time
    srand((unsigned int)time(0));

    for(unsigned int x = 0; x < WORLD_WIDTH; ++x)
    {
      for(unsigned int y = 0; y < WORLD_HEIGHT; ++y)
        if(rand() % NUM_STATES == 0)
          world[x][y] = DEAD;
        else
          world[x][y] = ALIVE;
    }
  }
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
      if(ALLOW_MUTATE)
      {
        if(rand() % 1000 > 997)
        {
          if(tempWorld[x][y] == DEAD)
            tempWorld[x][y] = ALIVE;
        }
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

  unsigned int tics = 0;

  while(tics < MAX_TICS)
  {
    drawWorld();
    getSomeSleep(100);
    applyRules();
    ++tics;
  }
  saveWorld("world.out");
  cleanUp();
}

void init()
{
#ifdef WIN32
#  ifdef USE_WCHAR
  _setmode(_fileno(stdout), _O_U16TEXT);
#  endif
#endif

}

void cleanUp()
{
#if WIN32
  std::wcout << "Thanks for playing!\n";
#else
  std::cout << "Thanks for playing!\n";
#endif
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
  system("clear");
#endif
}
 
 
void getSomeSleep(const double mseconds)
{
  const double tics = (double)CLOCKS_PER_SEC * mseconds / 1000.0;
  const clock_t goal = (unsigned int)tics + clock();
  while (goal > clock());
}
