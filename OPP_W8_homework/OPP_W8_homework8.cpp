#include <iostream>
#include <vector>
using namespace std;

class Animal
{
public:
  Animal(){}


  virtual void speak() { cout << "동물 울음소리" << endl; };
};

class Dog : public Animal
{

public:
Dog(){};
  virtual void speak()
  {
    cout << "멍멍" << endl;
  }
};

class Cat : public Animal
{

public:
Cat(){};
  virtual void speak()
  {
    cout << "야옹" << endl;
  }
};

int main()
{
  Animal *a = new Animal();
  Dog *d = new Dog();
  Cat *c = new Cat();
  vector<Animal *> v;

  a->speak();
  d->speak();
  c->speak();
  Animal *ap = a;
  Animal *ad = d;
  Animal *ac = c;

  v.push_back(ap);
  v.push_back(ad);
  v.push_back(ac);

  cout << "" << endl;

  for (int i = 0; i < v.size(); i++)
  {
    v[i]->speak();
    delete v[i];
  }

  return 0;
}