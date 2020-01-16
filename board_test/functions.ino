void forward(int speed_){
  motor_right_back.writeMicroseconds(speed_);
}

void backward(int speed_){
//  Serial.println("Backward");
}

void circleRight(int speed_) {
//  Serial.println("Right");
}

void circleLeft(int speed_) {
//  Serial.println("Left");
}

void _stop(int speed_){
  motor_right_back.writeMicroseconds(speed_);
}

void _setSpeed(char _speed) {
//  Serial.println("Stop");
}
