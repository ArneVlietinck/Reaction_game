/*
 * File: button.h
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <miosix.h>
using namespace miosix;

typedef Gpio<GPIOA_BASE,0> button;

extern bool action;

void initButton();
void checkButton();
void checkAction();


#endif /* BUTTON_H */
