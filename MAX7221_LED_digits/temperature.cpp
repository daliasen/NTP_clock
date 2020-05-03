#include "temperature.h"

String readTemperatureShell(){
  char sign;
  int temperature_digit_2;
  int temperature_digit_3;
  String temperature;
 
  CiaoData data_temperature = Ciao.write("shell", "cat /root/temperature.txt");
  
  if(!data_temperature.isEmpty()){
    String message_temperature = data_temperature.get(2);
    message_temperature.trim(); // remove leading or trailing whitespace

    int len_temperature = message_temperature.length();
    if(len_temperature == 3){
      temperature = message_temperature;
    }
    else if(len_temperature == 2){
      if((String(message_temperature[0]) == "+") || (String(message_temperature[0]) == "-")){
        temperature = message_temperature;
      }
      else{
        temperature = "+" + message_temperature;
      }   
    } 
    else if(len_temperature == 1){
      temperature = "+" + message_temperature;
    }

    Serial.println("temperature: " + temperature);
  }
  else{
    Serial.println("temperature: empty");
    temperature = "";
  }
  return temperature;
}
