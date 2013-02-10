// World 

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "snake.h"

// FORWARD DECLARES //////////
class Game;
class WorldObject;

class World
{
public:

  World(const Vector & dimensions = Vector(80, 40));
  ~World();

  void preTick();
  void tick(Game & game);
  void postTick();
  
  void draw();
  
  void insertObject(WorldObject * object);
  void removeObject(WorldObject * object);

  Vector getRandomPoint(const int padding = 0);

  Snake & getSnake();
  const Vector & getDimensions() const;

private:
  typedef std::vector<WorldObject *> Objects;

  Vector myDimensions;
  Snake mySnake;
  Objects myObjects;
  Objects myToInsert;
  Objects myToRemove;
};


#endif
