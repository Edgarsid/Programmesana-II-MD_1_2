#ifndef IROBOT_H
#define IROBOT_H
#include <cstring>
#include "sensor.h"

using namespace std;

class iRobot												// klase irobot
{
public:
   	iRobot(string, int, int, string, string, int, int);		// konstruktors
  	void SwitchOnOff(int);									// iesledz robotu
  	void Run(int[]);										// palaist run
  	void PrintRobot();										// izdruka robota info
  	void PrintSensor();										// izdruka sensora info

private:													// lauki
	string model_name;
	int LeftSensor;
	int RightSensor;
	string alarm_r_g;
	string map;
   	ProximitySensor ps;										// mainigais, lai piekljutu sensora klases parametriem
};

#endif
