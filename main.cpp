#include <iostream>
#include <cstring>
#include "sensor.h"
#include "iRobot.h"
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
	time_t t;
	srand((unsigned) time(&t));								// prieksh serijas nr generacijas
	
	int room_1[10]={23,19,87,56,94,67,81,23,45,77};      	// istaba 1
	int room_2[10]={23,19,87,56,94,  66,81,23,45,77};		// istaba 2, pie 66 ir fail
	
	cout << "Robots 1" << endl;
	iRobot R2_D2 ("R2-D2", 0, 0, "alarm", "", 0, 0);		// piekluve konstruktoram
	R2_D2.PrintSensor();									// Izvada sensora statusu
	R2_D2.SwitchOnOff(1);									// iesledz sensoru ar state 1
	R2_D2.PrintSensor();									// Izvada sensora statusu
	R2_D2.Run(room_1);										// Palaizh robotu istabaa 1
	R2_D2.PrintRobot();										// izdruka map un alarm
	
	
	cout << "Robots 2" << endl;
	iRobot C_3PO ("C-3PO", 0, 0, "alarm", "", 0, 0);		// piekluve konstruktoram
	C_3PO.PrintSensor();									// Izvada sensora statusu
	C_3PO.SwitchOnOff(1);									// iesledz sensoru ar state 1
	C_3PO.PrintSensor();									// Izvada sensora statusu
	C_3PO.Run(room_2);										// Palaizh robotu istabaa 2
	C_3PO.PrintRobot();										// izdruka map un alarm
	
	system("pause");
	return 0;
}
