#include <iostream>

// Notice we're using double for output as even long long
// wouldn't be long enough!
double factorial(const unsigned int n)
{
  if(n > 1)
    return (n * factorial(n - 1));
  else
    return 1;
}

int main()
{

}
