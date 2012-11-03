#include <iostream>

// Notice we're using double for output as even long long
// wouldn't be long enough!
double factorial(const unsigned int n)
{
  if(n > 1)
    return (n * factorial(n - 1));
  else
    return 1;
}

unsigned long binomialCoeff(unsigned int n, unsigned int k)
{
  return factorial(n) / (factorial(k) * (factorial(n - k)));
}

int main()
{
  unsigned long numBalls, numToChoose;

  std::cout << "How many balls? ";
  std::cin >> numBalls;
  std::cout << "How many to choose? ";
  std::cin >> numToChoose;

  if(numToChoose >= numBalls)
  {
    std::cout << "Number to choose must be less than the number of balls";
    return 0;
  }

  const unsigned long odds = binomialCoeff(numBalls, numToChoose);
  std::cout << "Odds are 1 in " << odds << "\n";
  if(odds > 2320000)
    std::cout << "Good luck with that, you have more chance of being struck by lightning.\n"; // [1]
  else if(odds > 662000)
    std::cout << "You've got better odds of winning an olympic medal!\n";

  return 0;
}


// [1] http://www.funny2.com/odds.htm
