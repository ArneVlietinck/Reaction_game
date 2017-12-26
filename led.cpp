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
extern int level;

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

bool clockOrCounterClockWise()
{
    int randomval = rand() % 2;
    if(randomval == 0 )
    {
      return true;
    }
    else
    {
      return false;
    }
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

void blinkLed(int currentLed, int sleepTime)
{
  if(currentLed==BLUE)
  {
    blueLed::high();
    Thread::sleep(sleepTime);
    blueLed::low();
    Thread::sleep(sleepTime);
  }
  else if(currentLed==GREEN)
  {
    greenLed::high();
    Thread::sleep(sleepTime);
    greenLed::low();
    Thread::sleep(sleepTime);
  }
  else if(currentLed==ORANGE)
  {
    orangeLed::high();
    Thread::sleep(sleepTime);
    orangeLed::low();
    Thread::sleep(sleepTime);
  }
  else if(currentLed==RED)
  {
    redLed::high();
    Thread::sleep(sleepTime);
    redLed::low();
    Thread::sleep(sleepTime);
  }
}

void blinkingClockwise(int currentLed, int sleepTime)
{
  while(currentLed==BLUE && game!=GAMEOVER)
  {
    blinkLed(currentLed, sleepTime);
    currentLed = gamePlay(currentLed, true);
  }

  while(currentLed==GREEN && game!=GAMEOVER)
  {
    blinkLed(currentLed, sleepTime);
    currentLed = gamePlay(currentLed, true);
  }

  while(currentLed==ORANGE && game!=GAMEOVER)
  {
    blinkLed(currentLed, sleepTime);
    currentLed = gamePlay(currentLed, true);
  }

  while(currentLed==RED && game!=GAMEOVER)
  {
    blinkLed(currentLed, sleepTime);
    currentLed = gamePlay(currentLed, true);
  }
}

void blinkingCounterClockwise(int currentLed, int sleepTime)
{
  while(currentLed==BLUE && game!=GAMEOVER)
  {
    blinkLed(currentLed, sleepTime);
    currentLed = gamePlay(currentLed, false);
  }

  while(currentLed==RED && game!=GAMEOVER)
  {
    blinkLed(currentLed, sleepTime);
    currentLed = gamePlay(currentLed, false);
  }

  while(currentLed==ORANGE && game!=GAMEOVER)
  {
    blinkLed(currentLed, sleepTime);
    currentLed = gamePlay(currentLed, false);
  }

  while(currentLed==GREEN && game!=GAMEOVER)
  {
    blinkLed(currentLed, sleepTime);
    currentLed = gamePlay(currentLed, false);
  }
}

void blinkingsequence(int currentLed, int sleepTime, int level)
{
  if(clockOrCounterClockWise())
  {
    blinkingClockwise(currentLed, sleepTime);
  }
  else
  {
    blinkingCounterClockwise(currentLed, sleepTime);
  }
}

void blinkingGame()
{
    int currentLed = BLUE;
    int sleepTime = calculateSleepTime(difficulty);
    level++;

    blinkingsequence(currentLed, sleepTime, level);
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

void onOffBlinking(int times)
{
    for(int i=0; i<times; i++)
    {
        turnAllOn();
        Thread::sleep(500);
        turnAllOff();
        Thread::sleep(500);
    }
}
