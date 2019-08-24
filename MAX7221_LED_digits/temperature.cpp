#include "temperature.h"

void displayTemperature(LedControl* lc, String second){
  char sign;
  int temperature_digit_2;
  int temperature_digit_3;
  // run a command in lininoOS
  CiaoData data_temperature = Ciao.write("shell", "cat temperature.txt");
  String message_temperature = "undefined";
  while(data_temperature.isEmpty()){
    data_temperature = Ciao.write("shell", "cat temperature.txt");
    Serial.println("data_temperature.get(0): " + data_temperature.get(0));
    Serial.println("data_temperature.get(1): " + data_temperature.get(1));
    Serial.println("data_temperature.get(2): " + data_temperature.get(2));
      if(!data_temperature.isEmpty()){
        message_temperature = data_temperature.get(2);
        message_temperature.trim(); // remove leading or trailing whitespace
        Serial.println("message_temperature: " + message_temperature);

        int len_temperature = message_temperature.length();
        if(len_temperature == 3){
          sign = message_temperature[0];
          temperature_digit_2 = String(message_temperature[1]).toInt();
          temperature_digit_3 = String(message_temperature[2]).toInt();
        }
        else if(len_temperature == 2){
          if((String(message_temperature[0]) == "+") || (String(message_temperature[0]) == "-")){
            sign = message_temperature[0];
            temperature_digit_2 = NULL;
            temperature_digit_3 = String(message_temperature[1]).toInt();
            Serial.println("the first character is a sign");
          }
          else{
            sign = '+';
            temperature_digit_2 = String(message_temperature[0]).toInt();
            temperature_digit_3 = String(message_temperature[1]).toInt();
          }   
        } 
        else if(len_temperature == 1){
          sign = '+';        
          temperature_digit_2 = NULL;   
          temperature_digit_3 = message_temperature.toInt();
        }
        else if(len_temperature == 0){
          delay(200);
          turnOffLEDs(lc);
          turnOnErr(lc);
          turnOnDigit(lc, 3, 5);
        }
        else{
          Serial.println("temperature message is too long");
        }

        // display temperature
        if(second.toInt()%5 == 0){
          turnOffLEDs(lc);
          if(temperature_digit_2 != NULL){
            turnOnSign(lc, 1, sign);
            turnOnDigit(lc, 2, temperature_digit_2); 
          }
          else{
            turnOnSign(lc, 2, sign);
          }
          turnOnDigit(lc, 3, temperature_digit_3); 
          Serial.println("sign: ");
          Serial.println(sign);
        }
      }
      else{
        delay(200);
        turnOffLEDs(lc);
        turnOnErr(lc);
        turnOnDigit(lc, 3, 4);
      }
      //Serial.println("temperature: " + temperature);
  }
}

 /*CiaoData data_location_id = Ciao.write("shell", "python location_id.py");
  String location_id = "undefined";
  while(data_location_id.isEmpty()){
    data_location_id = Ciao.write("shell", "python location_id.py");
    Serial.println("data_location_id.get(0): " + data_location_id.get(0));
    Serial.println("data_location_id.get(1): " + data_location_id.get(1));
    Serial.println("data_location_id.get(2): " + data_location_id.get(2));
    if(!data_location_id.isEmpty()){
      location_id = data_location_id.get(2);
      location_id.trim(); // remove leading or trailing whitespace
    }
    else{
      delay(200);
      turnOffLEDs(&lc);
      turnOnErr(&lc);
      turnOnDigit(&lc, 3, 3);
    }
    //Serial.println("location ID: " + location_id);
  }*/
