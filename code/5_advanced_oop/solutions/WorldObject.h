
#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

// FORWARD DECLARES ///////////
class Game;

class WorldObject
{
public:
  virtual ~WorldObject() {}

  virtual void tick(Game & game) = 0;

  virtual void draw() = 0;

};

#endif
