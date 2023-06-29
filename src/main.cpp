// CNC SHIELD ARDUINO UNO
// Voor de Arduino Uno + CNC shield V3
// http://domoticx.com/arduino-shield-cnc-shield/
// #define MOTOR_X_ENABLE_PIN 8
// #define MOTOR_X_STEP_PIN 2
// #define MOTOR_X_DIR_PIN 5
 
// #define MOTOR_Y_ENABLE_PIN 8
// #define MOTOR_Y_STEP_PIN 3
// #define MOTOR_Y_DIR_PIN 6
 
// #define MOTOR_Z_ENABLE_PIN 8
// #define MOTOR_Z_STEP_PIN 4
// #define MOTOR_Z_DIR_PIN 7

#include <Arduino.h>
#include <AccelStepper.h>

#define MOTOR_Y_ENABLE_PIN 8
#define MOTOR_Y_STEP_PIN 3
#define MOTOR_Y_DIR_PIN 6

#define ANALOG_IN A0


// Define some steppers and the pins the will use
AccelStepper stepper(AccelStepper::DRIVER, MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);

void setup() {
  Serial.begin(115200); 

  pinMode(MOTOR_Y_ENABLE_PIN, OUTPUT);
  stepper.setEnablePin(MOTOR_Y_ENABLE_PIN);
  stepper.setPinsInverted(false, false, true);
  stepper.setAcceleration(1000);  
  stepper.setMaxSpeed(4000);
  //stepper.setSpeed(100);
  stepper.enableOutputs();

}

void loop() {

  // stepper.move(30);
  // stepper.run();

  // int analog_in = analogRead(ANALOG_IN);
  // int pot = map(analog_in,0,1023,0,400);
  // Serial.println(analog_in);
  // // stepper.setSpeed(100);
  stepper.moveTo(100000);
  stepper.run();
  // stepper.moveTo(0);
  // stepper.runToPosition();  
}
