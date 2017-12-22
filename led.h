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
 *
 * @param int difficulty - The current difficulty level of the game.
 * @return int The sleepTime between two blinking leds.
 */
int calculateSleepTime(int difficulty);

/**
 * Function for the clockwise blinking.
 *
 * @param int currentLed - The number of the current led.
 * @param int sleepTime - The sleeptime between two blinking leds.
 * @post Repeat the sequence:
 *  Turn led x high, sleep for sleepTime, turn led x low, sleep for sleepTime.
 * @post Sets currentLed to gamePlay(currentLed)
 * @see gamePlay()
 */
void blinkingClockwise(int currentLed, int sleepTime);

/**
 * Function for the counterclockwise blinking.
 *
 * @param int currentLed - The number of the current led.
 * @param int sleepTime - The sleeptime between two blinking leds.
 * @post Repeat the sequence:
 *  Turn led x high, sleep for sleepTime, turn led x low, sleep for sleepTime.
 * @post Sets currentLed to gamePlay(currentLed)
 * @see gamePlay()
 */
void blinkingCounterClockwise(int currentLed, int sleepTime);

/**
 * Function with the gameplay for the blinking sequence.
 *
 * @param int currentLed - The number of the current led.
 * @param int sleepTime - The sleeptime between two blinking leds.
 * @param bool clockwise - Specifies if the blinking sequence is clockwise (true) or counterclockwise (false)
 * @post if and only if (clockwise == true), blinkingClockwise() is excecuted.
 * @post if and only if (clockwise != true), blinkingCounterClockwise() is excecuted.
 *
 */
void blinkingsequence(int currentLed, int sleepTime, bool clockwise);

/**
 * Function with the game ritual.
 *
 * @see calculateSleepTime(int difficulty)
 * @see blinkingsequence()
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
 *
 * @post Repeat three times the sequence:
 *  Turn all leds on, sleep for 500ms, turn all leds off, sleep for 500ms.
 */
void gameOverBlinking();

#endif /* LED_H */
