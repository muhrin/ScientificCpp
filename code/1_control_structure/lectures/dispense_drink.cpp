#include <iostream>

const int MONDAY = 0, TEA = 0, COFFEE = 1;
void dispenseDrink(const int drinkType = COFFEE)
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
  std::cin >> dayOfWeek;

  if(dayOfWeek == MONDAY)
    dispenseDrink();
  else
    dispenseDrink(TEA);
}
