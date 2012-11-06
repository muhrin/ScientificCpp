

#include "pong.h"


const int XMIN = 0;
const int XMAX = 60;
const int YMIN = 2;
const int YMAX = 30;
const char BALL[] = "O";
const int PADDLE_SIZE = 9;
const int PADDLE_HALF_SIZE = PADDLE_SIZE / 2;
const char PADDLE[PADDLE_SIZE] = "88888888";
const double BALL_VEL = 0.4;


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
