/**
 * \file main.cpp
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 22/12/2017
 */

#include <miosix.h>
#include <pthread.h>
#include "led.h"
#include "game.h"
#include "player.h"
#include "button.h"

using namespace miosix;

/**
 * Boolean which representate the state of the game.
 * If game==1, the current game is finished.
 * Elseif game==0, the current game is still going.
 */
bool game;

/**
 * Boolean which representate the need of a players' interaction.
 * When interaction is true, the player must do something
 * (eg: press the user button) to avoid a game over.
 */
bool interaction;

/**
 * Boolean which representate the action of a player.
 * When action is true, the player did an action.
 * When action is false, the player didn't do an action.
 */
bool action;

/**
 * Integer which representate the difficulty level of the game.
 * Higher integer means higher degree of difficulty.
 * It affects the time between the blinking leds.
 */
int difficulty;

/**
 * Integer which representate the level of the game.
 * There are several gameplays implemented depending on the game level.
 */
int level;

/**
 * A pthread_mutex_t variable to prevent a race condition when changing action.
 */
 pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;


/**
 * Initialisation process of the main.
 *
 * @post The leds are initialised.
 * @post The button is initialised.
 */
void mainInitialisation()
{
  initLeds();
  configureButtonInterrupt();
}

/**
 * Reinitialisation process of the main. This is used to reset the game without
 * a complete reset by using the computer.
 *
 * @post difficulty is set on 1.
 * @post Interaction is set on false.
 * @post Action is set on false while protected by mutex.
 * @post Game is set on 0;
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
}

/*! \mainpage Blinking Reaction Game
 *
 * \section Introduction
 *
 * This game is made for the discoveryboard STM32F407G.
 * It is a project for Embedded Systems 1 and Advanced Operating Systems
 *of prof. William Fornaciari at the Politecnico di Milano.
 *
 * \section Gameplay
 *
 * The game starts when the player pushes on the button. To emphasize that the
 *game starts, the four leds will blink once. From then on each button push can
 *cause gameover. The blinking ritual will start with the blue led and goes
 *random clockwise or counterclockwise. The main issue of the game is pushing
 *the button when the led (blue/green/orange/red) blinks twice. If the player
 *pushes the button correctly the time between the blinks will be shorter and
 *consequentely the game will become more difficult.
 * If the player pushes the button to late or in a wrong situation
 *then the board will play a buzzer sound. After the buzzer sound,
 *the game will start over again with blinking the leds 3 times.
 * Good Luck!
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
            onOffBlinking(1); /// To emphasize the start of the game.
        }
        blinkingGame();
    }
}
