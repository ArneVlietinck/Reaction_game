/**
 * \file game.cpp
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 30/12/2017
 *
 * \brief The cpp-file of the gameplay library.
 */

#include <miosix.h>
#include <pthread.h>
#include "game.h"
#include "led.h"
#include "player.h"
#include "buzzer.h"
#include "highscore.h"

using namespace miosix;

typedef Gpio<GPIOA_BASE,0> button;

extern bool action;
extern bool game;
extern bool interaction;
extern int difficulty;
extern int level;
extern int highscore;
extern pthread_mutex_t mutex;

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

void buzzerSound()
{
    ADPCMSound sound(buzzer_bin,buzzer_bin_len);
    Player::instance().play(sound);
}

void highscoreSound()
{
    ADPCMSound sound(highscore_bin,highscore_bin_len);
    Player::instance().play(sound);
}

void gameOver()
{
    if(level>highscore){
      highscoreSound();
      highscore = level;
    }
    else{
      buzzerSound();
    }
    onOffBlinking(2);
    game = GAMEOVER;
}

int gamePlay(int currentLed, bool clockwise)
{
    pthread_mutex_lock(&mutex);
    /*
     * (interaction==false) to avoid the situation where an interaction
     *was true from the shouldRepeat of the previous iteration and
     *shouldRepeat is again true, which would lead to a third repetition.
     */
    if(interaction==false && shouldBlinkAgain()==true)
    {
        interaction = true;
    }
    //Something should have been done but the player didn't do it.
    else if(interaction==true && action==false)
    {
        pthread_mutex_unlock(&mutex);
        gameOver();
        pthread_mutex_lock(&mutex);
    }
    //Nothing should have been done and the player did something.
    else if(interaction==false && action==true)
    {
        pthread_mutex_unlock(&mutex);
        gameOver();
        pthread_mutex_lock(&mutex);
    }
    //Something should have been done and the player did it.
    else if(interaction==true && action==true)
    {
        //Back to normal.
        interaction = false;
        action = false;
        if(clockwise)
        {
          currentLed++;
        }
        else
        {
          currentLed--;
        }
        //Game becomes more challenging.
        difficulty++;
        level++;
    }
    else
    {
      if(clockwise)
      {
        currentLed++;
      }
      else
      {
        currentLed--;
      }
    }

    pthread_mutex_unlock(&mutex);

    //Handle issue when currentLed>4.
    if(currentLed>RED)
    {
        currentLed = BLUE;
    }

    //Handle issue when currentLed<1.
    if(currentLed<BLUE)
    {
        currentLed = RED;
    }

    return currentLed;
}
