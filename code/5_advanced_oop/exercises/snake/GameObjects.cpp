
#include "Draw.h"
#include "GameObjects.h"


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
  drawChars(myPos, "*");
}

void Apple::eaten(Game & game)
{
  // Up the score
  game.changeScore(1);
  game.getWorld().getSnake().resize(1);
  // Move our position
  myPos = game.getWorld().getRandomPoint();
}


// EXERCISE
// Here implement the BonusApple constructor
// tell Apple the position in the initialiser list
// also set timeLived to zero and set the lifetime member

// Here implement the BonusApple draw method
// Using the method from Apple above draw a BonusApple but with a different symbol

// Here implement the BonusApple eaten method
// Use the eaten method above to create something similar but give the player
// a higher score and remove the object once it's eaten.  You will need to look
// in World.h to see how to remove objects in the world.

// Here implement the BonusApple doTick method
// you need to get the time elapsed since the last 'tick' from the Game object,
// look this up in Game.h, and add it to the timeLived member to keep track
// of how long the BonusApple has been alive.
// Then check if it has lived for longer than the lifetime.  If so remove the object
// from the world.

// When you're happy with your BonusApple uncomment the indicated line below.
// This method will create a bonus apple every 10 seconds at a random location.
void ObjectGenerator::tick(Game & game)
{
  myTimeSinceLastInserted += game.getElapsedTime();

  if(myTimeSinceLastInserted > 10.0)
  {
//    game.getWorld().insertObject(new BonusApple(6.0, game.getWorld().getRandomPoint())); // <- Uncomment this line
    myTimeSinceLastInserted = 0.0;
  }
}
