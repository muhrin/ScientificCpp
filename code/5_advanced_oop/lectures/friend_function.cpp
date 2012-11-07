#include <iostream>

class Rectangle {
public:
  Rectangle(unsigned int widthIn, unsigned int heightIn);

  unsigned int area();
  
  friend void drawRectangle(const Rectangle &);
private:
  unsigned int width, height;
};

Rectangle::Rectangle(unsigned int widthIn, unsigned int heightIn)
{
  width = widthIn;
  height = heightIn;
}

unsigned int Rectangle::area()
{
  return width * height;
}

void printChars(const char toPrint, const unsigned int howMany)
{
  for(unsigned int i = 0; i < howMany; ++i)
    std::cout << toPrint;
}

void drawRectangle(const Rectangle & rect)
{
  std::cout << " ";     // Draw top
  printChars('-', rect.width);
  std::cout << " \n";
  for(unsigned int i = 0; i < rect.height; ++i)
  {
    std::cout << "|";   // Draw sides
    printChars(' ', rect.width);
    std::cout << "|\n";
  }	
  std::cout << " ";     // Draw bottom
  printChars('-', rect.width);
  std::cout << " \n";
}

int main()
{
  unsigned int width, height;
  std::cout << "How big do you want it? ";
  std::cin >> width >> height;
  Rectangle rect(width, height);
  drawRectangle(rect);

  return 0;
}
