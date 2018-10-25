 #include <Servo.h>
 Servo servo1;// create a servo object to control servo1
 Servo servo2; // create a servo object to control servo2

 
 int PressureSensor = A0; //the number for the pressure sensor 
 int val = 0; // the value in which each servo motor will read   
 
void setup(void) {
 Serial.begin(9600);   
 servo1.attach(9);            //servo motor 1 will be attached at digital pin 9
 servo1.write(0);             //initial reading for servo motor 1
 servo2.attach(10);           //servo motor 2 will be attched to digital pin 10
 servo2.write(0);             // initial reading reading for servo motor 2 

}
// the loop routine runs over and over again forever:
 
//read the state of the pressure sensor value
void loop(void) {
  PressureSensor= analogRead(A0); // Pressure sensor will attached to analog 0
  Serial.print("Sensor value = "); // the serial monitor will read sensor value 
  Serial.println(PressureSensor); // the serial monitor will print the value the pressure sensor spits out
 

int value = map(PressureSensor, 0, 1023, 0, 255); // the value that will calibrate the pressure sensors to move the servo motors 

  servo1.write(value); // the value that will move the servo motor 1
  servo2.write(value);.// the value that will move the servo motor 2
 
  delay(100); // delay the loop for a few seconds 
}
