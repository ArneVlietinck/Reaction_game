/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game.h
 * Author: mastro
 *
 * Created on 12 décembre 2017, 12:32
 */

#ifndef GAME_H
#define GAME_H

#include<miosix.h>
using namespace miosix;

#define GAMEOVER 1
typedef Gpio<GPIOA_BASE,0> button;

//If game=GAMEOVER, the current game is finished
extern bool game;
//When risk is true, the player must do something (eg:press a button) to avoid a game over
extern bool risk;
//Tell if the player did an action
extern bool action;
//Increased difficulty means less time between on and off
extern int difficulty;

bool shouldBlinkAgain();

int shouldRepeat(int currentLed);


#endif /* GAME_H */

