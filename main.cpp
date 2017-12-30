/**
 * \file main.cpp
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 30/12/2017
 */

#include <miosix.h>
#include <pthread.h>
#include "led.h"
#include "game.h"
#include "player.h"
#include "button.h"

using namespace miosix;

/**
 * Boolean which represents the state of the game.
 * If (game==1), the current game is finished.
 * Elseif (game==0), the current game is still going.
 */
bool game;

/**
 * Boolean which represents the need of a players' interaction.
 * When interaction is true, the player must do something
 * (eg: press the user button) to avoid a game over.
 */
bool interaction;

/**
 * Boolean which represents the action of a player.
 * If (action==true), the player did an action.
 * Elseif (action==false), the player didn't do an action.
 */
bool action;

/**
 * Integer which represents the difficulty level of the game.
 * Higher integer means higher degree of difficulty.
 * It affects the time between the blinking LED's.
 */
int difficulty;

/**
 * Integer which represents the level of the game.
 */
int level;

/**
 * Integer which represents the current highscore of the game.
 */
int highscore;

/**
 * A pthread_mutex_t variable to prevent a race condition when changing action.
 */
 pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;


/**
 * Initialisation process of the main.
 *
 * @post The LED's are initialised.
 * @post The button is initialised.
 * @post highscore is set to 0.
 * @see initLeds()
 * @see configureButtonInterrupt()
 */
void mainInitialisation()
{
  initLeds();
  configureButtonInterrupt();
  highscore = 0;
}

/**
 * Reinitialisation process of the main. This is used to reset the game without
 * a complete reset by using the computer.
 *
 * @post Difficulty is set on 1.
 * @post Interaction is set on false.
 * @post Action is set on false while protected by mutex.
 * @post Game is set on 0.
 * @post Level is set on 0.
 * @post onOffBlinking(1) is executed.
 * @see onOffBlinking()
 */
void reInitialisation(){
  difficulty = 1;
  interaction = false;
  {
    pthread_mutex_lock(&mutex);
    action = false;
    pthread_mutex_unlock(&mutex);
  }
  game = 0;
  level = 0;
  onOffBlinking(1); //To emphasize the start of the game.
}

/*! \mainpage Blinking Reaction Game
 *
 * \section Introduction
 *
 * This game is developed with the Miosix kernel and made for the discoveryboard
 *STM32F407G.
 * It is a project for Embedded Systems 1 and Advanced Operating Systems
 *of prof. William Fornaciari at the Politecnico di Milano.
 *
 * \section Gameplay
 *
 * The game starts when the player pushes on the button. To emphasize the start
 *of the game, the four LED's will blink once. From then on each button push can
 *cause gameover. The blinking ritual will start with the blue LED and goes
 *random clockwise or counterclockwise. The main issue of the game is pushing
 *the button when the LED (blue/green/orange/red) blinks twice. If the player
 *pushes the button correctly the time between the blinks will be shorter and
 *consequentely the game will become more difficult.
 * If the player pushes the button to late or in a wrong situation
 *then the board will play a buzzer sound or a highscore sound.
 *After the buzzer/highscore sound, the game will start over again
 *with blinking the LED's 3 times.
 * Have Fun!
 *
 * \section Improvements
 *
 * Some improvements are listed in the issue area of the git repository. They
 *are signed with the label "extra feature".
 */
int main()
{
    mainInitialisation();
    waitForButton();
    game = GAMEOVER;
    while(1)
    {
        if(game==GAMEOVER) {
            reInitialisation();
        }
        blinkingGame();
    }
}
