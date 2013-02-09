#include <iostream>

const int MONDAY = 0;
const int TEA = 0, COFFEE = 1;
void dispenseDrink(
  const int drinkType = COFFEE)
{
  std::cout << "Dispensing: ";
  if(drinkType == COFFEE)
    std::cout << "coffee...\n";
  else
    std::cout << "tea...\n";
}

int main()
{
  unsigned int dayOfWeek;
  // Enter number from 0 to 6
  std::cin >> dayOfWeek;

  if(dayOfWeek == MONDAY)
    dispenseDrink();
  else
    dispenseDrink(TEA);
}
