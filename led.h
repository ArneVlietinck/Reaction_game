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
 * Function which calculate if the led should blink in clock or counterclockwise.
 *
 * @return Returns a random boolean which tells if the led should blink again.
 */
bool clockOrCounterClockWise();

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
 * @param int level - Specifies the level of the current game.
 * @post if and only if (clockOrCounterClockWise() == true), blinkingClockwise() is excecuted.
 * @post if and only if (clockOrCounterClockWise() != true), blinkingCounterClockwise() is excecuted.
 * @see clockOrCounterClockWise()
 */
void blinkingsequence(int currentLed, int sleepTime, int level);

/**
 * Function with the game ritual.
 *
 * @see calculateSleepTime(int difficulty)
 * @see blinkingsequence(int currentLed, int sleepTime, int level)
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
 * On off blinking ritual by leds.
 *
 * @param int times - number of times
 * @post Repeat - times - the sequence:
 *  Turn all leds on, sleep for 500ms, turn all leds off, sleep for 500ms.
 */
void onOffBlinking(int times);

#endif /* LED_H */
