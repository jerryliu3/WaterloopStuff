#include <Servo.h>//Using servo library to control ESC
Servo esc; //Creating a servo class with name as esc

  int maxVal = 1500;
  
void setup()
{
  delay(10000);
  Serial.begin(9600); //Setup input/output screen
  Serial.print("Starting");
  int pin = 2; //Specify the pin connection (D8)
  esc.attach(pin); //Specify the esc signal pin



  
/*   To configure first time (may have to do for loop instead of the two lines)*/
  esc.writeMicroseconds(2000);
  esc.writeMicroseconds(1000);  
}

void loop()
{
  Serial.println("Void loop");
  delay(3000);

  //Throttle up and down to configure ESC (5 secods to throttle up and 5 seconds to throttle down - can change the delay to change the throttle up and down times)
  for (int i = 1000; i <= maxVal; i++){ //Throttle up
    esc.writeMicroseconds(i);
    Serial.println(i);
    delay(10);
  }
  for (int i = maxVal; i >= 1000; i--){ //Throttle down
    esc.writeMicroseconds(i);
    Serial.println(i);
    delay(10);
  }
}

