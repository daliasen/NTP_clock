#include "MAX7221_LED_digits.h"

void turnOffColon(LedControl* lc) {
  lc->setLed(0, 5, 3, false);
  lc->setLed(0, 7, 3, false);
}

void turnOnColon(LedControl* lc) {
  lc->setLed(0, 5, 3, true);
  lc->setLed(0, 7, 3, true);
}

void turnOffLEDs(LedControl* lc) {
  lc->setRow(0, 0, B00000000); // setRow(addr,row,value)
  lc->setRow(0, 1, B00000000); // setRow(addr,row,value)
  lc->setRow(0, 2, B00000000); // setRow(addr,row,value)
  lc->setRow(0, 3, B00000000); // setRow(addr,row,value)
  lc->setRow(0, 4, B00000000); // setRow(addr,row,value)
  lc->setRow(0, 5, B00000000); // setRow(addr,row,value)
  lc->setRow(0, 6, B00000000); // setRow(addr,row,value)
  lc->setRow(0, 7, B00000000); // setRow(addr,row,value)
}

void turnOnSign(LedControl* lc, int digitNo, char sign){
  int column = digitNo * 2;
  if(sign == '+'){
    //lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
    //lc->setLed(0, 1, column, true);
    lc->setLed(0, 2, column, true);
    //lc->setLed(0, 3, column, true);
    //lc->setLed(0, 4, column, true);
    lc->setLed(0, 5, column, true);
    lc->setLed(0, 6, column, true);
    lc->setLed(0, 7, column, true);
    //lc->setLed(0, 0, column + 1, true);
    //lc->setLed(0, 1, column + 1, true);
    lc->setLed(0, 2, column + 1, true);
    //lc->setLed(0, 3, column + 1, true);
    //lc->setLed(0, 4, column + 1, true);
  }
  else if(sign == '-'){
    //lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
    //lc->setLed(0, 1, column, true);
    lc->setLed(0, 2, column, true);
    //lc->setLed(0, 3, column, true);
    //lc->setLed(0, 4, column, true);
    //lc->setLed(0, 5, column, true);
    lc->setLed(0, 6, column, true);
    //lc->setLed(0, 7, column, true);
    //lc->setLed(0, 0, column + 1, true);
    //lc->setLed(0, 1, column + 1, true);
    lc->setLed(0, 2, column + 1, true);
    //lc->setLed(0, 3, column + 1, true);
    //lc->setLed(0, 4, column + 1, true);
  }
}

void turnOnDigit(LedControl* lc, int digitNo, int digit) {
  int column = digitNo * 2;
  switch (digit) {
    case 0:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      //lc->setLed(0, 6, column, false);
      lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 1:
      /*lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      lc->setLed(0, 7, column, true);*/
      lc->setLed(0, 0, column + 1, true);
      lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 2:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      //lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      lc->setLed(0, 6, column, true);
      lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      //lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 3:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      //lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      //lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      lc->setLed(0, 6, column, true);
      lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 4:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      /*lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);*/
      lc->setLed(0, 6, column, true);
      //lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 5:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      //lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      lc->setLed(0, 6, column, true);
      lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      //lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 6:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      lc->setLed(0, 6, column, true);
      lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      //lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 7:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      /*lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      lc->setLed(0, 6, column, true);*/
      lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 8:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      lc->setLed(0, 6, column, true);
      lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
    case 9:
      lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
      lc->setLed(0, 1, column, true);
      lc->setLed(0, 2, column, true);
      //lc->setLed(0, 3, column, true);
      lc->setLed(0, 4, column, true);
      lc->setLed(0, 5, column, true);
      lc->setLed(0, 6, column, true);
      lc->setLed(0, 7, column, true);
      lc->setLed(0, 0, column + 1, true);
      lc->setLed(0, 1, column + 1, true);
      lc->setLed(0, 2, column + 1, true);
      lc->setLed(0, 3, column + 1, true);
      lc->setLed(0, 4, column + 1, true);
      break;
  }
}

void turnOnErr(LedControl* lc){
  int column = 0;
  lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
  lc->setLed(0, 1, column, true);
  lc->setLed(0, 2, column, true);
  lc->setLed(0, 3, column, true);
  lc->setLed(0, 4, column, true);
  lc->setLed(0, 5, column, true);
  lc->setLed(0, 6, column, true);
  lc->setLed(0, 7, column, true);
  lc->setLed(0, 0, column + 1, true);
  //lc->setLed(0, 1, column + 1, true);
  lc->setLed(0, 2, column + 1, true);
  //lc->setLed(0, 3, column + 1, true);
  lc->setLed(0, 4, column + 1, true);

  column = 2;
  //lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
  //lc->setLed(0, 1, column, true);
  lc->setLed(0, 2, column, true);
  lc->setLed(0, 3, column, true);
  lc->setLed(0, 4, column, true);
  //lc->setLed(0, 5, column, true);
  lc->setLed(0, 6, column, true);
  /*lc->setLed(0, 7, column, true);
  lc->setLed(0, 0, column + 1, true);
  lc->setLed(0, 1, column + 1, true);
  lc->setLed(0, 2, column + 1, true);
  lc->setLed(0, 3, column + 1, true);
  lc->setLed(0, 4, column + 1, true);*/

  column = 4;
  //lc->setLed(0, 0, column, true); // address of the display, row (0..7), column (0..7)
  //lc->setLed(0, 1, column, true);
  lc->setLed(0, 2, column, true);
  lc->setLed(0, 3, column, true);
  lc->setLed(0, 4, column, true);
  //lc->setLed(0, 5, column, true);
  lc->setLed(0, 6, column, true);
}
