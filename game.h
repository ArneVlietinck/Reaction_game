/*
 * File:   game.h
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */

#ifndef GAME_H
#define GAME_H

#include <miosix.h>
using namespace miosix;

#define GAMEOVER 1
typedef Gpio<GPIOA_BASE,0> button;

extern bool game;
extern bool interaction;
extern bool action;
extern int difficulty;

bool shouldBlinkAgain();
int shouldRepeat(int currentLed);

#endif /* GAME_H */
