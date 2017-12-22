/**
 * \file led.cpp
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 22/12/2017
 */

#include <miosix.h>
#include "led.h"
#include "game.h"

using namespace miosix;

extern bool game;
extern int difficulty;

typedef Gpio<GPIOD_BASE,12> greenLed;
typedef Gpio<GPIOD_BASE,13> orangeLed;
typedef Gpio<GPIOD_BASE,14> redLed;
typedef Gpio<GPIOD_BASE,15> blueLed;

void initLeds()
{
    greenLed::mode(Mode::OUTPUT);
    orangeLed::mode(Mode::OUTPUT);
    redLed::mode(Mode::OUTPUT);
    blueLed::mode(Mode::OUTPUT);
}

int calculateSleepTime(int difficulty)
{
  int sleepTime = 600 - 30 * difficulty;
  if (sleepTime<0)
  {
    return 0;
  }
  else{
    return sleepTime;
  }
}

void blinkingGame()
{
    int currentLed = BLUE;
    int sleepTime = calculateSleepTime(difficulty);

    while(currentLed==BLUE && game!=GAMEOVER)
    {
      blueLed::high();
      Thread::sleep(sleepTime);
      blueLed::low();
      Thread::sleep(sleepTime);
      currentLed = gamePlay(currentLed);
    }

    while(currentLed==GREEN && game!=GAMEOVER)
    {
      greenLed::high();
      Thread::sleep(sleepTime);
      greenLed::low();
      Thread::sleep(sleepTime);
      currentLed = gamePlay(currentLed);
    }

    while(currentLed==ORANGE && game!=GAMEOVER)
    {
      orangeLed::high();
      Thread::sleep(sleepTime);
      orangeLed::low();
      Thread::sleep(sleepTime);
      currentLed = gamePlay(currentLed);
    }

    while(currentLed==RED && game!=GAMEOVER)
    {
      redLed::high();
      Thread::sleep(sleepTime);
      redLed::low();
      Thread::sleep(sleepTime);
      currentLed = gamePlay(currentLed);
    }
}

void turnAllOn()
{
    redLed::high();
    blueLed::high();
    greenLed::high();
    orangeLed::high();
}

void turnAllOff()
{
    redLed::low();
    blueLed::low();
    greenLed::low();
    orangeLed::low();
}

void gameOverBlinking()
{
    for(int i=0; i<=2; i++)
    {
        turnAllOn();
        Thread::sleep(500);
        turnAllOff();
        Thread::sleep(500);
    }
}
