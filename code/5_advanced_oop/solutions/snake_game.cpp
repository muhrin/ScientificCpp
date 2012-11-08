
#include "snake_game.h"
#include "snake.h"

void World::tick(World & world, const double timestep, const int keypress)
{
  for(int i = 0; i < myObjects.size(); ++i)
  {
    myObject[i].tick(world, timestep, keypress);
  }
}
  
void World::draw(const World & world)
{
  for(int i = 0; i < myObjects.size(); ++i)
  {
    myObject[i].draw(*this);
  }
}

void World::insertObject(WorldObject * object)
{
  myObjects.push_back(object);
}

int main()
{
  World myWorld;

  init();

  bool quit = false;
  double elapsedTime = 0.0;

  int key;
  while(!quit)
  {
    preFrame();
    
    key = getKey();

    myWorld.tick(myWorld, elapsedTime, key);
    myWorld.draw(myWorld);

    postFrame();
  }

  cleanUp();

  return 0;
}
}
