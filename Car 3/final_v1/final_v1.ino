#include "rf_control.h"
#include <SoftwareSerial.h>

SoftwareSerial HC12(2,3);

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);
  digitalWrite(7,HIGH);
}

void loop() {
  recieve();
  if (data[1] == 'Y') {
    if (data[0] == 'X') {
      //forward right
      Serial.println("Forward right");
    } else if (data[0] == 'x') {
      //forward left
      Serial.println("Forward left");
    } else {
      //forward
      Serial.println("Forward");
    }
  }

  else if (data[1] == 'y') {
    if (data[0] == 'X') {
      //backward right
      Serial.println("Backward right");
    } else if (data[0] == 'x') {
      //backward left
      Serial.println("Backward left");
    } else {
      //backward
      Serial.println("Backward");
    }
  } else {
    //standby
    Serial.println("Stand by");
  }
}
