#include "LedControl.h"
#include "MAX7221_LED_digits.h"
#include "Ciao.h"
#include "temperature.h"

// Ciao File Connector needs to be enabled
// print message via serial 

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

String hour;
String minute;
String second;

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
  SERIAL_PORT_IN_USE.setTimeout(10000); // set stream timeout to 10s
  Serial.begin(9600);
  Serial.println("serial is initialized");

  int brightness = 4; // set to max
  lc.setIntensity(0,brightness);
  
  delay(40000);
}

void loop() {
  Serial.println("==========================================");

  delay(delaytime);

  turnOnColon(&lc);

  // run a command in lininoOS
  CiaoData data_time = Ciao.write("shell", "date +%H:%M:%S");

  /*Serial.println("data_time.get(0): " + data_time.get(0));
  Serial.println("data_time.get(1): " + data_time.get(1));
  Serial.println("data_time.get(2): " + data_time.get(2));*/

  if (!data_time.isEmpty()){
    String message_time = data_time.get(2);
    message_time.trim(); // remove leading or trailing whitespace
    //Serial.println(message_time);

    if (message_time.length() > 0){
      hour = message_time.substring(0,2);
      minute = message_time.substring(3,5);
      second = message_time.substring(6,8);
      
      /*Serial.println("hour: " + hour);
      Serial.println("minute: " + minute);*/
      Serial.println("second: " + second);

      int digit_3 = minute.toInt() % 10;
      int digit_2 = (minute.toInt() - digit_3) / 10;
      int digit_1 = hour.toInt() % 10;
      int digit_0 = (hour.toInt() - digit_1) / 10;

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
  else{
    turnOffLEDs(&lc);
    turnOnErr(&lc);
    turnOnDigit(&lc, 3, 1);
  }

  // TODO: get a tuple with sign, temperature_digit_2 & 3

  delay(500);    
  if(second.toInt()%5 == 0){
    displayTemperature(&lc, second); // TODO: split into read and display?
    delay(500);
  }
 }
