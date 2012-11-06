#include <iostream>

unsigned int fibonacci(const unsigned int n)
{
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main()
{
  int n;
  std::cout << "Max Fibonacci number: ";
  std::cin >> n;

  for(int i = 0; i < n; ++i)
  {
    std::cout << fibonacci(i) << ", ";
  }

  return 0;
}
