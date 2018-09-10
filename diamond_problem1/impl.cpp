#include <iostream>

using namespace std;

class Animal 
{
 public:
  virtual void eat()
  {
    cout << "Animal::eat()" << endl;
  }
};

class Mammal : public Animal 
{
 public:
  void breathe()
  {
    cout << "Animal::breathe()" << endl;
  }
};

class WingedAnimal : public Animal 
{
 public:
  void flap()
  {
    cout << "WingedAnimal::flap()" << endl;
  }
};

// A bat is a winged mammal
class Bat : public Mammal, public WingedAnimal 
{
};

int main()
{ 
  Bat bat;
  bat.Mammal::eat();
  bat.WingedAnimal::eat();

  Bat b;
  Animal &mammal = static_cast<Mammal&> (b); 
  Animal &winged = static_cast<WingedAnimal&> (b);  
  mammal.eat();
  winged.eat();
  
  Animal mammal1 = static_cast<Mammal> (b); 
  Animal winged1 = static_cast<WingedAnimal> (b);  
  mammal1.eat();
  winged1.eat();
  
  Animal mammal2 = Mammal(b); 
  Animal winged2 = WingedAnimal(b);  
  mammal2.eat();
  winged2.eat();

  Animal mammal3 = (Mammal) b; 
  Animal winged3 = (WingedAnimal) b;  
  mammal3.eat();
  winged3.eat();

  static_cast<Mammal&>(bat).eat();
  static_cast<WingedAnimal&>(bat).eat();
}
