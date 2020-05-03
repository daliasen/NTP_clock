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
unsigned long delaytime = 990;

String hour;
String minute;
String second;

String temperature = "";
bool show_temperature = false;

void setup(){
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0, false);
  lc.clearDisplay(0);

  Ciao.begin();
  Serial.begin(9600);
  Serial.println("serial is initialized");

  int brightness = 4; // set to max
  lc.setIntensity(0, brightness);

  Serial.println("initializing temperature");
  while (temperature.length() == 0){
    temperature = readTemperatureShell();
    delay(delaytime);
  }
  Serial.println("temperature initialization done");
}

void loop(){
  Serial.println("==========================================");
  
  String new_temperature = readTemperatureShell();
  if (new_temperature != NULL){
    temperature = new_temperature;
  }

  CiaoData data_time = Ciao.write("shell", "date +%H:%M:%S");
  if (!data_time.isEmpty()){
    String message_time = data_time.get(2);
    message_time.trim(); // remove leading or trailing whitespace
    
    if (message_time.length() > 0){
      hour = message_time.substring(0,2);
      minute = message_time.substring(3,5);
      second = message_time.substring(6,8);

      Serial.println("second: " + second);

      if(second.toInt()%3 == 0){
        Serial.println("second.toInt()%3 == 0");
        Serial.println(temperature);
         
        turnOffLEDs(&lc);
        int len_temperature = temperature.length();
        for (int i = len_temperature-1; i >= 0; i--){
          Serial.println("i=" + String(i));
          if ((String(temperature[i]) == "+") || (String(temperature[i]) == "-")){
            turnOnSign(&lc, i+1, temperature[i]);
          }
          else{
            turnOnDigit(&lc, i+1, String(temperature[i]).toInt());
          }
        }

        show_temperature = true;
      }
      else{        
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

        show_temperature = false;
      }
    }
  }
  delay(delaytime/2);
  if (!show_temperature){
    turnOnColon(&lc);
  }
  delay(delaytime/2);
  turnOffColon(&lc);
}
