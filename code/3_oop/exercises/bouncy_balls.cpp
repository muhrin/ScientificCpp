#include <iostream>
#include <time.h>

const double FLOOR_Y = 0;

void getSomeSleep(const unsigned int);

class Ball
{
public:

//TODO: Write a Ball constructor that takes the following parameters:
/*
  An initial x position
  An initial y position
  An initial x velocity
  An initial y velocity
  A squishiness

  Assign them to the members of the class.
  
    const double initialPosX,
    const double initialPosY,
    const double initialVelX,
    const double initialVelY,
    const double squishiness)

*/



  void advancePosition(const double timestep)
  {
// TODO: Advance the positions:
/*
  We want to simulate a ball that is affected by gravity so:

  Using x = u * t advance the x position (there is no x acceleration)
  Using v = u + a * t set the new y velocity including a gravitational acceleration (10.0 is fine - careful about sign)
  Using y = u * t advance the y position using the new y velocity

  Now detect if the bouncy ball has hit the ground:

  if the new y position is less than or equal to Y_FLOOR then set it to Y_FLOOR
  and nagate its velocity.
  Now, squishiness tells you how much energy loss there is when it hits the ground
  so multiply the new negated velocity by some factor of the squishiness that goes
  inversely to it.

*/


    if(myY <= FLOOR_Y)
    {
      myY = FLOOR_Y;
      myVelY = -(1.0 / mySquishiness) * myVelY;
    }
  }

  void printPosition()
  {
// Todo: print out the current x and y coordinates separated by a space and followed by a newline
  }

private:

  double myX;
  double myY;
  double myVelX;
  double myVelY;
  double mySquishiness;
};

int main()
{
  while(true)
  {
    double xVel, squishiness;
    std::cout << "#Enter initial x velocity and squishiness: ";
    std::cin >> xVel >> squishiness;

    if(squishiness == 0.0)
      return 0;

    const double timestep = 0.1;

// TODO: Instantiate (i.e. create) a Ball called myBall passing in the parameters:
/*
  initial x = 0
  initial y = 100
  initial x velocity = xVel
  initial y velocity = 0.0
  squishiness = squishiness

*/
    double maxTime = 100.0;
    double time = 0.0;
    while(time < maxTime)
    {
      myBall.printPosition();
      myBall.advancePosition(timestep);
      time += timestep;
      getSomeSleep(300);
    }
  }
  return 0;
}

// Some code to make sure the game doesn't run too fast!
void getSomeSleep(const unsigned int mseconds)
{
  const clock_t goal = mseconds + clock();
  while (goal > clock());
}
