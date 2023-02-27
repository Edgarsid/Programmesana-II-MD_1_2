#include <iostream>
#include <cstring>
#include "iRobot.h"
#include "sensor.h"



using namespace std;


iRobot::iRobot(string n, int l, int r, string alarm, string m, int on, int sn) 	// kontruktors
	: ps(on, sn)																// piekljuve sensora klasei
{
	model_name = n;
	LeftSensor = l;
	RightSensor = r;
	alarm_r_g = alarm;
	map = m;
}

void iRobot::SwitchOnOff(int on)							// metode, lai ieslegtu sensorus.  ar 1 main iesledz
{
	ps.Set_state(on);										// setteris no sensora
}

void iRobot::Run(int r[])									// palaizh run.  int r[]  piekljust room masivam
{

	if(ps.Get_state() == 1)									// palaizh, ja sensori ieslegti
	{
		cout << "Run" << endl;
		
		int a;												// mainigais, lai pec 10x izdrukatu "green"
		string m;											// mianigais, lai "uzzimetu" map
	
		for(int i = 0; i < 10; i++)							// cikls, lai uzzimetu map
			{
				LeftSensor = r[i] / 10;						// kreisais senors - piekljust 1. ciparam
				RightSensor = r[i] % 10;					// labais sensors piekljust 2. ciparam
			
				if(ps.Scan(LeftSensor) == false && ps.Scan(RightSensor) == false)   // ja nav shkershlju - iet taisni
					m = "f";
				else if(ps.Scan(LeftSensor) == false && ps.Scan(RightSensor) == true)  // ja skerslis pa labi, iet pa kreisi
					m = "l";
				else if(ps.Scan(LeftSensor) == true && ps.Scan(RightSensor) == false)  // ja skerslis pa kreisi, ie pa labi
					m = "r";
				else
				{
						alarm_r_g = "red";									// else - ja shkersli abas puses
						break;
					}
				map += m;													// "ziimee" map
				++a;
				if(a == 10)													// ja viss ir veiksmigi
					alarm_r_g = "green";
			}
	}
		
	else
		cout << "Switch on device" << endl;									// ja sensori izslegti
}

void iRobot::PrintRobot()													// izdrukat info par robotu
{
	cout << "Map = " << map << endl
	<< "Alarm = " << alarm_r_g << endl << endl;

}

void iRobot::PrintSensor()													// izdrukat info par sensoru
{
	ps.PrintSensor();
}
