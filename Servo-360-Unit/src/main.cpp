#define ROTATE_RIGHT_HIGH_SPEED 1500
#define ROTATE_RIGHT_LOW_SPEED 4500
#define ROTATE_STOP 5000
#define ROTATE_LEFT_HIGH_SPEED 5500
#define ROTATE_LEFT_LOW_SPEED 7500
#define TIMER_WIDTH 16
#define KEY_PIN_A 37
#define KEY_PIN_C 39
#include "esp32-hal-ledc.h"
#include <M5Unified.h>
#include <M5StickCPlus2.h>

int pwmPin = 32;
int pwd = 0;

void setup() {
  Serial.begin(115200); 

  ledcSetup(1, 50, TIMER_WIDTH);

  pinMode(KEY_PIN_A, INPUT_PULLUP);
  pinMode(KEY_PIN_C, INPUT_PULLUP);

  ledcAttachPin(pwmPin, 1);
}

bool ButtonA() {
  return digitalRead(KEY_PIN_A) == LOW;
}

bool ButtonC() {
  return digitalRead(KEY_PIN_C) == LOW;
}

void Rotate(uint8_t channel, uint32_t value) {
  ledcWrite(channel, value);
}

void DisplayRotation(const char* rotationType, int speed) {
  Rotate(1, speed);
  Serial.printf("%s: %d\n", rotationType, speed);
  delay(1000);
}

void RotateRightHighSpeed() {
  DisplayRotation("ROTATE_RIGHT_HIGH_SPEED", ROTATE_RIGHT_HIGH_SPEED);
}

void RotateRightLowSpeed() {
  DisplayRotation("ROTATE_RIGHT_LOW_SPEED", ROTATE_RIGHT_LOW_SPEED);
}

void StopRotation() {
  DisplayRotation("ROTATE_STOP", ROTATE_STOP);
}

void RotateLeftHighSpeed() {
  DisplayRotation("ROTATE_LEFT_HIGH_SPEED", ROTATE_LEFT_HIGH_SPEED);
}

void RotateLeftLowSpeed() {
  DisplayRotation("ROTATE_LEFT_LOW_SPEED", ROTATE_LEFT_LOW_SPEED);
}

void WaitForButtonA() {
  while (!ButtonA()) {
    delay(100);
  }
}

void loop() {
  RotateRightHighSpeed();
  RotateRightLowSpeed();
  StopRotation();
  RotateLeftHighSpeed();
  RotateLeftLowSpeed();
  StopRotation();

  Serial.println("Press ButtonA to continue...");
  WaitForButtonA();
}