#include<iostream>
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

class RobotBuilder
{
public:
  ~RobotBuilder()
  {
    delete _robot;
    _robot = nullptr;
  }

  virtual void createNewRobot() = 0;
  virtual void buildChassis() = 0;
  virtual void buildController() = 0;
  virtual void buildPowerSupply() = 0;
  virtual void buildSoftware() = 0;

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
  virtual void createNewRobot() override
  {
    _robot = new Robot("Crawler Robot - Dagu DG012-SV"s, ++robotCounter);
  }

  virtual void buildChassis() override
  {
    _robot->setChassis("Dagu DG012-SV"s);
  }

  virtual void buildController() override
  {
    _robot->setController("Raspberry Pi"s);
  }

  virtual void buildPowerSupply() override
  {
    _robot->setPowerSupply("Redox Li-Pol 2200mAh 11.1V 30C"s);
  }

  virtual void buildSoftware() override
  {
    _robot->setSoftware("Raspbian"s);
  }

private:
  static int robotCounter;
};

class WheeledRobotBuilder : public RobotBuilder
{
public:
  virtual void createNewRobot() override
  {
    _robot = new Robot("Wheeled Robot - Dagu Wild Thumper"s, ++robotCounter);
  }

  virtual void buildChassis() override
  {
    _robot->setChassis("Dagu Wild Thumper"s);
  }

  virtual void buildController() override
  {
    _robot->setController("STM32 Discovery"s);
  }

  virtual void buildPowerSupply() override
  {
    _robot->setPowerSupply("Redox Li-Pol 2600mAh 7.4V 20C"s);
  }

  virtual void buildSoftware() override
  {
    _robot->setSoftware("Free RTOS"s);
  }

private:
  static int robotCounter;
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
    _builder->createNewRobot();
    _builder->buildChassis();
    _builder->buildController();
    _builder->buildPowerSupply();
    _builder->buildSoftware();
  }

  Robot* getResult() const
  {
    return _builder->getResult();
  }

private:
  RobotBuilder * _builder;
};

int CrawlerRobotBuilder::robotCounter = 0;
int WheeledRobotBuilder::robotCounter = 0;

int main()
{
  Director director;

  CrawlerRobotBuilder builder1;
  director.setBuilder(&builder1);
  director.buildRobot();
  Robot desirableRobot1 = *director.getResult();
  cout << desirableRobot1;

  WheeledRobotBuilder builder2;
  director.setBuilder(&builder2);
  director.buildRobot();
  Robot desirableRobot2 = *director.getResult();
  cout << desirableRobot2;

  system("PAUSE");
  return 0;
}