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

  ~World();

  void tick(Game & game);
  
  void draw();
  
  void insertObject(WorldObject * object);

  Snake & getSnake();

private:
  Snake mySnake;
  std::vector<WorldObject *> myObjects;
};


#endif
