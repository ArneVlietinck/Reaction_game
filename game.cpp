/*
 * File: game.cpp
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */

#include <pthread.h>
#include "game.h"
#include "led.h"
#include "player.h"
#include "Buzzer.h"

extern pthread_mutex_t mutex;

/*
 * @return Returns a boolean which tells if the led should blink again.
 * @note The boolean is in 30% of the situations true and in the other 70% false.
 */
bool shouldBlinkAgain()
{
    int randomval = rand() % 10;
    if(randomval < 3)
    {
      return true;
    }
    else
    {
      return false;
    }
}

/**
 *
 */
int shouldRepeat(int currentLed)
{
    pthread_mutex_lock(&mutex);
    /* interaction == false to avoid the situation where an interaction was true from the shouldRepeat
     * of the previous iteration and shouldRepeat is again true, which would lead
     * to a third repetition
     */
    if(interaction==false && shouldBlinkAgain()==true)
    {
        interaction = true;
    }
    //Something should have been done but the player didn't do it
    else if(interaction==true && action==false)
    {
        ADPCMSound sound(Buzzer_bin,Buzzer_bin_len);
        Player::instance().play(sound);
        gameOver();
        game = GAMEOVER;
    }
    //Nothing should have been done and the player did something
    else if(interaction==false && action==true)
    {
        ADPCMSound sound(Buzzer_bin,Buzzer_bin_len);
        Player::instance().play(sound);
        gameOver();
        game = GAMEOVER;
    }
    //Something should have been done and the player did it
    else if(interaction==true && action==true)
    {
        //Back to normal
        interaction = false;
        action = false;
        currentLed++;
        //game becomes more challenging
        difficulty++;
    }
    else
    {
      currentLed++;
    }

    pthread_mutex_unlock(&mutex);

    if(currentLed > RED)
    {
        currentLed = BLUE;
    }

    return currentLed;
}
