#include <iostream>
#include <cstring>
#include "sensor.h"
#include <ctime>
#include <cstdlib>

using namespace std;



ProximitySensor::ProximitySensor(int st, int sn)  	// kontruktors
{
	st = 0; 										// 0 ir izslegts
	sn = 0;
	sn = rand() % 100000;							// Generee serijas nr
    state = st;										// izsledz sensoru
   	serial_number = sn;								// pieshkjir serijas nr
}  

void ProximitySensor::Set_state(int onof)			// setteris, kuru padod uz iRobot SwitchOnOf

{
	state = onof;									// state ir mainigais, kuru piekjir pie: void iRobot::SwitchOnOff(int on)
}

int ProximitySensor::Get_state()					// getteris, kuru padodu uz: iRobot::Run,  prieksh tam lai palaistu run funkciju vai nee
{
   return state;
}

bool ProximitySensor::Scan(int area)				// skeneris, kursh atgriezh vai prieksha ir skerslis
{
	if(area%2 == 0)									// ja paara skaitlis, atgriezh True - shkerslis ir
		return true;
	else											// ja nepaara skaitlis, tad false - shkerslis nav
		return false;
}

void ProximitySensor::PrintSensor()					// izdruka sensoru
{
	if(state == 0)									// 0, ja sensors izslegts
		cout << "Sensors izslegts" << endl
		<< "S/N: " << serial_number << endl;
	else if(state == 1)								// 1, ja sensors ieslegts
		cout << "Sensors ieslegts" << endl
		<< "S/N: " << serial_number << endl;
	else
		cout << "Error" << endl;
}
