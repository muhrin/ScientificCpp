#include <iostream>
// Notice we're using double here as unsigned int could be too small
double factorial(const unsigned int n)
{
  if(n > 1)
    return (n * factorial(n - 1));
  else
    return 1;
}

int main ()
{
  unsigned long number;
  std::cout << "Please type a number: ";
  std::cin >> number;
  std::cout << number << "! = " << factorial(number);
  return 0;
}
