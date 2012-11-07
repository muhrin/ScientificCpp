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
  return (number >= numberMin && number <= numberMax);
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
  // Check each player ball against all in the lottery numbers
  for(int i = 0; i < numBalls; ++i)
  {
    bool numberMatches = false;
    // Loop over all lottery numbers
    for(int j = 0; j < numBalls; ++j)
    {
      if(playerNumbers[i] == lotteryNumbers[j])
        numberMatches = true;
    }

    if(!numberMatches)
      return false;
  }
  // We have a winner!
  return true;
}

void printNumbers(const unsigned int numbers[6])
{
  for(int i = 0; i < numBalls; ++i)
  {
    std::cout << numbers[i] << " ";
  }
  std::cout << "\n";
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
    std::cout << "Enter 6 unique numbers between 1 and 49: ";
    std::cin >> playerNumbers[0]
      >> playerNumbers[1]
      >> playerNumbers[2]
      >> playerNumbers[3]
      >> playerNumbers[4]
      >> playerNumbers[5];

    numbersOk = numbersValid(playerNumbers);
  } while(!numbersOk);

  std::cout << "Starting lotter.  Let's hope you're a winner!\n";

  // Generate random lottery numbers
  do
  {
    for(int i = 0; i < numBalls; ++i)
    {
      lotteryNumbers[i] = randomLotteryNumber();
    }

  } while(!numbersOk);

  std::cout << "Player numbers: ";
  printNumbers(playerNumbers);
  std::cout << "Lottery numbers: ";
  printNumbers(lotteryNumbers);

  if(isPlayerAWinner(playerNumbers, lotteryNumbers))
  {
    std::cout << "Congratulations, you're a winner!\n";
  }
  else
  {
    std::cout << "Sorry, you're a looser.\n";
  }
}
