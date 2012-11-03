#include <iostream>

int main()
{
  bool wantACupOfTea;
  do
  {
    std::cout << "Cup of tea father? ";
    std::cin >> wantACupOfTea;
    if(!wantACupOfTea)
      std::cout << "Go on\n";
  } while(!wantACupOfTea);

  return 0;
}
