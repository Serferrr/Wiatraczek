#include <Arduino.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN PC13
#endif

void setup() {
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(USER_BTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(USER_BTN) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}