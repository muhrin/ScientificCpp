#include <iostream>

int main()
{
  bool wantACupOfTea;
  do
  {
    std::cout << "Do you want a cup of tea father? ";
    std::cin >> wantACupOfTea;
    std::cout << "Go on\n";
  } while(!wantACupOfTea);

  return 0;
}
