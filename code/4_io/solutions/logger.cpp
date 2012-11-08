#include <iostream>
#include <fstream>
#include <string>

// Logger abstract class
class Logger
{
public:
  virtual void logMessage( const std :: string & message ) = 0;
  virtual ~ Logger () {}
};


class ScreenLogger : public Logger
{
public:
  virtual void logMessage(const std::string & message);
};

void ScreenLogger::logMessage(const std::string & message)
{
  std::cout << message << std::endl;
}

// File logger - write log to file
class FileLogger : public Logger
{
public:

  FileLogger(const char * filename);

  virtual ~FileLogger();

  virtual void logMessage( const std :: string & message );
private:
  std::ofstream  myFile;
};

FileLogger::FileLogger(const char * filename)
{
  myFile.open(filename);
}

FileLogger::~FileLogger()
{
  if(myFile.is_open())
    myFile.close();
}

void FileLogger::logMessage(const std::string & message)
{
  if(myFile.good())
    myFile << message << "\n";
}

int main ()
{
  // Let's use some stuff to save typing
  using std::cout;
  using std::cin;
  using std::string;

  Logger * myLogger = 0;
  std::string loggerType;
  bool gotValidLoggerType = false;
  do
  {
    cout << "What kind of logger would you like to use [screen,file]: ";

    cin >> loggerType;

    if(loggerType == "screen")
    {
      myLogger = new ScreenLogger();

      gotValidLoggerType = true;
    }
    else if(loggerType == "file")
    {
      string logFilename;
      cout << "Please enter log filename: ";
      cin >> logFilename;
      myLogger = new FileLogger(logFilename.c_str());

      gotValidLoggerType = true;
    }

  } while(!gotValidLoggerType);

  myLogger->logMessage("Hello universe!");
  myLogger->logMessage("How's my log looking?");

  bool quit = false;
  do
  {
    string message;
    cout << "Do you have anything you want to log? ";
    getline(cin, message);

    if(message == "quit")
      quit = true;
    else
      myLogger->logMessage(message);

  } while(!quit);

  return 0;
}
