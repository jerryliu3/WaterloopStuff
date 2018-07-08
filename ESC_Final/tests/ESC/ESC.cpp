#include "Cosa/Trace.hh"
#include "Cosa/UART.hh"
#include "wloop/ESC.h"

wlp::ESC esc(Board::D2);

void setup()
{
  uart.begin(9600);
  trace.begin(&uart);
trace  << "Hello" << endl;
  esc.begin();
}

void loop()
{	

	esc.test();
}