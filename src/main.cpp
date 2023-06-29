// CNC SHIELD ARDUINO UNO
// const int enPin=8;
// const int stepXPin = 2; //X.STEP
// const int dirXPin = 5; // X.DIR
// const int stepYPin = 3; //Y.STEP
// const int dirYPin = 6; // Y.DIR
// const int stepZPin = 4; //Z.STEP
// const int dirZPin = 7; // Z.DIR

#include <Arduino.h>
#include <AccelStepper.h>

#define STEPPER1_DIR_PIN 6
#define STEPPER1_STEP_PIN 3
#define ANALOG_IN A0


// Define some steppers and the pins the will use
AccelStepper stepper(AccelStepper::DRIVER, STEPPER1_STEP_PIN, STEPPER1_DIR_PIN);

void setup() {
  Serial.begin(115200); 
  stepper.setMaxSpeed(1000.0);
  stepper.setAcceleration(100.0);
  // stepper.setSpeed(100);	
}

void loop() {
  // int analog_in = analogRead(ANALOG_IN);
  // int pot = map(analog_in,0,1023,0,400);
  stepper.moveTo(100000);
  // Serial.println(analog_in);
  // // stepper.setSpeed(100);
  // stepper.run();
  stepper.runToPosition();
  stepper.moveTo(0);
  stepper.runToPosition();
    
}
