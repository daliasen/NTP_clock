#ifndef _MAX7221_LED_digits_
  #define _MAX7221_LED_digits_

#include "LedControl.h"

void turnOffColon(LedControl* lc);
void turnOnColon(LedControl* lc);
void turnOffLEDs(LedControl* lc);
void turnOnDigit(LedControl* lc, int digitNo, int digit);

#endif // _MAX7221_LED_digits_
