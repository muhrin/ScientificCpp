

#ifndef GAME_OBJECTS_H
#define GMAE_OBJECTS_H

#include "Game.h"
#include "snake_game.h"
#include "WorldObject.h"

// FORWARD DECLARES //////////////////////


class Apple : public WorldObject
{
public:
  Apple(const Vector & initialPos);

  virtual void tick(Game & game);

  virtual void draw();

  virtual void eaten(Game & game);

protected:

  virtual void doTick(Game & game) {};

  Vector myPos;
};

// EXERCISE
// Create a BonusApple class that derives from Apple here.
// the class should have the following methods:
// *) A constructor that takes in a lifetime and a vector position
// *) A draw() method as in Apple
// *) An eaten method as in Apple
// *) A private doTick method that will be used to update the BonusApple
// the class should have the following members:
// *) A timeLived member to keep track of how long it's been alive
// *) A constant lifetime member that stores how long the BonusApple should live for
// Now go to GameObjects.cpp and follow the instructions there to complete the
// BonusApple class.


class ObjectGenerator : public WorldObject
{
public:
  ObjectGenerator(): myTimeSinceLastInserted(0.0) {}

  virtual void tick(Game & game);

  virtual void draw() {} // Nothing to draw

private:
  float myTimeSinceLastInserted;
};




#endif
