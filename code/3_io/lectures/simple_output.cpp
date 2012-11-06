#include <iostream>
#include <fstream>

int main () {
  std::ofstream myFile("caterpillar.txt");
  myFile << "Here, have a caterpillar:\n\n";
  myFile << "\\ \n";
  myFile << " '-.__.-' \n";
  myFile << " /oo |--.--,--,--. \n";
  myFile << " \\_.-'._i__i__i_.' \n";
  myFile << "       \"\"\"\"\"\"\"\"\" \n";
  if(myFile.is_open())
    myFile.close();
  return 0;
}
