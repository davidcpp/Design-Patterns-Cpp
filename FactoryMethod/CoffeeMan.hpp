#pragma once
#include <memory>
#include "Coffee.hpp"

class CoffeeManufacturer
{
public:
  virtual unique_ptr<Coffee> createCoffee(Coffee::TypeOfCoffee typeOfCoffee);
};

class LavazzaManufacturer : public CoffeeManufacturer
{
public:
  virtual unique_ptr<Coffee> createCoffee(Coffee::TypeOfCoffee typeOfCoffee) override;
};