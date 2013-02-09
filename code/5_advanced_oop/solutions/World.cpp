
#include "World.h"

#include "snake_game.h"


World::~World()
{
  for(int i = 0; i < myObjects.size(); ++i)
    delete myObjects[i];
}

void World::tick(Game & game)
{
  // Tick the snake
  mySnake.tick(game);
  for(int i = 0; i < myObjects.size(); ++i)
  // Tick all objects
    myObjects[i]->tick(game);
}
  
void World::draw()
{
  // Draw the snake
  mySnake.draw();
  // Draw all objects
  for(int i = 0; i < myObjects.size(); ++i)
    myObjects[i]->draw();
}

void World::insertObject(WorldObject * object)
{
  myObjects.push_back(object);
}

Snake & World::getSnake()
{
  return mySnake;
}
