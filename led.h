/**
 * \file led.h
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 22/12/2017
 */

#ifndef LED_H
#define LED_H

#define BLUE 1
#define GREEN 2
#define ORANGE 3
#define RED 4

/**
 * Initialisation of the Green, Orange, Red and Blue led in output mode.
 */
void initLeds();

/**
 * Calculate the sleepTime between two blinks of a led.
 * @param int difficulty - The current difficulty level of the game.
 * @return int The sleepTime between two blinking leds.
 */
int calculateSleepTime(int difficulty);

/**
 * Function with the game ritual.
 * @post Repeat the sequence:
 *  Turn led x high, sleep for sleepTime, turn led x low, sleep for sleepTime,
 *  sets currentLed to gamePlay(currentLed)
 * @see gamePlay()
 */
void blinkingGame();

/**
 * Turn Red, Blue, Green and Orange leds on.
 */
void turnAllOn();

/**
 * Turn Red, Blue, Green and Orange leds off.
 */
void turnAllOff();

/**
 * Game over ritual by the blinking leds.
 * @post Repeat three times the sequence:
 *  Turn all leds on, sleep for 500ms, turn all leds off, sleep for 500ms.
 */
void gameOverBlinking();

#endif /* LED_H */
