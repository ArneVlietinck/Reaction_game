/*
 * File: led.h
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */

#ifndef LED_H
#define LED_H

#define BLUE 1
#define GREEN 2
#define ORANGE 3
#define RED 4

#include <miosix.h>
using namespace miosix;

typedef Gpio<GPIOD_BASE,12> greenLed;
typedef Gpio<GPIOD_BASE,13> orangeLed;
typedef Gpio<GPIOD_BASE,14> redLed;
typedef Gpio<GPIOD_BASE,15> blueLed;

void initLeds();
void blinkingAll();
void turnAllOn();
void turnAllOff();
void gameOver();


#endif /* LED_H */
