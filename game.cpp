/*
 * File:   game.cpp
 * Authors: Simon Mastrodicasa & Arne Vlietinck
 */

#include"game.h"
#include"led.h"

/**
* @return A boolean which tells if the led should blink again.
* @note False should happen more than true.
*/
//TODO
bool shouldBlinkAgain()
{
    return false;
}

/**
*
*/
int shouldRepeat(int currentLed)
{
    /* interaction==false to avoid the situation where a interaction was true from the shouldRepeat
    * of the previous iteration and shouldRepeat is again true, which would lead
    * to a third repetition
    */
    if(interaction==false && shouldBlinkAgain()==1)
    {
        interaction=true;
    }
    //Something should have been done but the player didn't do it
    else if(interaction==true && action==false)
    {
        gameOver();
        game=GAMEOVER;
    }
    //Nothing should have been done and the player did something
    else if(interaction==false && action==true)
    {
        gameOver();
        game=GAMEOVER;
    }
    //Something should have been done and the player did it
    else if(interaction==true && action ==true)
    {
        //Back to normal
        interaction=false;
        action=false;
        currentLed++;
        //game becomes more challenging
        difficulty++;
    }
    else
    {
      currentLed++;
    }

    if(currentLed>RED)
    {
        currentLed=BLUE;
    }

    return currentLed;
}
