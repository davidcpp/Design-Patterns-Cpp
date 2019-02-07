#pragma once
#include<string>

using namespace std;

class Robot
{
public:
  Robot(string name, int id)
  {
    _name = name;
    _id = id;
  }

  void setChassis(string chassis)
  {
    _chassis = chassis;
  }

  void setController(string controller)
  {
    _controller = controller;
  }

  void setPowerSupply(string powerSupply)
  {
    _powerSupply = powerSupply;
  }

  void setSoftware(string software)
  {
    _software = software;
  }

  friend ostream& operator<<(ostream& os, Robot& robot)
  {
    os << robot._name << " no. " << robot._id << endl << endl
      << "Specification: " << endl
      << "Chassis: " << robot._chassis << endl
      << "Controller: " << robot._controller << endl
      << "PowerSupply: " << robot._powerSupply << endl
      << "Software: " << robot._software << endl << endl;
    return os;
  }

private:
  string _name;
  string _chassis;
  string _controller;
  string _powerSupply;
  string _software;
  int _id;
};