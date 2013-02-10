
#include "World.h"

#include <algorithm>
#include <cstdlib>

#include "GameObjects.h"
#include "snake_game.h"

World::World(const Vector & dimensions):
myDimensions(dimensions)
{}

World::~World()
{
  for(unsigned int i = 0; i < myToInsert.size(); ++i)
    delete myToInsert[i];
  for(unsigned int i = 0; i < myObjects.size(); ++i)
    delete myObjects[i];
}

void World::preTick()
{
  for(unsigned int i = 0; i < myToInsert.size(); ++i)
    myObjects.push_back(myToInsert[i]);
  myToInsert.clear();
}

void World::tick(Game & game)
{
  // Tick the snake
  mySnake.tick(game);
  for(int i = 0; i < myObjects.size(); ++i)
  // Tick all objects
    myObjects[i]->tick(game);
}

void World::postTick()
{
  for(unsigned int i = 0; i < myToRemove.size(); ++i)
  {
    const Objects::iterator it = std::find(myObjects.begin(), myObjects.end(), myToRemove[i]);

    if(it != myObjects.end())
    {
      const WorldObject * object = *it;
      myObjects.erase(it);
      delete object;
      object = 0;
    }
  }
  myToRemove.clear();
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
  myToInsert.push_back(object);
}

void World::removeObject(WorldObject * object)
{
  myToRemove.push_back(object);
}

Vector World::getRandomPoint(const int padding)
{
  // Generate an x position with padding
  int xPos = rand() % myDimensions.getX();
  if(xPos < padding)
    xPos = padding;
  else if(myDimensions.getX() - xPos + 1 < padding)
    xPos = myDimensions.getX() - 1 - padding;

  // Generate a y position with padding
  int yPos = rand() % myDimensions.getY();
  if(yPos < padding)
    yPos = padding;
  else if(myDimensions.getY() - yPos + 1 < padding)
    yPos = myDimensions.getY() - 1 - padding;

  return Vector(xPos, yPos);
}

Snake & World::getSnake()
{
  return mySnake;
}

const Vector & World::getDimensions() const
{
  return myDimensions;
}



