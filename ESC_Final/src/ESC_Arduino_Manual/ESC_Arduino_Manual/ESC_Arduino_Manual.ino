int maxVal = 3000;
int servoPin = 2;
void setup()
{
  delay(1000);
  Serial.begin(9600); //Setup input/output screen
  Serial.print("Starting");
pinMode(servoPin, OUTPUT);
/*   To configure first time (may have to do for loop instead of the two lines)*/
  digitalWrite(servoPin, HIGH);
  delay(2); // 1000 microseconds
  digitalWrite(servoPin, LOW);
  delay(1);
  digitalWrite(servoPin, HIGH);
  delay(1); // 1000 microseconds
  digitalWrite(servoPin, LOW);
}

void loop()
{
  Serial.println("Void loop");
  delay(3000);

  //Throttle up and down to configure ESC (5 secods to throttle up and 5 seconds to throttle down - can change the delay to change the throttle up and down times)
  for (int i = 1000; i <= maxVal; i++){ //Throttle up
    digitalWrite(servoPin, HIGH);
  delay(i/1000.0); // convert to microseconds not sure if cast properly
  digitalWrite(servoPin, LOW);
    Serial.println(i/1000.0);
    delay(10);
  }
  for (int i = maxVal; i >= 1000; i--){ //Throttle down
  digitalWrite(servoPin, HIGH);
  delay(i/1000.0); // convert to microseconds not sure if cast properly
  digitalWrite(servoPin, LOW);
  Serial.println(i/1000.0);
    delay(10);
  }
}

