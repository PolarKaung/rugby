#include "controller.h"

int en1 = 5; // left    PD5
int in1 = 6; // left    PD6
int in2 = 7; // left    PD7
int in3 = 8; // right   PB0
int in4 = 9; // right   PB1
int en2 = 10;// right   PB2

void setup() {
  Serial.begin(9600);
  
//  pinMode(forward_backward_channel,INPUT);
//  pinMode(right_left_channel,INPUT);
//  pinMode(speed_channel,INPUT);

//  pinMode(en1, OUTPUT);
  DDRD = B11100000; // en1(5), in1(6), in2(7) = OUTPUT  forward[2], right[3], speed[4] = INPUT
  DDRB = B00000111; // in3(0), in4(1), en2(2) = OUTPUT
//  pinMode(in1, OUTPUT);
//  pinMode(in2, OUTPUT);
//  pinMode(in3, OUTPUT);
//  pinMode(in4, OUTPUT);
//  pinMode(en2, OUTPUT);
}

void loop() {
  recieve();
  if ( f_b == 0 && r_l == 0 ) {
    // Stand by
    analogWrite(en1,0);
    analogWrite(en2,0);
    PORTD = B11000000; // in1(6) = HIGH; in2(7) = HIGH
    PORTB = B00000011; // in3(0) = HIGH; in4(1) = HIGH
  }

  if ( f_b == 1) {
    if ( r_l == 1) {
      //forward_right
    } else if (r_l == -1) {
      //forward_left
    } else {
      //forward
      analogWrite(en1,speed_);
      analogWrite(en2,speed_);
      PORTD = B01000000; // in1(6) = HIGH; in2(7) = LOW
      PORTB = B00000001; // in3(0) = HIGH; in4(1) = LOW
    }
  }

  if ( f_b == -1) {
    if ( r_l == 1) {
      //backward_right
    } else if (r_l == -1) {
      //backward_left
    } else {
      //backward
      analogWrite(en1, speed_);
      analogWrite(en2, speed_);
      PORTD = B10000000; // in1(6) = LOW; in2(7) = HIGH
      PORTB = B00000010; // in3(0) = LOW; in4(1) = HIGH
    }
  }

  if ( r_l == 1 && f_b == 0) {
    //pivot_right
  } else {
    //pivot_left
  }
}
