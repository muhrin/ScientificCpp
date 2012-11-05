#include <iostream>

int main()
{
  int upSpins = 10;
  int downSpins = 7;
  int * spinsPointer = &upSpins;

  std::cout << "Address is: "
    << spinsPointer
    << "\n";

  std::cout << "Value is: "
    << *spinsPointer
    << "\n";

  *spinsPointer = 20;
  std::cout << "New upSpins: "
    << upSpins
    << "\n";

  spinsPointer = &downSpins;
  std::cout << "Down spins : "
    << *spinsPointer;

  return 0;
}
