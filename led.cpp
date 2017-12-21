/*
 * File: led.cpp
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */
#include "led.h"
#include "game.h"

/*
 * Initialisation of the Green, Orange, Red and Blue led in output mode.
 */
void initLeds()
{
    greenLed::mode(Mode::OUTPUT);
    orangeLed::mode(Mode::OUTPUT);
    redLed::mode(Mode::OUTPUT);
    blueLed::mode(Mode::OUTPUT);
}

/*
 *
 */
void blinkingAll()
{
    //Gameover when game==1
    game=0;

    int currentLed=BLUE;
    //The further the game, the shorter the time between an on/off
    int sleepTime= 600-30*difficulty;
    if (sleepTime<0)
        sleepTime=0;

    while(currentLed==BLUE && game!=GAMEOVER)
    {
    blueLed::high();
    Thread::sleep(sleepTime);
    blueLed::low();
    Thread::sleep(sleepTime);
    currentLed=shouldRepeat(currentLed);
    }

    while(currentLed==GREEN && game!=GAMEOVER)
    {
    greenLed::high();
    Thread::sleep(sleepTime);
    greenLed::low();
    Thread::sleep(sleepTime);
    currentLed=shouldRepeat(currentLed);
    }

    while(currentLed==ORANGE && game!=GAMEOVER)
    {
    orangeLed::high();
    Thread::sleep(sleepTime);
    orangeLed::low();
    Thread::sleep(sleepTime);
    currentLed=shouldRepeat(currentLed);
    }

    while(currentLed==RED && game!=GAMEOVER)
    {
    redLed::high();
    Thread::sleep(sleepTime);
    redLed::low();
    Thread::sleep(sleepTime);
    currentLed=shouldRepeat(currentLed);
    }
}

/*
 * Turn Red, Blue, Green and Orange leds on.
 */
void turnAllOn()
{
    redLed::high();
    blueLed::high();
    greenLed::high();
    orangeLed::high();
}

/*
 * Turn Red, Blue, Green and Orange leds off.
 */
void turnAllOff()
{
    redLed::low();
    blueLed::low();
    greenLed::low();
    orangeLed::low();
}

/*
 * Game over ritual:
 *  Turn all leds on, sleep for 500ms, turn all leds of, sleep for 500ms.
 * Repeat this cycle 3 times.
 */
void gameOver()
{
    for(int i=0; i<=2; i++)
    {
        turnAllOn();
        Thread::sleep(500);
        turnAllOff();
        Thread::sleep(500);
    }
}
