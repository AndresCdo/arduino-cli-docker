/*
  Adding Strings together
 
 Examples of how to add strings together
 You can also add several different data types to string, as shown here:
 
 created 27 July 2010
 modified 2 Apr 2012
 by Tom Igoe
 
 http://arduino.cc/en/Tutorial/StringAdditionOperator
 
 This example code is in the public domain. 
 */

// declare three strings:
String stringOne, stringTwo, stringThree;

void setup() {
  // initialize serial and wait for port to open:
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);
  Serial.begin(9600);
}

/**
 * The main loop function that runs repeatedly in the Arduino program.
 * It reads analog sensor values, calculates voltages, and prints the data to the serial monitor.
 */
void loop() {
  // read the input on analog pins 0 and 1:
  int sensorValue_1 = analogRead(A0);
  int sensorValue_2 = analogRead(A1);

  // print out the value you read:
  float voltage_1 = sensorValue_1 * (5.0 / 1023.0);
  float voltage_2 = sensorValue_2 * (5.0 / 1023.0);
  Serial.print("{\"t\":");
  Serial.print(millis());
  Serial.print(",\"v1\":");
  Serial.print(voltage_1);
  Serial.print(",\"v2\":");
  Serial.print(voltage_2);
  Serial.println("}");

  // wait for a bit so as not to send massive amounts of data
  delay(100);

  // clear the string:
  stringOne = String();
}
