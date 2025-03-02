#ifndef PINS_H_
#define PINS_H_
#include <stdint.h>


void initLEDPin();

void initButtonPin(uint8_t pinN);

void setLEDpinA(uint8_t pinN, uint8_t level);
void setLEDpinB(uint8_t pinN, uint8_t level);
void flashLEDS();






#endif