// https://playground.arduino.cc/Main/LedControl#Setup
/* We start by including the library */

#include "LedControl.h"
#include "MAX7221_LED_digits.h"

/* 
 * Now we create a new LedControl. 
 * We use pins 12,11 and 10 on the Arduino for the SPI interface
 * Pin 12 is connected to the DATA IN-pin of the first MAX7221
 * Pin 11 is connected to the CLK-pin of the first MAX7221
 * Pin 10 is connected to the LOAD(/CS)-pin of the first MAX7221   
 * There will only be a single MAX7221 attached to the arduino 
 */
LedControl lc=LedControl(12,11,10,1); 

/* we always wait a bit between updates of the display */
unsigned long delaytime=800;
/*int segDP = B10000000;
int segA = B01000000;
int segB = B00100000;
int segC = B00010000;
int segD = B00001000;
int segE = B00000100;
int segF = B00000010;
int segG = B00000001;*/
int segDP = B11111111;
int segA = B11111111;
int segB = B11111111;
int segC = B11111111;
int segD = B11111111;
int segE = B11111111;
int segF = B11111111;
int segG = B11111111;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,4);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() {
  //switch on the led in the 3'rd row 8'th column
  //and remember that indices start at 0! 

  for (int i = 0; i < 10; i++){
    turnOnDigit(&lc, 0, i); // (LedControl* lc, int digitNo, int digit)
    turnOnDigit(&lc, 1, i); // (LedControl* lc, int digitNo, int digit)
    turnOnDigit(&lc, 2, i); // (LedControl* lc, int digitNo, int digit)
    turnOnDigit(&lc, 3, i); // (LedControl* lc, int digitNo, int digit)
    delay(500);
    turnOffLEDs(&lc);
    delay(500);
  }
 }
