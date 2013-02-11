

#include "GameObjects.h"

extern "C"
{
#  include <ncurses.h>
}

Apple::Apple(const Vector & initialPos):
myPos(initialPos)
{}

void Apple::tick(Game & game)
{
  const Vector snakePos = game.getWorld().getSnake().getHeadPos();
  // We've been eaten by the snake
  if(snakePos == myPos)
    eaten(game);
  else
    doTick(game);
}

void Apple::draw()
{
  draw(myPos, "*");
}

void Apple::eaten(Game & game)
{
  // Up the score
  game.changeScore(1);
  game.getWorld().getSnake().resize(1);
  // Move our position
  myPos = game.getWorld().getRandomPoint();
}

BonusApple::BonusApple(const float lifetime, const Vector & pos):
Apple(pos),
myTimeLived(0.0),
myLifetime(lifetime)
{}

void BonusApple::draw()
{
  mvprintw(myPos, "B");
}
 
void BonusApple::eaten(Game & game)
{
  // Up the score
  game.changeScore(10);
  game.getWorld().removeObject(this);
}

void BonusApple::doTick(Game & game)
{
  myTimeLived += game.getElapsedTime();
  if(myTimeLived >= myLifetime)
    game.getWorld().removeObject(this);
}

void ObjectGenerator::tick(Game & game)
{
  myTimeSinceLastInserted += game.getElapsedTime();

  if(myTimeSinceLastInserted > 10.0)
  {
    game.getWorld().insertObject(new BonusApple(6.0, game.getWorld().getRandomPoint()));
    myTimeSinceLastInserted = 0.0;
  }
}
