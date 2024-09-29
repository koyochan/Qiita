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

void setup() {
  Serial.begin(115200); 

  // PWM設定
  ledcSetup(1, 50, TIMER_WIDTH);
  ledcAttachPin(pwmPin, 1);

  // ボタンの入力設定
  pinMode(KEY_PIN_A, INPUT_PULLUP);
  pinMode(KEY_PIN_C, INPUT_PULLUP);
}

void loop() {
  // 右に高速回転
  ledcWrite(1, ROTATE_RIGHT_HIGH_SPEED);
  Serial.printf("ROTATE_RIGHT_HIGH_SPEED: %d\n", ROTATE_RIGHT_HIGH_SPEED);
  delay(1000);

  // 右に低速回転
  ledcWrite(1, ROTATE_RIGHT_LOW_SPEED);
  Serial.printf("ROTATE_RIGHT_LOW_SPEED: %d\n", ROTATE_RIGHT_LOW_SPEED);
  delay(1000);

  // 停止
  ledcWrite(1, ROTATE_STOP);
  Serial.printf("ROTATE_STOP: %d\n", ROTATE_STOP);
  delay(1000);

  // 左に高速回転
  ledcWrite(1, ROTATE_LEFT_HIGH_SPEED);
  Serial.printf("ROTATE_LEFT_HIGH_SPEED: %d\n", ROTATE_LEFT_HIGH_SPEED);
  delay(1000);

  // 左に低速回転
  ledcWrite(1, ROTATE_LEFT_LOW_SPEED);
  Serial.printf("ROTATE_LEFT_LOW_SPEED: %d\n", ROTATE_LEFT_LOW_SPEED);
  delay(1000);

  // 停止
  ledcWrite(1, ROTATE_STOP);
  Serial.printf("ROTATE_STOP: %d\n", ROTATE_STOP);
  delay(1000);

  // ボタンAが押されるまで待つ
  Serial.println("Press ButtonA to continue...");
  while (digitalRead(KEY_PIN_A) != LOW) {
    delay(100);
  }
}
