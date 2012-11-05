#include <iostream>

int main()
{
  int upSpins = 10;
  int downSpins = 7;
  int & spinsReference = upSpins;

//  std::cout << "Address is: "
//    << spinsReference
//    << "\n";

  std::cout << "Value is: "
    << spinsReference
    << "\n";

  spinsReference = 20;
  std::cout << "New upSpins: "
    << upSpins
    << "\n";

//  spinsReference = downSpins;
//  std::cout << "Down spins : "
//    << spinsReference;

  return 0;
}
