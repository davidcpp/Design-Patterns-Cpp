#include "CoffeeMan.hpp"
#include "Coffee.hpp"

unique_ptr<Coffee> CoffeeManufacturer::createCoffee(Coffee::TypeOfCoffee typeOfCoffee)
{
  switch (typeOfCoffee)
  {
  case Coffee::TypeOfCoffee::INSTANT:
    return make_unique<InsantCoffee>();
    break;
  case Coffee::TypeOfCoffee::GROUND:
    return make_unique<GroundCoffee>();
    break;
  case Coffee::TypeOfCoffee::BEANS:
    return make_unique<BeansCoffee>();
    break;
  default:
    return make_unique<BeansCoffee>();
    break;
  }
}

unique_ptr<Coffee> LavazzaManufacturer::createCoffee(Coffee::TypeOfCoffee typeOfCoffee)
{
  switch (typeOfCoffee)
  {
  case Coffee::TypeOfCoffee::CHOCOLATE:
    return make_unique<ChocolateCoffee>();
    break;
  default:
    return CoffeeManufacturer::createCoffee(typeOfCoffee);
    break;
  }
}
