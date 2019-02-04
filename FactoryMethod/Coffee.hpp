#pragma once
using namespace std;

class Coffee
{
public:
  enum class TypeOfCoffee
  {
    BEANS,
    CHOCOLATE,
    DEFAULT,
    GROUND,
    INSTANT
  };
  using ToC = Coffee::TypeOfCoffee;

protected:
  TypeOfCoffee typeOfCoffee;
  double caffeineContent;
  void prepareBeans();

private:
  virtual void makeCoffee() = 0;
  void roastBeans();
  void takeBeans();
};

class BeansCoffee : public Coffee
{
public:
  BeansCoffee();
private:
  virtual void makeCoffee() override;
};

class ChocolateCoffee : public Coffee
{
public:
  ChocolateCoffee();
private:
  virtual void makeCoffee() override;
  void addChocolateExtract();
};

class GroundCoffee : public Coffee
{
public:
  GroundCoffee();
private:
  virtual void makeCoffee() override;
  void grindBeans();
};

class InsantCoffee : public Coffee
{
public:
  InsantCoffee();
private:
  virtual void makeCoffee() override;
  void makeInstant();
};
