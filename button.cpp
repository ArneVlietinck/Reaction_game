/*
 * File: button.cpp
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */
#include "button.h"

/*
 * Initialisation of the button in input mode.
 */
void initButton()
{
    button::mode(Mode::INPUT);
}

/*
 * Check if the button is pushed.
 */
void checkButton()
{
  while(button::value()==0) Thread::sleep(10);
}
