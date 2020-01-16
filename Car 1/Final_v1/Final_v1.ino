#include "controller_without_switches.h"

void setup() {
  Serial.begin(9600);
  
  pinMode(forward_backward_channel,INPUT);
  pinMode(right_left_channel,INPUT);
  pinMode(speed_channel,INPUT);
}

void loop() {
  recieve();
}
