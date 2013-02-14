
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

const unsigned int MAX_ROWS = 10000;
const int INVALID_INT = -1;
const float INVALID_FLOAT = -1.0;
const std::string NO_DATA = "n/a";
const unsigned int MONTH_AUGUST = 8;

class HeathrowRowData
{
public:

  // Populate the data from a line read in from the file
  void fillFromLine(const std::string & line);
  void printData();
  void printDate();

  int getYear();
  int getMonth();
  float getTMax();
  float getTMin();
  float getRain();

private:

  // Notice use of overloading
  void setData(int & intToSet, const std::string & valueString);
  void setData(float & floatToSet, const std::string & valueString);

  void printValue(const int intToPrint);
  void printValue(const float floatToPrint);

  int myYear;
  int myMonth;
  float myTMax;
  float myTMin;
  int myAirFrost;
  float myRain;
  float mySunHours;

};

void HeathrowRowData::setData(int & intToSet, const std::string & valueString)
{
  std::stringstream stream(valueString);
  if(!(stream >> intToSet))
    intToSet = INVALID_INT;
}

void HeathrowRowData::setData(float & floatToSet, const std::string & valueString)
{
  std::stringstream stream(valueString);
  if(!(stream >> floatToSet))
    floatToSet = INVALID_FLOAT;
}

void HeathrowRowData::printValue(const int intToPrint)
{
  if(intToPrint == INVALID_INT)
    std::cout << NO_DATA;
  else
    std::cout << intToPrint;
  // Put a space at the end so they don't all run into each other
  std::cout << " ";
}

void HeathrowRowData::printValue(const float floatToPrint)
{
  if(floatToPrint == INVALID_FLOAT)
    std::cout << NO_DATA;
  else
    std::cout << floatToPrint;
  // Put a space at the end so they don't all run into each other
  std::cout << " ";
}


void HeathrowRowData::fillFromLine(const std::string & line)
{
  std::stringstream lineStream(line); // use this stream for the whole line
  std::string valueString;

  // Year
  std::getline(lineStream, valueString, ' ');
  setData(myYear, valueString);

  // Month
  std::getline(lineStream, valueString, ' ');
  setData(myMonth, valueString);

  // T_max
  std::getline(lineStream, valueString, ' ');
  setData(myTMax, valueString);

  // T_max
  std::getline(lineStream, valueString, ' ');
  setData(myTMin, valueString);

  // Air frost
  std::getline(lineStream, valueString, ' ');
  setData(myAirFrost, valueString);

  // Rain
  std::getline(lineStream, valueString, ' ');
  setData(myRain, valueString);

  // Sun hours
  std::getline(lineStream, valueString, ' ');
  setData(mySunHours, valueString);
}

void HeathrowRowData::printData()
{
  printValue(myYear);
  printValue(myMonth);
  printValue(myTMax);
  printValue(myTMin);
  printValue(myAirFrost);
  printValue(myRain);
  printValue(mySunHours);

  std::cout << "\n";
}

void HeathrowRowData::printDate()
{
  printValue(myMonth);
  std::cout << "/ ";
  printValue(myYear);
}

int HeathrowRowData::getYear()
{
  return myYear;
}

int HeathrowRowData::getMonth()
{
  return myMonth;
}

float HeathrowRowData::getTMax()
{
  return myTMax;
}

float HeathrowRowData::getTMin()
{
  return myTMin;
}

float HeathrowRowData::getRain()
{
  return myRain;
}

int main()
{
  std::string line;
  std::ifstream dataFile("heathrow.dat");


  HeathrowRowData heathrowData[MAX_ROWS];
  unsigned int rowsRead = 0;

  if(dataFile.is_open())
  {
    for(unsigned int i = 0; i < MAX_ROWS && dataFile.good(); ++i)
    {
      std::getline(dataFile, line);
      if(!line.empty())
      {
        heathrowData[i].fillFromLine(line);
        ++rowsRead;
      }
    }
    dataFile.close();
  }


  // Initialise to 0
  float totalRainfall[12] = {0.0};
  unsigned int totalMonthsOfData[12] = {0};

  float minTemp = heathrowData[0].getTMin();
  float maxTemp = heathrowData[0].getTMax();
  unsigned int frostiestAugustIndex = INVALID_INT;
  
  for(unsigned int i = 0; i < rowsRead; ++i)
  {
    // Have to subtract 1 in square brackets because months go 1..12
    if(heathrowData[i].getRain() != INVALID_FLOAT)
    {
      const unsigned int monthIndex = heathrowData[i].getMonth() - 1;
      totalRainfall[monthIndex] += heathrowData[i].getRain();
      ++totalMonthsOfData[monthIndex];
    }

    if(heathrowData[i].getTMin() != INVALID_INT)
      minTemp = std::min(minTemp, heathrowData[i].getTMin());

    if(heathrowData[i].getTMax() != INVALID_INT)
      maxTemp = std::max(maxTemp, heathrowData[i].getTMax());
    
    if(heathrowData[i].getMonth() == MONTH_AUGUST)
    {
      if(frostiestAugustIndex == INVALID_INT)
        frostiestAugustIndex = i;
      else if(heathrowData[i].getTMin() < heathrowData[frostiestAugustIndex].getTMin())
        frostiestAugustIndex = i;
    }
  }

  // Go through the months calculating the averages
  unsigned int raniestMonth = 0;
  for(unsigned int i = 0; i < 12; ++i)
  {
    totalRainfall[i] /= static_cast<float>(totalMonthsOfData[i]);
    if(totalRainfall[i] > totalRainfall[raniestMonth])
      raniestMonth = i;
  }
  // Need to add 1 to raniest month to get back to 1..12 range
  std::cout << "Raniest month: " << raniestMonth + 1  << "\n";

  std::cout << "Temperatures - min: " << minTemp << ", max: " << maxTemp <<
    ", mean: " << 0.5 * (maxTemp - minTemp) + minTemp  << "\n";

  std::cout << "Frostiest August: ";
  heathrowData[frostiestAugustIndex].printDate();
  std::cout << " temperature: " << heathrowData[frostiestAugustIndex].getTMin() << "\n";


  return 0;
}
