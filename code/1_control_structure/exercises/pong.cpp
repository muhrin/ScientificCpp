

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

    // TODO: Add controls for the top paddle.  Try them out, do they work?

    ballX += ballVelX;
    ballY += ballVelY;

    // TODO: Make the ball stay within the bounds
    // The bounds are made up by:
    // 0 -> XMAX
    // 0 -> YMAX (WARNING: Y increases going down the screen)

    // If the ball goes past XMAX or below 0 then negate its velocity
    // to make it stay on the screen
    
    // Do the same for Y

    // TODO: Detecting collisions with paddles
    // Now if the ball is about to go off the top or bottom of the screen
    // it may NOT have hit a paddle so check for this
    // The ball will have hit a paddle if it is between e.g.:
    // bottomPaddleX - PADDLE_HALF_SIZE -> bottomPaddleX + PADDLE_HALF_SIZE
    // If this is not then call reset:
    // reset(topPaddleX, bottomPaddleX, ballX, ballY);
    // And up the opposite players score.

    postFrame();

    drawPaddle(topPaddleX, 0);
    drawPaddle(bottomPaddleX, YMAX);
    drawBall((int)ballX, (int)ballY);
    drawScore(topPlayerScore, bottomPlayerScore);
  }

  cleanUp();

  return 0;
}
