#include <SoftwareSerial.h>
#include "bluetooth.h"
SoftwareSerial bt(2,3);

void setup() {
  bt.begin(38400);
  Serial.begin(9600);
}

void loop() {
  recieve();
}
