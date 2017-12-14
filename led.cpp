/*
 * File:   led.cpp
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */
#include "led.h"
#include "game.h"


void initLeds()
{
    greenLed::mode(Mode::OUTPUT);
    orangeLed::mode(Mode::OUTPUT);
    redLed::mode(Mode::OUTPUT);
    blueLed::mode(Mode::OUTPUT);
}

void blinkingAll()
{
    //Gameover when game=1
    game=0;

    int currentLed=BLUE;
    //The further the game, the shorter the time between an on/off
    int sleepTime= 600-30*difficulty;
    if (sleepTime<0)
        sleepTime=0;

    while(currentLed==BLUE && game!=GAMEOVER)
    {
    blueLed::high();    //Turn the LED on
    Thread::sleep(sleepTime); //Wait 500ms
    blueLed::low();     //Turn the LED off
    Thread::sleep(sleepTime); //Wait sleepTimems
    currentLed=shouldRepeat(currentLed);
    }

    while(currentLed==GREEN && game!=GAMEOVER)
    {
    greenLed::high();    //Turn the LED on
    Thread::sleep(sleepTime); //Wait sleepTimems
    greenLed::low();     //Turn the LED off
    Thread::sleep(sleepTime); //Wait sleepTimems
    currentLed=shouldRepeat(currentLed);
    }

    while(currentLed==ORANGE && game!=GAMEOVER)
    {
    orangeLed::high();    //Turn the LED on
    Thread::sleep(sleepTime); //Wait sleepTimems
    orangeLed::low();     //Turn the LED off
    Thread::sleep(sleepTime); //Wait sleepTimems
    currentLed=shouldRepeat(currentLed);
    }

    while(currentLed==RED && game!=GAMEOVER)
    {
    redLed::high();    //Turn the LED on
    Thread::sleep(sleepTime); //Wait sleepTimems
    redLed::low();     //Turn the LED off
    Thread::sleep(sleepTime); //Wait sleepTimems
    currentLed=shouldRepeat(currentLed);
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
void gameOver()
{
    for(int i=1; i<=3; i++)
    {
        turnAllOn();
        Thread::sleep(500);
        turnAllOff();
        Thread::sleep(500);
    }
}
