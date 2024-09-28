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
  auto cfg = M5.config();
  cfg.serial_baudrate = 115200;
  M5.begin(cfg);

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

void kaiten(uint8_t channel, uint32_t value) {
  ledcWrite(channel, value);
}

void display(const char *str) {
  M5.Display.fillScreen(TFT_BLACK);
  M5.Display.setCursor(20, 80);
  M5.Display.setTextSize(2);
  M5.Display.printf("%s", str);
}

void loop() {
  
  
  if (ButtonA()) {
    kaiten(1, ROTATE_RIGHT_HIGH_SPEED);
    display("Rotation: True"); 
  }
  else if (ButtonC()) {
    kaiten(1, ROTATE_STOP);
    display("Rotation: false"); 
  }

  M5.update();
  delay(100);
}
