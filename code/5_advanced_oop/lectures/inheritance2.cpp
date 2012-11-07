#include <iostream>
#include <string>

class Mammal {
public:
  Mammal(const unsigned int age, const unsigned int weight);

  unsigned int getAge();
  void  setAge(const unsigned int age);

  unsigned int getWeight();
  void setWeight(const unsigned int weight);

  void speak();
  
protected:
  unsigned int myAge;
  unsigned int myWeight;
};

Mammal::Mammal(const unsigned int age,
  const unsigned int weight)
{
  myAge = age;
  myWeight = weight;
}

unsigned int Mammal::getAge()
{
  return myAge;
}

void Mammal::setAge(const unsigned int age)
{
  myAge = age;
}

unsigned int Mammal::getWeight()
{
  return myWeight;
}

void Mammal::setWeight(const unsigned int weight)
{
  myWeight = weight;
}

void Mammal::speak()
{
  std::cout << "Grrrr, mammal noise!\n";
}


class Dog : public Mammal {
public:
  Dog(const unsigned int age,
    const unsigned int weight,
    const std::string & breed);

  void wagTail();
  void goFetch(const std::string & fetchWhat);
  // Override Mammal's speak
  void speak();

private:
  const std::string myBreed;
};

Dog::Dog(const unsigned int age,
    const unsigned int weight,
    const std::string & breed):
Mammal(age, weight),
myBreed(breed)
{}

void Dog::wagTail()
{
  std::cout << "\\/\\/\\/ <- That's my tail wagging!\n";
}

void Dog::goFetch(const std::string & fetchWhat)
{
  std::cout << "Fetching " << fetchWhat << "...Here you go.\n";
}

void Dog::speak()
{ std::cout << "Woof!\n"; }

int main() {
  Dog fido(2, 10, "Labrador");
  fido.speak();

  return 0;
}
