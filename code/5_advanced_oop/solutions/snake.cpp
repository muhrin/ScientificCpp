

#include "snake.h"


const int XMIN = 0;
const int XMAX = 60;
const int YMIN = 2;
const int YMAX = 30;
const char BALL[] = "O";
const int PADDLE_SIZE = 9;
const int PADDLE_HALF_SIZE = PADDLE_SIZE / 2;
const char PADDLE[PADDLE_SIZE] = "88888888";
const double BALL_VEL = 0.05;

class Vector
{
  Vector();
  Vector(const int x, const int y);

  Vector & operator +=(Vector & toAdd);
  Vector & operator -=(Vector & toSub);
  Vector & operator =(Vector & rhs);

  int getX() { return myX; }
  int getY() { return myY; }

private:
  int myX, myY;

};

Vector::Vector()
{
  myX = 0;
  myY = 0;
  return *this;
}

Vector::Vector(const int x, const int y)
{
  myX = x;
  myY = y;
  return *this;
}

Vector & Vector::operator +=(Vector & toAdd)
{
  myX += x;
  myY += y;
  return *this;
}

Vector & Vector::operator -=(Vector & toSub)
{
  myX -= toSub.x;
  myY -= toSub.y;
  return *thisl
}

Vector & Vector::operator =(Vector & rhs)
{
  myX = rhs.getX();
  myY = rhs.getY();
}

class Snake
{
public:


  tick(const float timestep);

  void draw();


private:
  const unsigned int maxSegments = 10;
  const unsigned int startingSegments = 3;
  const char segmentChar = '*';

  const Vector UP;
  const Vector DOWN;
  const Vector LEFT;
  const Vector RIGHT;

  void move();

  Vector myDirection;
  float mySpeed;
  unsigned int mySize;
  Vector mySegments[MAX_SEGMENTS];

};

void Snake::draw()
{
  for(int i = 0; i < mySize; ++i)
  {
    mvprintw(mySegments[i].getY(), mySegments[i].getY(), BALL);
  }
}

void Snake::move()
{
  for(int i = 0; i < mySize - 1; ++i)
  {
    mySegments[i] = mySegments[i + 1];
  }
  mySegments[mySize - 1] += myDirection;
}

int main()
{
  init();

  double ballVelX = BALL_VEL;
  double ballVelY = BALL_VEL;

  int topPaddleX;
  int bottomPaddleX;

  double ballX;
  double ballY;

  unsigned int topPlayerScore = 0;
  unsigned int bottomPlayerScore = 0;

  reset(topPaddleX, bottomPaddleX, ballX, ballY);

  bool quit = false;

  int key;
  while(!quit)
  {
    preFrame();
    
    key = getKey();
    if(key == 's')
      --topPaddleX;
    else if(key == 'd')
      ++topPaddleX;
    else if(key == 'k')
      --bottomPaddleX;
    else if(key == 'l')
      ++bottomPaddleX;
    else if(key == '`')
      quit = true;

    ballX += ballVelX;
    ballY += ballVelY;

    if(ballX >= XMAX)
      ballVelX = -ballVelX;
    else if(ballX <= 0)
      ballVelX = -ballVelX;
    if(ballY >= YMAX)
    {
      ballVelY = -ballVelY;

      if(ballX < (bottomPaddleX - PADDLE_HALF_SIZE) ||
         ballX > (bottomPaddleX + PADDLE_HALF_SIZE))
      {
        reset(topPaddleX, bottomPaddleX, ballX, ballY);
        ++topPlayerScore;
      }
    }
    else if(ballY <= 0)
    {
      ballVelY = -ballVelY;

      if(ballX < (topPaddleX - PADDLE_HALF_SIZE) ||
         ballX > (topPaddleX + PADDLE_HALF_SIZE))
      {
        ++bottomPlayerScore; 
        reset(topPaddleX, bottomPaddleX, ballX, ballY);
      }
    }


    postFrame();

    drawPaddle(topPaddleX, 0);
    drawPaddle(bottomPaddleX, YMAX);
    drawBall((int)ballX, (int)ballY);
    drawScore(topPlayerScore, bottomPlayerScore);
  }

  cleanUp();

  return 0;
}
