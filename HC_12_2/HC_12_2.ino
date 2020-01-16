#include <SoftwareSerial.h>

byte incomingByte;
String readBuffer = "";

SoftwareSerial HC12(2,3);
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);
  digitalWrite(7,HIGH);
}

void loop() {
  boolean start = false;
  while (HC12.available()) {        // If HC-12 has data
    incomingByte = HC12.read();          // Store each icoming byte from HC-12
    delay(5);
    if (start == true) {
      if ( incomingByte!='e') {
        readBuffer += char(incomingByte);
      } else {
        start = false;
      }
    } else if (incomingByte == 's') {
      start = true;
    }
     
  }
  Serial.println(readBuffer);
  
  while (Serial.available()) {      // If Serial monitor has data
    HC12.write(Serial.read());      // Send that data to HC-12
  }
  readBuffer = "";

  delay(50);
}
