#ifndef SENSOR_H
#define SENSOR_H

class ProximitySensor				// klase
{
public:
   	ProximitySensor(int, int);		// konstruktors
  	void Set_state(int);			// sensora sledzis setteris
  	int Get_state();				// sensora sledzis getteris
  	bool Scan(int);					// skeneris
  	void PrintSensor();				// izdruka sensora datus

private:
   	int state;						// stavoklis
	int serial_number;				// serijas numurs
};


#endif
