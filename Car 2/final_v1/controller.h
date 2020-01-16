int forward_backward_channel = 2;//channel 2    PD2
int right_left_channel = 3; //channel 1         PD3
int speed_channel = 4; //channel 3              PD4

long f_b_channel_us = 0;
long r_l_channel_us = 0;
long s_channel_us = 0;

int f_b = 0;
int r_l = 0;
int speed_ = 0;

long r_l_min_us = 991;
long r_l_max_us = 1981;

long f_b_min_us = 993;
long f_b_max_us = 1981;

long s_min_us = 992;
long s_max_us = 1980;

long center_f_b = 0;
long center_r_l = 0;
long min_speed = 0;

long timeout = 150000;
