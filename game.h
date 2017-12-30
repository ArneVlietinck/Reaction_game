/**
 * \file game.h
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 30/12/2017
 *
 * \brief The h-file of the gameplay library.
 */

#ifndef GAME_H
#define GAME_H

#define GAMEOVER 1

/**
 * Function which calculate if the LED should blink for a second time.
 *
 * @return Returns a random boolean which tells if the LED should blink again.
 * @note The boolean is in 30% of the situations true and in the other 70% false.
 */
bool shouldBlinkAgain();

/**
 * Function which plays the buzzer sound.
 */
void buzzerSound();

/**
 * Function which plays the high score sound.
 */
void highscoreSound();

/**
 * Function which does the gameOver ritual.
 *
 * @post If and only if (level>highscore), the high score sound is played.
 * @post If and only if (level>highscore), highscore is set to level.
 * @post If (level<=highscore), the buzzer sound is played.
 * @post The gameOver blinking ritual is played.
 * @post Game is set to GAMEOVER.
 * @see buzzerSound()
 * @see highscoreSound()
 * @see onOffBlinking()
 */
void gameOver();

/**
 * Function which takes care of the gameplay. It checks the several possible
 *conditions and increment or decrement the several game parameters. When the
 *player did a wrong interaction the gameover ritual is started.
 *
 * @param int currentled - The number of the current LED.
 * @param bool clockwise - Represents the order of blinking the LED's.
 * @post If and only if (interaction==false && shouldBlinkAgain()==true), interaction is set true.
 * @post If (interaction==true && action==false), gameOver() is excecuted.
 * @post If (interaction==false && action==true), gameOver() is excecuted.
 * @post If and only if (interaction==true && action==true), interaction is set false.
 * @post If and only if (interaction==true && action==true), action is set false.
 * @post If and only if (interaction==true && action==true), difficulty is incremented by one.
 * @post If and only if (interaction==true && action==true), level is incremented by one.
 * @post If and only if (clockwise==true), currentLed is incremented by one.
 * @post If and only if (clockwise!=false), currentLed is decremented by one.
 * @post If and only if (currentLed>RED), currentLed is set to the smallest LED (BLUE).
 * @post If and only if (currentLed<BLUE), currentLed is set to the biggest LED (RED).
 * @return int currentLed - The number of the current LED.
 * @see gameOver()
 * @see shouldBlinkAgain();
 */
int gamePlay(int currentLed, bool clockwise);

#endif /* GAME_H */
