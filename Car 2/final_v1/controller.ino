void recieve() {
  f_b_channel_us = pulseIn(forward_backward_channel,HIGH,timeout);
  r_l_channel_us = pulseIn(right_left_channel,HIGH,timeout);
  s_channel_us = pulseIn(speed_channel,HIGH,timeout);

  int f_b_dir = map(f_b_channel_us,f_b_min_us,f_b_max_us,0,100);
  int r_l_dir = map(r_l_channel_us,r_l_min_us,r_l_max_us,0,100);
  speed_ = map(s_channel_us, s_min_us, s_max_us, 0, 255);
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

  Serial.println(speed_);
//  delay(100);
}
