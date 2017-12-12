
#include <miosix.h>
#include "led.h"
#include "game.h"
using namespace miosix;


//If game=GAMEOVER, the current game is finished
bool game;
//When risk is true, the player must do something (eg:press a button) to avoid a game over
bool risk;
//Tell if the player did an action
bool action;
//Increased difficulty means less time between on and off
int difficulty;


int main()
{
    greenLed::mode(Mode::OUTPUT);
    orangeLed::mode(Mode::OUTPUT);
    redLed::mode(Mode::OUTPUT);	
    blueLed::mode(Mode::OUTPUT);
    
    button::mode(Mode::INPUT);
    
    
    game=GAMEOVER;
    //Not useful
    //Thread *thread;
    //thread=Thread::create(interruptButton,2048,PRIORITY_MAX-1,NULL, Thread::JOINABLE);
    while(1)
    {
        //while(button::value()==0) Thread::sleep(10);
        
        if(game==GAMEOVER)
        {
            //Initialisation
            difficulty=1;
            risk=false;
            action=false;
            game=0;
        }
        blinkingAll();
        //thread->join();

       
    }
  
    
	
    
}

