#include "MAX7221_LED_test.h"

 void test(LedControl* lc, int on){
    for (int dig = 0; dig < 8; dig++){  
      lc->setRow(0,dig,on); // setRow(addr,row,value)
      delay(200);
      if (dig>0){
        lc->setRow(0,dig-1,B00000000); // setRow(addr,row,value)
      }
      else if (dig==0){
        lc->setRow(0,7,B00000000); // setRow(addr,row,value)
      }
      delay(200);
    } 
 }
