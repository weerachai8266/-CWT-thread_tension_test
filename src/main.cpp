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
#include "HX711.h"
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

#define MOTOR_Y_ENABLE_PIN 8
#define MOTOR_Y_STEP_PIN 3
#define MOTOR_Y_DIR_PIN 6

#define pb1 11
#define pb2 10
#define pb3 9

// ตัวแปรสำหรับเก็บสถานะปุ่ม
int buttonState = 0;
int lastButtonState = 0;

// ตัวแปรสำหรับเก็บสถานะการทำงานของมอเตอร์
boolean motorRunning = false;

// #define DOUT  10
// #define CLK   9

// float calibration_factor = 20069.00;
// #define zero_factor -94686 

// float offset_kg = 0;
// float offset_nm = 0;
// float get_units_kg();
// float get_units_nm();

// Define some steppers and the pins the will use
AccelStepper stepper(AccelStepper::DRIVER, MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);
// HX711 scale;

// float get_units_kg()
// {
//   return(scale.get_units()*0.453592);
// }
// float get_units_nm()
// {
//   return(scale.get_units()*4.4482179868);
// }

void setup() {
  Serial.begin(115200); 

  // scale.begin(DOUT, CLK);
  // scale.set_scale(calibration_factor); 
  // scale.set_offset(zero_factor);

  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);

  pinMode(MOTOR_Y_ENABLE_PIN, OUTPUT);
  stepper.setEnablePin(MOTOR_Y_ENABLE_PIN);
  stepper.setPinsInverted(false, false, true);
  //stepper.setSpeed(100);
  stepper.setCurrentPosition(0);
  stepper.enableOutputs();

}

void loop() {
  // int speedMotor = analogRead(A0);
  // int accMotor = analogRead(A1);
  // int steepMotor = analogRead(A2);
  // Serial.print("speedMotor "); Serial.println(speedMotor);
  // Serial.print("accMotor "); Serial.println(accMotor);
  // Serial.print("steepMotor "); Serial.println(steepMotor);
  // delay(1000);
  stepper.setAcceleration(1000);  // min= max=
  stepper.setMaxSpeed(2000); // min=500 max=5000

  // อ่านสถานะปุ่ม
  buttonState = digitalRead(pb1);
  // ถ้าปุ่มถูกกด
  if (buttonState != lastButtonState && buttonState == LOW) {
    // หาก Stepper Motor ไม่ได้ทำงาน
    if (!stepper.isRunning()) {
      // เลื่อน Stepper Motor ไปทางที่ต้องการ (500 steps)
      stepper.moveTo(125*100); //500 = 4CM, 125 = 1CM
    }
  }

  // ทำงานของ Stepper Motor
  stepper.run();

  // หาก Stepper Motor ได้ทำงานเสร็จสิ้น
  if (stepper.distanceToGo() == 0) {
    // หยุด Stepper Motor
    stepper.stop();
    stepper.setCurrentPosition(0);
  }

  lastButtonState = buttonState;
}
