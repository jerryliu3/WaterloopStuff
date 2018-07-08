#include <Cosa/Trace.hh>
#include "wloop/ESC.h"
#include "Cosa/UART.hh"

using namespace wlp;

int maxVal = 2000;
ESC::ESC(Board::DigitalPin escPin)
    : esc(escPin, 1) {
	}

void ESC::test() {
	
	delay(3000);  
    //Throttle up and down to configure ESC (5 secods to throttle up and 5 seconds to throttle down - can change the delay to change the throttle up and down times)
  for (int i = 1000; i <= maxVal; i++){ //Throttle up
    esc.high();
	delay(i/1000.0); // convert to microseconds not sure if cast properly
    esc.low();
	trace << i/1000.0 << endl;
    //Serial.println(i);
    delay(10);
  }
  esc.low();
  delay(3000);
    for (int i = maxVal; i >= 1000; i--){ //Throttle down
    esc.high();
	delay(i/1000.0); // convert to microseconds not sure if cast properly
    esc.low();
	trace << i/1000.0 << endl;
    delay(10);
  }
  trace << esc << endl;
}

void ESC::begin() {
	  uart.begin(9600);
  trace.begin(&uart);
  esc.mode(Board::D2, 0);
	/*   To configure first time (may have to do for loop instead of the two lines)*/
    esc.high();
  delay(2); // 1000 microseconds
    esc.low();
  delay(1);
    esc.high();
  delay(1); // 1000 microseconds
    esc.low();
	for (int i = 1800; i <= 1900; i++){ //Throttle up
    esc.high();
	delay(i/1000.0); // convert to microseconds not sure if cast properly
    esc.low();
	trace << i/1000.0 << endl;
    //Serial.println(i);
    delay(10);
  }
}