#include <iostream>
#include <vector>
#include "Coffee.hpp"
#include "CoffeeMan.hpp"

using ToC = Coffee::TypeOfCoffee;
const ToC coffeeTypes[] = { ToC::BEANS, ToC::CHOCOLATE, ToC::DEFAULT, ToC::GROUND, ToC::INSTANT };

int main()
{
  vector<unique_ptr<Coffee>> createdCoffees;

  CoffeeManufacturer *lavazzaMan = new LavazzaManufacturer();

  for (auto& x : coffeeTypes )
  {
    createdCoffees.emplace_back(lavazzaMan->createCoffee(x));
  }

  cout << '\n';
  system("PAUSE");
  return 0;
}