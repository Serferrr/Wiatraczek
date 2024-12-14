

#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <Wire.h>

Adafruit_BMP280 bmp;

int tempMax = 40;
int tempMin = 20;
int speedMax = 255;
int speedMin = 0;

float howFast(float temperature)
{
  float fanSpeed;
  fanSpeed = speedMin + (temperature - tempMin) * (speedMax - speedMin) / (tempMax - tempMin);
  return fanSpeed;
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(D7, OUTPUT);
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1)
      ;
  }
  Serial.println("BMP280 found!");
  analogWriteFrequency(25000);
}

void loop() {
  // Serial.print("Temperature = ");
  // Serial.print(bmp.readTemperature());
  // Serial.print(" *C");

  // Serial.print("Pressure = ");
  // Serial.print(bmp.readPressure());
  // Serial.print(" Pa\n");
  // delay(2000);

  // Set PWM frequency to 25kHz and duty cycle to 10% (slow speed)
 // analogWrite(D7, 0); // 10% of 255 is approximately 26
  //delay(5000);

  // Set PWM duty cycle to 90% (fast speed)
  //analogWrite(D7, 255); // 90% of 255 is approximately 230
  //delay(1000);

  analogWrite(D7, uint32_t(howFast(bmp.readTemperature())));
  Serial.println(bmp.readTemperature());
  delay(1000);
  
}

