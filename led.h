/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   led.h
 * Author: mastro
 *
 * Created on 8 décembre 2017, 22:45
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

