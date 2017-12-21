/*
 * File: main.cpp
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */

#include <miosix.h>
#include <pthread.h>
#include "led.h"
#include "game.h"
#include "player.h"
#include "Buzzer.h"
#include "button.h"

using namespace miosix;

/*
 * Boolean which representate the state of the game.
 * If game==1, the current game is finished.
 */
bool game;
/*
 * When interaction is true, the player must do something (eg:press a button) to avoid a game over.
 */
bool interaction;
/*
 * Tell if the player did an action.
 */
bool action;
/*
 * Increased difficulty means less time between on and off.
 */
int difficulty;
/*
 *
 */
 pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

/*
 * Initialisation of the main:
 *  Led initialisation
 *  Button initialisation
 */
void mainInitialisation()
{
  initLeds();
  configureButtonInterrupt();
}

int main()
{
    mainInitialisation();
    //while (game == 0)
    //{
      waitForButton(); //Start game by clicking the button
      //gameOver();
      //blinkingAll();
    //}
    game=GAMEOVER;
    while(1)
    {
        if(game==GAMEOVER) {
            //Initialisation
            difficulty = 1;
            interaction = false;
            {
              pthread_mutex_lock(&mutex);
              action = false;
              pthread_mutex_unlock(&mutex);
            }
            game = 0;
        }
        blinkingAll();
    }
}
