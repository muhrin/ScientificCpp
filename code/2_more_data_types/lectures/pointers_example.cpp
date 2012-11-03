#include <iostream>

int main()
{
  int upSpins = 10;
  int * upSpinsPointer = &upSpins;

  std::cout << "Address is: "
    << upSpinsPointer
    << "\n";

  std::cout << "Value is: "
    << *upSpinsPointer
    << "\n";

  *upSpinsPointer = 20;
  std::cout << "New upSpins: "
    << upSpins
    << "\n";

  return 0;
}
