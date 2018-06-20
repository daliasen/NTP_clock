// https://playground.arduino.cc/Main/LedControl#Setup
// serial part from https://www.arduino.cc/en/Tutorial/ShftOut12
/* We start by including the library */
#include "LedControl.h"

/*
   Now we create a new LedControl.
   We use pins 12,11 and 10 on the Arduino for the SPI interface
   Pin 12 is connected to the DATA IN-pin of the first MAX7221
   Pin 11 is connected to the CLK-pin of the first MAX7221
   Pin 10 is connected to the LOAD(/CS)-pin of the first MAX7221
   There will only be a single MAX7221 attached to the arduino
*/
LedControl lc = LedControl(12, 11, 10, 1);

int lightPin = 0; // Analog pin
int lightLevel, maxLevel, minLevel;
int brightness;

/* we always wait a bit between updates of the display */
unsigned long delaytime = 100;

void setup() {
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);

  Serial.begin(9600); // Serial Monitor
  maxLevel = analogRead(lightPin);
  minLevel = 300;
}

void loop() {
  // put your main code here, to run repeatedly:
  lightLevel = analogRead(lightPin); // Read the value of the photoresistor
  Serial.println("lightLevel");
  Serial.println(lightLevel);
  constrain(lightLevel, 500, 1023);
  brightness = map(lightLevel, 500, 1023, 1, 15);
  lc.setIntensity(0, brightness);
  Serial.println("brightness");
  Serial.println(brightness);

  // 0
  lc.setRow(0, 0, B11111000);
  lc.setRow(0, 1, B10001000);
  lc.setRow(0, 2, B11111000);
  delay(1000);

  // 1
  /*lc.setRow(0, 0, B11111000);
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00000000);
  delay(1000);

  /*

  // 2
  lc.setRow(0, 0, B11101000);
  lc.setRow(0, 1, B10101000);
  lc.setRow(0, 2, B10111000);
  delay(1000);

  // 3
  lc.setRow(0, 0, B11111000);
  lc.setRow(0, 1, B10101000);
  lc.setRow(0, 2, B10101000);
  delay(1000);

  // 4
  lc.setRow(0, 0, B11111000);
  lc.setRow(0, 1, B00100000);
  lc.setRow(0, 2, B11100000);
  delay(1000);

  // 5
  lc.setRow(0, 0, B10111000);
  lc.setRow(0, 1, B10101000);
  lc.setRow(0, 2, B11101000);
  delay(1000);

  // 6
  lc.setRow(0, 0, B10111000);
  lc.setRow(0, 1, B10101000);
  lc.setRow(0, 2, B11111000);
  delay(1000);

  // 7
  lc.setRow(0, 0, B11111000);
  lc.setRow(0, 1, B10000000);
  lc.setRow(0, 2, B10000000);
  delay(1000);

  // 8
  lc.setRow(0, 0, B11111000);
  lc.setRow(0, 1, B10101000);
  lc.setRow(0, 2, B11111000);
  delay(1000);

  // 9
  lc.setRow(0, 0, B11111000);
  lc.setRow(0, 1, B10101000);
  lc.setRow(0, 2, B11101000);
  delay(1000);

  */
}


