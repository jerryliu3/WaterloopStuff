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
//  delay(10000);
//  for (int i = 1000; i <= 2000; i++){ //Throttle up
//    esc.writeMicroseconds(i);
//    Serial.println("Forward : " + String(i));
//    delay(1);
//  }
//  for (int i = 2000; i >= 1000; i--){ //Throttle down
//    esc.writeMicroseconds(i);
//    Serial.println(i);
//    delay(1);
//  }
  
  
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

  /*int val = 10;//Can change this to any number between 0 and 1000
  val = map(val, 0, 1023, 1000, 2000); //converts inputed value (0-1023) to ouput value for ESC (1000-2000)
  esc.writeMicroseconds(val);
  delay(1000);//run for 1 second(s)
    
  esc.writeMicroseconds(1000); //stop
  delay(10000); //wait 10 seconds (remove this if you want to run continuously)*/
}

