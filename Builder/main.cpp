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
  virtual void createNewRobot() = 0;
  virtual void buildChassis() = 0;
  virtual void buildController() = 0;
  virtual void buildPowerSupply() = 0;
  virtual void buildSoftware() = 0;

  unique_ptr<Robot> getResult()
  {
    return std::move(_robot);
  }

protected:
  unique_ptr<Robot> _robot;
};

class CrawlerRobotBuilder : public RobotBuilder
{
public:
  virtual void createNewRobot() override
  {
    _robot = make_unique<Robot>("Crawler Robot - Dagu DG012-SV"s, ++robotCounter);
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
    _robot = make_unique<Robot>("Wheeled Robot - Dagu Wild Thumper"s, ++robotCounter);
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

  unique_ptr<Robot> getResult() const
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

  CrawlerRobotBuilder crawlerBuilder;
  director.setBuilder(&crawlerBuilder);
  director.buildRobot();
  Robot crawlerRobot = *director.getResult();
  cout << crawlerRobot;
  // show option of creating next Robot object by the same builder
  director.buildRobot();
  Robot nextCrawlerRobot = *director.getResult();
  cout << nextCrawlerRobot;

  WheeledRobotBuilder wheeledBuilder;
  director.setBuilder(&wheeledBuilder);
  director.buildRobot();
  Robot wheeledRobot = *director.getResult();
  cout << wheeledRobot;
  // show option of creating next Robot object by the same builder
  director.buildRobot();
  Robot nextWheeledRobot = *director.getResult();
  cout << nextWheeledRobot;

  system("PAUSE");
  return 0;
}