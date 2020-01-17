#include <SoftwareSerial.h>

SoftwareSerial bt(2,3);

char recieveByte;
char direction_ = 'S';
char speed_ = '5';
char _speed;
void setup() {
  bt.begin(38400);
  Serial.begin(9600);
}

void loop() {
  while (bt.available() > 0) {
    char _temp = bt.read();
    recieveByte = ((_temp > 47 && _temp < 58) || (_temp > 64 && _temp < 91) || (_temp > 96 && _temp < 123)) ? _temp : 'S';   
  }

  if (Serial.available()) {
    char rxChar = Serial.read();
    bt.write(rxChar);
  }

  if ((recieveByte > 47 && recieveByte < 58) || recieveByte == 'q') {
    switch (recieveByte) {
      case '0': speed_ = 1000; break; ////// change
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
    direction_ = recieveByte;
  }
  
}
