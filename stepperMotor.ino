#include <Stepper.h>
#include <Servo.h>

#define STEPS 32

#define IN1  11
#define IN2  10
#define IN3   9
#define IN4   8
 
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);


#define joystick_x A0
#define joystick_y A1

Servo servo;

int servoPosition = 0;

void setup() {
  servo.attach(3);
}
 
void loop() {
  int valx = analogRead(joystick_x);
  int valy = analogRead(joystick_y);

  if((valx > 500) && (valx < 523)) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
 
  else {
    if (valx >= 523) {
      int speed_ = map(valx, 523, 1023, 1, 400);
      stepper.setSpeed(speed_);
 
      stepper.step(1);
    }
 
    if (valx <= 500) {
      int speed_ = map(valx, 500, 0, 1, 400);
      stepper.setSpeed(speed_);
 
      stepper.step(-1);
    }
  }
  if (valy >= 523 && servoPosition <= 180) {
    servoPosition++;
    servo.write(servoPosition);
  } else if (valy <= 500 && servoPosition >=0) {
    servoPosition--;
    servo.write(servoPosition);
  }
}
