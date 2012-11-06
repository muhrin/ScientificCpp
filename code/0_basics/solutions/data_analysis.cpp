#include <iostream>
#include <cmath>

int main()
{
  double num1, num2, num3, num4;

  std::cout << "Enter four data points: ";
  std::cin >> num1 >> num2 >> num3 >> num4;

  std::cout << "Got: \n" << "n1: " << num1
    << "\nn2: " << num2
    << "\nn3: " << num3
    << "\nn4: " << num4 << "\n";

  const double mean = (num1 + num2 + num3 + num4) / 4.0;
  const double standardDeviation = std::sqrt(
    0.25 *
    ((num1 - mean) * (num1 - mean)
    + (num2 - mean) * (num2 - mean)
    + (num3 - mean) * (num3 - mean)
    + (num4 - mean) * (num4 - mean)));

  std::cout << "mean: " << mean << "\n";
  std::cout << "sd: " << standardDeviation << "\n";

}
