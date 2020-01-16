#include <Servo.h>

#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
#define MOTOR_PIN 9

Servo motor;

void setup() {
  Serial.begin(9600);
  Serial.println("Program begin...");
  Serial.println("This program will calibrate the ESC.");

  motor.attach(MOTOR_PIN);

  Serial.println("Now writing maximum output.");
  Serial.println("Turn on power source, then wait 2 seconds and press any key.");
//  motor.writeMicroseconds(MAX_SIGNAL);
//  delay(2000);
//  // Wait for input
////  while (!Serial.available());
////  Serial.read();
//
//  // Send min output
////  Serial.println("Sending minimum output");
//  motor.writeMicroseconds(MIN_SIGNAL);
//  delay(5000);

}

void loop() {  
//  for ( int i = MIN_SIGNAL; i < MAX_SIGNAL; i+= 100){
//    delay(700);
//  }
   motor.writeMicroseconds(1000);
  
}
