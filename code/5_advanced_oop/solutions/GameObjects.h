

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

class BonusApple : public Apple
{
public:
  BonusApple(const float lifetime, const Vector & pos);

  virtual void draw();
  virtual void eaten(Game & game);

private:

  virtual void doTick(Game & game);

  float myTimeLived;
  const float myLifetime;
};

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
