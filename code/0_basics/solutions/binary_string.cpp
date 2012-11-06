#include <iostream>

int main()
{
  unsigned int num;

  std::cout << "Please enter a positive integer between 0 and 128: ";
  std::cin >> num;

  num %= 128;
  std::cout << (num >= 64);
  num %= 64;
  std::cout << (num >= 32);
  num %= 32;
  std::cout << (num >= 16);
  num %= 16;
  std::cout << (num >= 8);
  num %= 8;
  std::cout << (num >= 4);
  num %= 4;
  std::cout << (num >= 2);
  num %= 2;
  std::cout << (num >= 1);


  return 0;
}
