int forward_backward_channel = 2;//channel 2
int right_left_channel = 3; //channel 1
int speed_channel = 4; //channel 3

long f_b_channel_us = 0;
long r_l_channel_us = 0;
long s_channel_us = 0;

int f_b = 0;
int r_l = 0;

long r_l_min_us = 1200;
long r_l_max_us = 2048;

long f_b_min_us = 1140;
long f_b_max_us = 1930;

long s_min_us = 1190;
long s_max_us = 1850;

long center_f_b = 0;
long center_r_l = 0;
long min_speed = 0;

long timeout = 150000;
void setup() {
  Serial.begin(9600);
  
  pinMode(forward_backward_channel,INPUT);
  pinMode(right_left_channel,INPUT);
  pinMode(speed_channel,INPUT);
}

void loop() {
  f_b_channel_us = pulseIn(forward_backward_channel,HIGH,timeout);
  r_l_channel_us = pulseIn(right_left_channel,HIGH,timeout);
  s_channel_us = pulseIn(speed_channel,HIGH,timeout);

  float f_b_dir = map(f_b_channel_us,f_b_min_us,f_b_max_us,0,100);
  float r_l_dir = map(r_l_channel_us,r_l_min_us,r_l_max_us,0,100);
  int speed = map(s_channel_us, s_min_us, s_max_us, 0, 255);
  if ( f_b_dir >= 55) {
    f_b = 1;
  } else if (f_b_dir <= 45) {
    f_b = -1;
  } else {
    f_b = 0;
  }

  if ( r_l_dir >= 55) {
    r_l = 1;
  } else if (r_l_dir <= 45) {
    r_l = -1;
  } else {
    r_l = 0;
  }

//  Serial.print(f_b);Serial.print("  ");Serial.print(r_l);Serial.print("   ");Serial.println(speed);
 Serial.println(speed);
 delay(100);
}
