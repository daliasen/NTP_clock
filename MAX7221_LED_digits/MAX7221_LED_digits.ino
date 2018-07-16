#include "LedControl.h"
#include "MAX7221_LED_digits.h"
#include "Ciao.h"

// Ciao File Connector needs to be enabled

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

// for photo-resistor
int lightPin = 0; // Analog pin
int minLevel = 260;
int maxLevel = 1023; 
int lightLevel;
int brightness;

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
  for (int i = 0; i < 10; i++){
    turnOnDigit(&lc, 0, i); // (LedControl* lc, int digitNo, int digit)
    turnOnDigit(&lc, 1, i); 
    turnOnDigit(&lc, 2, i); 
    turnOnDigit(&lc, 3, i); 
    delay(delaytime);
    turnOffLEDs(&lc);
    delay(delaytime);

    turnOnColon(&lc);

    lightLevel = analogRead(lightPin); // Read the value of the photoresistor
    lightLevel = constrain(lightLevel, minLevel, maxLevel);
    brightness = map(lightLevel, minLevel, 1023, 1, 15); // (value, fromLow, fromHigh, toLow, toHigh)
    brightness = constrain(brightness, 1, 15);
    lc.setIntensity(0,brightness);
  }

  delay(500);

  //Read file from lininoOS
  CiaoData data = Ciao.read("file","/root/date/date.txt");
  if(!data.isEmpty()){

    //extract data from Ciao
    String message = data.get(2);
    // you need include <algorithm> to use general algorithms like std::remove()
    message.remove(10);

    unsigned long epoch = 0;

    for (int i = 0; i < message.length(); i++) {
       char c = message.charAt(i);
       if (c < '0' || c > '9') break;
       epoch *= 10;
       epoch += (c - '0');
    }
    
    //Print message via serial
    Serial.println(message);
    Serial.println("epoch:");
    Serial.println(epoch);

    byte second = epoch%60; epoch /= 60;
    byte minute = epoch%60; epoch /= 60;
    byte hour   = epoch%24; epoch /= 24;

    Serial.println("second:");
    Serial.println(second);

    Serial.println("minute:");
    Serial.println(minute);

    Serial.println("hour:");
    Serial.println(hour);

    //string3 += string2; // append
    //char thisChar = string1[n]
  }
  //Delay the operations because IO is slow
  delay(500);
 }
