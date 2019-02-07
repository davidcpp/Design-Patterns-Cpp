#pragma once
#include "RobotBuilders.hpp"

class Director
{
public:
  void setBuilder(RobotBuilder * builder)
  {
    _builder = builder;
  }

  void buildRobot()
  {
    _builder->createNewRobot();
    _builder->buildChassis();
    _builder->buildController();
    _builder->buildPowerSupply();
    _builder->buildSoftware();
  }

  unique_ptr<Robot> getResult() const
  {
    return _builder->getResult();
  }

private:
  RobotBuilder * _builder;
};