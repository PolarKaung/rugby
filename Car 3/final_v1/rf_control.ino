void recieve() {
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
//  Serial.println(readBuffer);
  if (readBuffer == "") {
    data = data;
  } else {
    data = readBuffer;
  }
  
  while (Serial.available()) {      // If Serial monitor has data
    HC12.write(Serial.read());      // Send that data to HC-12
  }
  readBuffer = "";

  delay(50);
}
