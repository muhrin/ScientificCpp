#include <iostream>

const double FLOOR_Y = 0;

class Ball
{
public:

  Ball(
    const double initialPosX,
    const double initialPosY,
    const double initialVelX,
    const double initialVelY,
    const double squishiness)
  {
    myX = initialPosX;
    myY = initialPosY;
    myVelX = initialVelX;
    myVelY = initialVelY;
    mySquishiness = squishiness;
  }


  void advancePosition(const double timestep)
  {
    myX += myVelX * timestep;
    myVelY -= 10 * timestep;
    myY += myVelY * timestep;

    if(myY <= FLOOR_Y)
    {
      myY = FLOOR_Y;
      myVelY = -(1.0 / mySquishiness) * myVelY;
    }
  }

  void printPosition()
  {
    std::cout << myX << " " << myY << "\n";
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
    std::cout << "#Enter initial x velocity and squishiness";
    std::cin >> xVel >> squishiness;

    if(squishiness == 0.0)
      return 0;

    const double timestep = 0.1;
    Ball myBall(0, 100, xVel, 0.0, squishiness);
    double maxTime = 100.0;
    double time = 0.0;
    while(time < maxTime)
    {
      myBall.printPosition();
      myBall.advancePosition(timestep);
      time += timestep;
    }
  }
  return 0;
}
