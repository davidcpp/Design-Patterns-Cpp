#include<iostream>
#include<string>

using namespace std;

class Robot
{
public:
  Robot() {}

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

private:
  string _chassis;
  string _controller;
  string _powerSupply;
  string _software;
};

class Director
{
public:
  void setBuilder(RobotBuilder * builder)
  {
    _builder = builder;
  }

  void buildRobot()
  {
    _builder->setChassis();
    _builder->setController();
    _builder->setPowerSupply();
    _builder->setSoftware();
  }

  Robot* getResult() const
  {
    return _builder->getResult();
  }

private:
  RobotBuilder * _builder;
};

class RobotBuilder
{
public:
  RobotBuilder()
  {
    _robot = new Robot();
  }

  ~RobotBuilder()
  {
    _robot = nullptr;
    delete _robot;
  }

  virtual void setChassis() = 0;
  virtual void setController() = 0;
  virtual void setPowerSupply() = 0;
  virtual void setSoftware() = 0;

  Robot * getResult() const
  {
    return _robot;
  }

protected:
  Robot * _robot;
};

class CrawlerRobotBuilder : public RobotBuilder
{
public:
  virtual void setChassis() override
  {
    _robot->setChassis("Dagu DG012-SV"s);
  }

  virtual void setController() override 
  {
    _robot->setController("Raspberry Pi"s);
  }

  virtual void setPowerSupply() override 
  {
    _robot->setPowerSupply("Redox Li-Pol 2200mAh 11.1V 30C"s);
  }

  virtual void setSoftware() override
  {
    _robot->setSoftware("Raspbian"s);
  }

private:
};

class WheeledRobotBuilder : public RobotBuilder
{
public:
  virtual void setChassis() override
  {
    _robot->setChassis("Dagu Wild Thumper"s);
  }

  virtual void setController() override
  {
    _robot->setController("STM32 Discovery"s);
  }

  virtual void setPowerSupply() override
  {
    _robot->setPowerSupply("Redox Li-Pol 2600mAh 7.4V 20C"s);
  }

  virtual void setSoftware() override
  {
    _robot->setSoftware("Free RTOS"s);
  }

private:
};

int main()
{
  Director director;

  CrawlerRobotBuilder builder1;
  director.setBuilder(&builder1);
  director.buildRobot();
  Robot desirableRobot1 = *director.getResult();

  WheeledRobotBuilder builder2;
  director.setBuilder(&builder2);
  director.buildRobot();
  Robot desirableRobot2 = *director.getResult();

  system("PAUSE");
  return 0;
}