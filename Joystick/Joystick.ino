#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3);

int X_pin = A0;
int Y_pin = A1;

long X, Y;

long min_ = 0;
long max_ = 1023;

int X_value;
int Y_value;

int i = 0;

char data[4] = {'s', '0','0','e'};
void setup() {
  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT);
  HC12.begin(9600);
  Serial.begin(9600);
}

void loop() {
  X = map(analogRead(X_pin), min_, max_, 0, 100);
  if (X > 51) {
    data[1] = 'x';
  } else if ( X < 49) {
    data[1] = 'X';
  } else {
    data[1] = '0';
  }

  Y = map(analogRead(Y_pin), min_, max_, 0, 100);
  if (Y > 52) {
    data[2] = 'y';
  } else if ( Y < 50) {
    data[2] = 'Y';
  } else {
    data[2] = '0';
  }

  while (HC12.available()) {        // If HC-12 has data
    Serial.write(HC12.read());      // Send the data to Serial monitor
  }
  while (Serial.available()) {      // If Serial monitor has data
    HC12.write(Serial.read());      // Send that data to HC-12
  }
  for (i = 0; i<4; i++) {
    HC12.write(data[i]);
  }
  delay(100);
  
  Serial.println(data[0]);
  
}
