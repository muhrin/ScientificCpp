#include <iostream>


class Vector2;

class Body
{
public:
  Planet(const mass)
  {
    myMass = mass;
  }

  double getMass()
  {
    return myMass;
  }

  Vector2 getPosition()
  {
    return myPos;
  }

  void addToForce(Vector2 & force)
  {
    myForce += force;
  }

  void clearForce()
  {
    myForce.zero();
  }

private:
  Vector2 myPos;
  Vector2 myVelocity;
  Vector2 myForce;
  double myMass;
}

void advanceTimestep(double timestep, Body & body)
{

}

void advanceSolarSystem()
{

}



int main()
{


}
