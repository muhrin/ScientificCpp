#include <iostream>
#include <cstdlib>
#include <time.h>

// CONSTANTS //////////////
const unsigned int numBalls = 6;
const unsigned int numberMin = 1;
const unsigned int numberMax = 49;
const unsigned int numbersRange = numberMax - numberMin;


unsigned int randomLotteryNumber()
{
  return (rand() % numbersRange) + numberMin;
}

bool numberValid(const unsigned int number)
{
// TODO: Check that the number is in the correct range
// i.e. between numberMin and numberMax inclusive and return
// and appropriate boolean response
  return false;
}

bool numbersValid(const unsigned int numbers[6])
{
  // Check each ball.
  for(int i = 0; i < numBalls; ++i)
  {
    // First check that the number is in the valid range
    if(!numberValid(numbers[i]))
      return false;

    // Now check against all the other balls except itself for uniqueness

    // Check all numbers up to the (i-1)^th
    for(int j = 0; j < i; ++j)
    {
      if(numbers[i] == numbers[j])
        return false;
    }
    // Move on to checking the (i+1)^th
    for(int j = i + 1; j < numBalls; ++j)
    {
      if(numbers[i] == numbers[j])
        return false;
    }
  }
  // Well we haven't returned yet so the numbers must be good
  return true;
}

bool isPlayerAWinner(
  const unsigned int playerNumbers[6],
  const unsigned int lotteryNumbers[6])
{
  for(int i = 0; i < numBalls; ++i)
  {
    bool numberMatches = false;

// TODO: This function need to compare the players numbers and
// decide if they match that of the lottery.  Probably the easiest
// way to do this is to is to check the player number one by one
// against all the lottery numbers.  Which is what we're doing in this
// loop.
// Loop over all the lottery numbers here and check if there is a match
// if so, set numberMatches to true otherwise do nothing

    if(!numberMatches)
      return false;
  }
  // We have a winner!
  return true;
}

void printNumbers(const unsigned int numbers[6])
{
// TODO: Write a function that loops over all the numbers
// and prints them out on a line here.
}

int main()
{
  // Seed the random number generator with the current time
  srand((unsigned int)time(NULL));

  bool numbersOk;
  unsigned int playerNumbers[6];
  unsigned int lotteryNumbers[6];

  // Ask the player for their numbers
  do
  {
// TODO Ask the player for 6 numbers and store them
// one by one in playerNumbers[...]

    numbersOk = numbersValid(playerNumbers);
  } while(!numbersOk);

  std::cout << "Starting lotter.  Let's hope you're a winner!\n";

  // Generate random lottery numbers
  do
  {

// TODO: Use randomLotteryNumber to populate the lotteryNumbers
// array one by one with random numbers

  } while(!numbersOk);

  std::cout << "Player numbers: ";
  printNumbers(playerNumbers);
  std::cout << "Lottery numbers: ";
  printNumbers(lotteryNumbers);

// TODO: Call isPlayerAWinner with the two arrays: playerNumbers and
// lotteryNumbers.  If they are, print a congratulatory message
// otherwise print a message telling them how bit a fool they were
// for playing a game with 1 in 13m odds.
}
