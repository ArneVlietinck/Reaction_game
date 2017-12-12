/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"game.h"
#include"led.h"



bool shouldBlinkAgain()
{
    //TO DO:
    //Should return a boolean to tell if it has to blink again by random number. 
    //False should happen way more often
    return false;
}

int shouldRepeat(int currentLed)
{
    //risk==false to avoid the situation where a risk was true from the shouldRepeat
    //of the previous iteration and shouldRepeat is again true, which would lead 
    //to a third repetition
    if(risk==false && shouldBlinkAgain()==1) 
    {
        risk=true;
    }
    //Something should have been done but the player didn't do it
    else if(risk==true && action==false)
    {
        gameOver();
        game=GAMEOVER;
    }
    //Nothing should have been done and the player did something
    else if(risk==false && action==true)
    {
        gameOver();
        game=GAMEOVER;       
    }    
    //Something should have been done and the player did it
    else if(risk==true && action ==true)
    {
        //Back to normal
        risk=false;
        action=false;
        currentLed++;
        //game becomes more challenging
        difficulty++;
    }
    else
        currentLed++;
    
    
    if(currentLed>RED)
        currentLed=BLUE;
    
    return currentLed;
}

