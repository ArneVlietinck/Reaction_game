/*
 * File:   main.cpp
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */

#include <miosix.h>
#include "led.h"
#include "game.h"
#include "player.h"
#include "Buzzer.h"
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


int main()
{
    greenLed::mode(Mode::OUTPUT);
    orangeLed::mode(Mode::OUTPUT);
    redLed::mode(Mode::OUTPUT);
    blueLed::mode(Mode::OUTPUT);

    button::mode(Mode::INPUT);

    game=GAMEOVER;
    while(1)
    {
        if(game==GAMEOVER) {
            //Initialisation
            difficulty = 1;
            interaction = false;
            action = false;
            game = 0;
        }
        if(button::value()==1)
        {
          blinkingAll();
          ADPCMSound sound(Buzzer_bin,Buzzer_bin_len);
          Player::instance().play(sound);
        }
        //thread->join();
    }
}
