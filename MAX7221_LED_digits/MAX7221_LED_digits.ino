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
  lc.setLed(0,2,7,true);   
  //Led at row 0 second from left too
  lc.setLed(0,0,1,true);   
  delay(500);
  //switch the first Led off (second one stays on)
  lc.setLed(0,2,7,false);
  delay(500);
  // 0
  /*lc.setRow(0,0,B11111111); // top row, outside
  lc.setRow(0,1,B11111111); // 2nd row from top
  lc.setRow(0,2,B11111111); // 3rd row from top, outside
  lc.setRow(0,3,B11111111); // 4th row from top
  lc.setRow(0,4,B11111111); // bottom row, outside
  lc.setRow(0,5,B11111111); // bottom row, middle (including colon)
  lc.setRow(0,6,B00000000); // middle row, middle
  lc.setRow(0,7,B11111111); // top, middle (including colon)

  delay(delaytime);
  turnOffLEDs(&lc);
  delay(delaytime);

  // 1
  lc.setRow(0,0,B01010101); // top row, outside
  lc.setRow(0,1,B01010101); // 2nd row from top
  lc.setRow(0,2,B01010101); // 3rd row from top, outside
  lc.setRow(0,3,B01010101); // 4th row from top
  lc.setRow(0,4,B01010101); // bottom row, outside
  lc.setRow(0,5,B00010000); // bottom row, middle (including colon)
  lc.setRow(0,6,B00000000); // middle row, middle
  lc.setRow(0,7,B00010000); // top, middle (including colon)

  delay(delaytime);
  turnOffLEDs(&lc);
  delay(delaytime);

  // 2
  lc.setRow(0,0,B11111111); // top row, outside
  lc.setRow(0,1,B01010101); // 2nd row from top
  lc.setRow(0,2,B11111111); // 3rd row from top, outside
  lc.setRow(0,3,B10101010); // 4th row from top
  lc.setRow(0,4,B11111111); // bottom row, outside
  lc.setRow(0,5,B11111111); // bottom row, middle (including colon)
  lc.setRow(0,6,B10101010); // middle row, middle
  lc.setRow(0,7,B11111111); // top, middle (including colon)

  delay(delaytime);
  turnOffLEDs(&lc);
  delay(delaytime);*/
 }
