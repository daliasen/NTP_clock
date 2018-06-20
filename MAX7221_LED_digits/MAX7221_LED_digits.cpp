#include "MAX7221_LED_digits.h"

void turnOffLEDs(LedControl* lc){
  lc->setRow(0,0,B00000000); // setRow(addr,row,value)
  lc->setRow(0,1,B00000000); // setRow(addr,row,value)
  lc->setRow(0,2,B00000000); // setRow(addr,row,value)
  lc->setRow(0,3,B00000000); // setRow(addr,row,value)
  lc->setRow(0,4,B00000000); // setRow(addr,row,value)
  lc->setRow(0,5,B00000000); // setRow(addr,row,value)
  lc->setRow(0,6,B00000000); // setRow(addr,row,value)
  lc->setRow(0,7,B00000000); // setRow(addr,row,value)
}
