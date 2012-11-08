#include <iostream>
#include <fstream>
#include <string>

int main () {
  std::string line;
  std::ifstream myFile("caterpillar.txt");

  if(myFile.is_open())
  {
    while(myFile.good())
    {
      std::getline(myFile, line);
      std::cout << line << std::endl;
    }
    myFile.close();
  }
  else
    std::cout << "Unable to open"; 

  return 0;
}
