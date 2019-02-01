#include <iostream>
#include <string>

using namespace std;

#pragma region Coffee

class Coffee
{
public:
  enum class TypeOfCoffee
  {
    BEANS,
    CHOCOLATE,
    GROUND,
    INSTANT,
    DEFAULT
  };

protected:
  TypeOfCoffee typeOfCoffee;
  double caffeineContent;

  void prepareBeans()
  {
    takeBeans();
    roastBeans();
  }

private:
  virtual void makeCoffee() = 0;

  void roastBeans()
  {
    cout << "Roasting beans\n";
  }

  void takeBeans()
  {
    cout << "Taking beans\n";
  }
};
using ToC = Coffee::TypeOfCoffee;

class BeansCoffee : public Coffee
{
public:
  BeansCoffee()
  {
    typeOfCoffee = ToC::BEANS;
    caffeineContent = 0.02;
    makeCoffee();
  }

private:
  virtual void makeCoffee() override
  {
    Coffee::prepareBeans();
  }
};

class ChocolateCoffee : public Coffee
{
public:
  ChocolateCoffee()
  {
    typeOfCoffee = ToC::CHOCOLATE;
    caffeineContent = 0.01;
    makeCoffee();
  }

private:
  virtual void makeCoffee() override
  {
    Coffee::prepareBeans();
    addChocolateExtract();
  }

  void addChocolateExtract()
  {
    cout << "Adding chocolate extract\n";
  }
};

class GroundCoffee : public Coffee
{
public:
  GroundCoffee()
  {
    typeOfCoffee = ToC::GROUND;
    caffeineContent = 0.02;
    makeCoffee();
  }

private:
  virtual void makeCoffee() override
  {
    Coffee::prepareBeans();
    grindBeans();
  }

  void grindBeans()
  {
    cout << "Grinding coffee bean\n";
  }
};

class InsantCoffee : public Coffee
{
public:
  InsantCoffee()
  {
    typeOfCoffee = ToC::INSTANT;
    caffeineContent = 0.03;
    makeCoffee();
  }

private:
  virtual void makeCoffee() override
  {
    Coffee::prepareBeans();
    makeInstant();
  };

  void makeInstant()
  {
    cout << "Making instant\n";
  };
};

#pragma endregion

#pragma region CoffeeMan

class CoffeeManufacturer
{
public:
  virtual unique_ptr<Coffee> createCoffee(ToC typeOfCoffee)
  {
    switch (typeOfCoffee)
    {
    case ToC::INSTANT:
      return make_unique<InsantCoffee>();
      break;
    case ToC::GROUND:
      return make_unique<GroundCoffee>();
      break;
    case ToC::BEANS:
      return make_unique<BeansCoffee>();
      break;
    default:
      return make_unique<BeansCoffee>();
      break;
    }
    return nullptr;
  }
};

class LavazzaManufacturer : public CoffeeManufacturer
{
public:
  virtual unique_ptr<Coffee> createCoffee(ToC typeOfCoffee) override
  {
    switch (typeOfCoffee)
    {
    case ToC::CHOCOLATE:
      return make_unique<ChocolateCoffee>();
      break;
    default:
      return CoffeeManufacturer::createCoffee(typeOfCoffee);
      break;
    }
  }
};

#pragma endregion

using ToC = Coffee::TypeOfCoffee;

int main()
{
  unique_ptr<Coffee> defaultCoffee;
  unique_ptr<Coffee> insCoffee;
  unique_ptr<Coffee> grCoffee;
  unique_ptr<Coffee> beansCoffee;
  unique_ptr<Coffee> chocCoffee;

  CoffeeManufacturer *lavazzaMan = new LavazzaManufacturer();
  defaultCoffee = lavazzaMan->createCoffee(ToC::DEFAULT);
  insCoffee = lavazzaMan->createCoffee(ToC::INSTANT);
  beansCoffee = lavazzaMan->createCoffee(ToC::BEANS);
  grCoffee = lavazzaMan->createCoffee(ToC::GROUND);
  chocCoffee = lavazzaMan->createCoffee(ToC::CHOCOLATE);

  system("PAUSE");
  return 0;
}