#pragma once
#include <mutex>
#include "Robot.hpp"

using namespace std;

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
  static CrawlerRobotBuilder* instance()
  {
    instanceMutex.lock();
    if (crawlerRobotBuilder.get() == nullptr)
      crawlerRobotBuilder = make_unique<CrawlerRobotBuilder>();
    instanceMutex.unlock();

    return crawlerRobotBuilder.get();
  }

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

  friend unique_ptr<CrawlerRobotBuilder> std::make_unique<CrawlerRobotBuilder>();

private:
  CrawlerRobotBuilder() {}

  static std::mutex instanceMutex;
  static unique_ptr<CrawlerRobotBuilder> crawlerRobotBuilder;
  static int robotCounter;
};

class WheeledRobotBuilder : public RobotBuilder
{
public:
  static WheeledRobotBuilder* instance()
  {
    instanceMutex.lock();
    if (wheeledRobotBuilder.get() == nullptr)
      wheeledRobotBuilder = make_unique<WheeledRobotBuilder>();
    instanceMutex.unlock();

    return wheeledRobotBuilder.get();
  }

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

  friend unique_ptr<WheeledRobotBuilder> std::make_unique<WheeledRobotBuilder>();

private:
  WheeledRobotBuilder() {}

  static std::mutex instanceMutex;
  static unique_ptr<WheeledRobotBuilder> wheeledRobotBuilder;
  static int robotCounter;
};