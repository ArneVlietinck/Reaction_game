/*
 * File: button.h
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <miosix.h>
using namespace miosix;

typedef Gpio<GPIOA_BASE,0> button;

void initButton();
void checkButton();


#endif /* BUTTON_H */
