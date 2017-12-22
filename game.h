/**
 * \file game.h
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 22/12/2017
 */

#ifndef GAME_H
#define GAME_H

#define GAMEOVER 1

/**
 * Function which calculate if the led should blink for a second time.
 * @return Returns a random boolean which tells if the led should blink again.
 * @note The boolean is in 30% of the situations true and in the other 70% false.
 */
bool shouldBlinkAgain();

/**
 * Function which plays the buzzer sound.
 */
void buzzerSound();

/**
 * Function which does the gameOver ritual.
 * @post The buzzersound is played.
 * @post The gameOver blinking ritual is played.
 * @see buzzerSound()
 * @see gameOverBlinking()
 */
void gameOver();

/**
 *
 * @param int currentled - The number of the current led.
 * @post If and only if (interaction==false && shouldBlinkAgain()==true), interaction is set true.
 * @post If (interaction==true && action==false), gameOver ritual starts.
 * @post If (interaction==false && action==true), gameOver ritual starts.
 * @post If and only if (interaction==true && action==true), interaction is set false.
 * @post If and only if (interaction==true && action==true), action is set false.
 * @post If and only if (interaction==true && action==true), difficulty is incremented by one.
 * @post The currentled is incremented by one.
 * @post If and only if currentled is bigger then the biggest led (red),
 * it is reset to the first led (blue).
 * @return int currentLed - The number of the current led.
 * @see gameOver()
 * @see shouldBlinkAgain();
 */
int gamePlay(int currentLed);

#endif /* GAME_H */
