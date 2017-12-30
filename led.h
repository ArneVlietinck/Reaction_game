/**
 * \file led.h
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 30/12/2017
 *
 * \brief The h-file of the LED library.
 */

#ifndef LED_H
#define LED_H

#define BLUE 1
#define GREEN 2
#define ORANGE 3
#define RED 4

/**
 * Initialisation of the Green, Orange, Red and Blue LED in output mode.
 */
void initLeds();

/**
 * Function which calculate if the LED should blink in clock or counterclockwise.
 *
 * @return Returns a random boolean which tells if the LED's should blink in
 *clock or counterclockwise.
 */
bool clockOrCounterClockWise();

/**
 * Calculate the sleepTime between two blinks of a LED.
 *
 * @param int difficulty - The current difficulty level of the game.
 * @return int sleepTime - The sleepTime between two blinking LED's.
 */
int calculateSleepTime(int difficulty);

/**
 * Function which blinks the currentLed (BLUE, GREEN, ORANGE, RED).
 *
 * @param int currentLed - The number of the current LED.
 * @param int sleepTime - The sleeptime between two blinking LED's.
 * @post Repeat the sequence: Turn currentLed high, sleep for sleepTime,
 *turn currentLed low, sleep for sleepTime.
 */
void blinkLed(int currentLed, int sleepTime);

/**
 * Function for the clockwise blinking.
 *
 * @param int currentLed - The number of the current LED.
 * @param int sleepTime - The sleeptime between two blinking LED's.
 * @post blinkLed(currentLed, sleepTime)
 * @post Sets currentLed to gamePlay(currentLed)
 * @see gamePlay()
 * @see blinkLed()
 */
void blinkingClockwise(int currentLed, int sleepTime);

/**
 * Function for the counterclockwise blinking.
 *
 * @param int currentLed - The number of the current LED.
 * @param int sleepTime - The sleeptime between two blinking LED's.
 * @post blinkLed(currentLed, sleepTime)
 * @post Sets currentLed to gamePlay(currentLed)
 * @see gamePlay()
 * @see blinkLed()
 */
void blinkingCounterClockwise(int currentLed, int sleepTime);

/**
 * Function with the gameplay for the blinking sequence.
 *
 * @param int currentLed - The number of the current LED.
 * @param int sleepTime - The sleeptime between two blinking LED's.
 * @param int level - Specifies the level of the current game.
 * @post If and only if (clockOrCounterClockWise() == true),
 *blinkingClockwise() is excecuted.
 * @post If and only if (clockOrCounterClockWise() != true),
 *blinkingCounterClockwise() is excecuted.
 * @see clockOrCounterClockWise()
 * @see blinkingClockwise()
 * @see blinkingCounterClockwise()
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
 * Turn Red, Blue, Green and Orange LED's on.
 */
void turnAllOn();

/**
 * Turn Red, Blue, Green and Orange LED's off.
 */
void turnAllOff();

/**
 * On off blinking ritual by LED's.
 *
 * @param int times - Number of times the LED's should blink.
 * @post Repeat - times - the sequence: turn all LED's on, sleep for 500ms,
 *turn all LED's off, sleep for 500ms.
 */
void onOffBlinking(int times);

#endif /* LED_H */
