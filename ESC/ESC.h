#ifndef CONTROL_RPM_H
#define CONTROL_RPM_H

#include <sensors/Sensor.h>

class ESC : public Sensor{
	const uint8_t pin;
	int rpm = 0;
	unsigned long lastMillis = 0;
public:
	ESC();

	void read();
	void escRequest();
	void radioRequest();
};

#endif //CONTROL_RPM_H