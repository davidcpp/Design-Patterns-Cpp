#include<iostream>
#include<string>
#include<memory>
#include "Director.hpp"
#include "Robot.hpp"
#include "RobotBuilders.hpp"

using namespace std;

unique_ptr<CrawlerRobotBuilder> CrawlerRobotBuilder::crawlerRobotBuilder;
unique_ptr<WheeledRobotBuilder> WheeledRobotBuilder::wheeledRobotBuilder;
int CrawlerRobotBuilder::robotCounter = 0;
int WheeledRobotBuilder::robotCounter = 0;

int main()
{
  Director director;

  director.setBuilder(CrawlerRobotBuilder::instance());
  director.buildRobot();
  Robot crawlerRobot = *director.getResult();
  cout << crawlerRobot;
  // show option of creating next Robot object by the same builder
  director.buildRobot();
  Robot nextCrawlerRobot = *director.getResult();
  cout << nextCrawlerRobot;

  director.setBuilder(WheeledRobotBuilder::instance());
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