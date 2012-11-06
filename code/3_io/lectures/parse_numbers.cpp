#include <iostream>
#include <string>
#include <sstream>

int main()
{
  const std::string line("3.51 9.23 1.25 4.51");
  std::string numString;
  std::stringstream stream(line);

  double num, sum = 0.0;
  while(std::getline(stream, numString, ' '))
  {
    std::stringstream numStream(numString);
    if(!(numStream >> num))
      num = 0.0;
    sum += num;
  }
  std::cout << "Sum is: " << sum << "\n";

  return 0;
}
