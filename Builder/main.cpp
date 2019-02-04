#include<iostream>

using namespace std;

class Robot
{
public:
  Robot() {}
private:

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
  virtual void setChassis() override {}
  virtual void setController() override {}
  virtual void setPowerSupply() override {}
  virtual void setSoftware() override {}

private:
};

class WheeledRobotBuilder : public RobotBuilder
{
public:
  virtual void setChassis() override {}
  virtual void setController() override {}
  virtual void setPowerSupply() override {}
  virtual void setSoftware() override {}

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