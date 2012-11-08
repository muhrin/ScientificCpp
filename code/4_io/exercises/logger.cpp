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


// TODO: Write a ScreenLogger class that derives from Logger
// It must have a virtual method called logMessage.
// you should make this print the paramter 'message' that it
// gets to the screen.

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
// Open a file with the name 'filename' using the myFile member
}

FileLogger::~FileLogger()
{
// Here we will be destructed so we need to close the file.  However
// only do it if the file is currently open.  Maybe there was a problem
// somewhere!
}

void FileLogger::logMessage(const std::string & message)
{
// Write the message to the file.  But only if the file is 'good' i.e.
// ready to be written to.
}


// TODO: After you've done everything else in this example:
// Create a new logger called EncryptingLogger that derives from FileLogger.
// Override the logMessage function but this time print encrypt the string by say
// printing it backwards, or printing the 0,2,3rd characters and then the 1,3,4th
// think of something interesting.
// Add the option for encrypt below and instantiate one of these.

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
// TODO: Here instantiate a new dynamically allocated ScreenLogger class
// that will be pointed to by the myLogger pointer.

      gotValidLoggerType = true;
    }
    else if(loggerType == "file")
    {
      string logFilename;
      cout << "Please enter log filename: ";
      cin >> logFilename;
// TODO: Here instantiate a new dynamically allocated FileLogger class
// that will be pointed to by the myLogger pointer.
// To convert the logFilename string to a char array which is what the
// constructor expects you can call the c_str() method.

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

// TODO: Clean up by deleting the myLogger object.

  return 0;
}
