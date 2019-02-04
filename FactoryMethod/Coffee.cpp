#include <iostream>
#include "Coffee.hpp"

#pragma region Coffee
void Coffee::prepareBeans()
{
  takeBeans();
  roastBeans();
}

void Coffee::roastBeans()
{
  cout << "Roasting beans\n";
}

void Coffee::takeBeans()
{
  cout << "Taking beans\n";
}
#pragma endregion

#pragma region BeansCoffee
BeansCoffee::BeansCoffee()
{
  cout << "\nCreate coffee beans\n";
  typeOfCoffee = ToC::BEANS;
  caffeineContent = 0.02;
  makeCoffee();
}

void BeansCoffee::makeCoffee()
{
  Coffee::prepareBeans();
}
#pragma endregion

#pragma region ChocolateCoffee
ChocolateCoffee::ChocolateCoffee()
{
  cout << "\nCreate chocolate coffee\n";
  typeOfCoffee = ToC::CHOCOLATE;
  caffeineContent = 0.01;
  makeCoffee();
}

void ChocolateCoffee::makeCoffee()
{
  Coffee::prepareBeans();
  addChocolateExtract();
}

void ChocolateCoffee::addChocolateExtract()
{
  cout << "Adding chocolate extract\n";
}

#pragma endregion

#pragma region GroundCoffee
GroundCoffee::GroundCoffee()
{
  cout << "\nCreate ground coffee\n";
  typeOfCoffee = ToC::GROUND;
  caffeineContent = 0.02;
  makeCoffee();
}

void GroundCoffee::makeCoffee()
{
  Coffee::prepareBeans();
  grindBeans();
}

void GroundCoffee::grindBeans()
{
  cout << "Grinding coffee bean\n";
}
#pragma endregion

#pragma region InsantCoffee
InsantCoffee::InsantCoffee()
{
  cout << "\nCreate instant coffee\n";
  typeOfCoffee = ToC::INSTANT;
  caffeineContent = 0.03;
  makeCoffee();
}

void InsantCoffee::makeCoffee()
{
  Coffee::prepareBeans();
  makeInstant();
};

void InsantCoffee::makeInstant()
{
  cout << "Making instant\n";
};
#pragma endregion