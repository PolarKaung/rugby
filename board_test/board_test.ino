#include <SoftwareSerial.h>
#include "functions.h"
#include <Servo.h>

/////////////////////////////Variables///////////////////////////////
int state = 1; //State of the led 13
int txPin = 2; //Arduino Tx pin to Bluetooth module Rx
int rxPin = 3; //Arudino Rx pin to Bluetooth module Tx
char rxChar; //Character received from Bluetooth module
char _speed = '5'; //Speed of the vehicle
char _direction = 'S'; //Direction of the vehicle
char _temp; //Temporary receiver
int speed_ = 1500;

#define MOTOR_RIGHT_BACK 9 //Motor pin
#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
/////////////////////////////////////////////////////////////////////

Servo motor_right_back;
SoftwareSerial myBt (rxPin, txPin);

void setup() {
  pinMode(13, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(MOTOR_RIGHT_BACK, OUTPUT);

  motor_right_back.attach(MOTOR_RIGHT_BACK);
  myBt.begin(38400);
  Serial.begin(9600);

  motor_right_back.writeMicroseconds(MAX_SIGNAL);
  delay(2000);
  motor_right_back.writeMicroseconds(MIN_SIGNAL);
  delay(5000);
}

void loop() {
  Serial.print("Speed: ");Serial.println(_speed);
  Serial.print("Direction: ");Serial.println(_direction);

  switch (_direction) {
    case 'F': forward(speed_); break;
    case 'B': backward(speed_); break;
    case 'L': circleLeft(speed_); break;
    case 'R': circleRight(speed_); break;
    case 'S': _stop(1000); break;  
  }
  
  while (myBt.available() > 0) {
    _temp = myBt.read();
    rxChar = ((_temp > 47 && _temp < 58) || (_temp > 64 && _temp < 91) || (_temp > 96 && _temp < 123)) ? _temp : 'S';   
//    Serial.print(_temp);
  }

  if ((rxChar > 47 && rxChar < 58) || rxChar == 'q') {
    _speed = rxChar;
    switch (_speed) {
      case '0': speed_ = 1000; break;
      case '1': speed_ = 1100; break;
      case '2': speed_ = 1200; break;
      case '3': speed_ = 1300; break;
      case '4': speed_ = 1400; break;
      case '5': speed_ = 1500; break;
      case '6': speed_ = 1600; break;
      case '7': speed_ = 1700; break;
      case '8': speed_ = 1800; break;
      case '9': speed_ = 1900; break;
      case 'q': speed_ = 2000; break;
    }
  } else {
    _direction = rxChar;
  }
  
  if (Serial.available()) {
    rxChar = Serial.read();
    myBt.write(rxChar);
  }
//  delay(200);
}
