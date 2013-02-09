#include <iostream>

int main()
{
  unsigned int width, height;
  std::cout << "Please enter a width and height: ";
  std::cin >> width >> height;
  std::cout << "Area is: " << width * height << "\n";

  const double ratio = static_cast<double>(height) /
    static_cast<double>(width);
  std::cout << "Ratio is: 1:" << ratio
            << " (width:height)" << "\n";

  const bool isSquare = (width == height);
  std::cout << "Is it a square? " << isSquare << "\n";

  return 0;
}
