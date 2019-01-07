#include "LedControl.h"
#include "MAX7221_LED_digits.h"
#include "Ciao.h"

// Ciao File Connector needs to be enabled
// print message via serial (can't print when the script is using the bridge)

/* 
 * Now we create a new LedControl. 
 * We use pins 12,11 and 10 on the Arduino for the SPI interface
 * Pin 12 is connected to the DATA IN-pin of the first MAX7221
 * Pin 11 is connected to the CLK-pin of the first MAX7221
 * Pin 10 is connected to the LOAD(/CS)-pin of the first MAX7221   
 * There will only be a single MAX7221 attached to the arduino 
 */
LedControl lc=LedControl(12,11,10,1); 

/* wait a bit between updates of the display */
unsigned long delaytime=900;

// for photo-resistor
int lightPin = 0; // Analog pin
int minLevel = 260;
int maxLevel = 1023; 
int lightLevel;
int brightness;

// message
unsigned long epoch = 0;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  //lc.setIntensity(0,4);
  /* and clear the display */
  lc.clearDisplay(0);

  Ciao.begin();
  Serial.begin(9600);
}

void loop() {
  /*lightLevel = analogRead(lightPin); // Read the value of the photoresistor
  lightLevel = constrain(lightLevel, minLevel, maxLevel);
  brightness = map(lightLevel, minLevel, 1023, 1, 15); // (value, fromLow, fromHigh, toLow, toHigh)
  brightness = constrain(brightness, 1, 15);*/
  brightness = 4; // set to max
  lc.setIntensity(0,brightness);

  delay(delaytime);

  turnOnColon(&lc);

  //Read file from lininoOS
  CiaoData data = Ciao.read("file","/root/date/date.txt");
  if(!data.isEmpty()){
  
    //get data from Ciao
    String message = data.get(2);
    message.remove(10);
  
    if (message.length() > 0){
      epoch = 0;
  
      for (int i = 0; i < message.length(); i++) {
         char c = message.charAt(i);
         if (c < '0' || c > '9') break;
         epoch *= 10;
         epoch += (c - '0');
      }
  
      byte second = epoch%60; epoch /= 60;
      byte minute = epoch%60; epoch /= 60;
      byte hour   = epoch%24; epoch /= 24;
  
      byte digit_3 = minute % 10;
      byte digit_2 = (minute - digit_3) / 10;
      byte digit_1 = hour % 10;
      byte digit_0 = (hour - digit_1) / 10;
  
      // display time
      turnOffLEDs(&lc);
      turnOnDigit(&lc, 0, digit_0); // (LedControl* lc, int digitNo, int digit)
      turnOnDigit(&lc, 1, digit_1); 
      turnOnDigit(&lc, 2, digit_2); 
      turnOnDigit(&lc, 3, digit_3); 
    }
    else{
      turnOffLEDs(&lc);
      turnOnErr(&lc);
      turnOnDigit(&lc, 3, 2);
    }
  }
  /*else{
    turnOffLEDs(&lc);
    turnOnErr(&lc);
    turnOnDigit(&lc, 3, 1);
  }*/
 }
