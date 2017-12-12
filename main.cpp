//#include "led.h"
#include <miosix.h>
#include "led.h"
using namespace miosix;

typedef Gpio<GPIOD_BASE,12> greenLed;
typedef Gpio<GPIOD_BASE,13> orangeLed;
typedef Gpio<GPIOD_BASE,14> redLed;
typedef Gpio<GPIOD_BASE,15> blueLed;

typedef Gpio<GPIOA_BASE,0> button;

#define BLUE 1
#define GREEN 2
#define ORANGE 3
#define RED 4
#define GAMEOVER 1

//If game=GAMEOVER, the current game is finished
bool game;
//When risk is true, the player must do something (eg:press a button) to avoid a game over
bool risk;
//Tell if the player did an action
bool action;
//Increased difficulty means less time between on and off
int difficulty;


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






void initLeds()
{
    greenLed::mode(Mode::OUTPUT);
    orangeLed::mode(Mode::OUTPUT);
    redLed::mode(Mode::OUTPUT);	
    blueLed::mode(Mode::OUTPUT);
}

void blinkingAll()
{
    //Gameover when game=1
    game=0;
    
    int currentLed=BLUE;
    //The further the game, the shorter the time between an on/off
    int sleepTime= 600-30*difficulty;
    if (sleepTime<0)
        sleepTime=0;
        
    while(currentLed==BLUE && game!=GAMEOVER)
    {
    blueLed::high();    //Turn the LED on
    Thread::sleep(sleepTime); //Wait 500ms
    blueLed::low();     //Turn the LED off
    Thread::sleep(sleepTime); //Wait sleepTimems
    currentLed=shouldRepeat(currentLed);
    }
    
    while(currentLed==GREEN && game!=GAMEOVER)
    {
    greenLed::high();    //Turn the LED on
    Thread::sleep(sleepTime); //Wait sleepTimems
    greenLed::low();     //Turn the LED off
    Thread::sleep(sleepTime); //Wait sleepTimems
    currentLed=shouldRepeat(currentLed);
    }

    while(currentLed==ORANGE && game!=GAMEOVER)
    {
    orangeLed::high();    //Turn the LED on
    Thread::sleep(sleepTime); //Wait sleepTimems
    orangeLed::low();     //Turn the LED off
    Thread::sleep(sleepTime); //Wait sleepTimems
    currentLed=shouldRepeat(currentLed);
    }
    
    while(currentLed==RED && game!=GAMEOVER)
    {
    redLed::high();    //Turn the LED on
    Thread::sleep(sleepTime); //Wait sleepTimems
    redLed::low();     //Turn the LED off
    Thread::sleep(sleepTime); //Wait sleepTimems
    currentLed=shouldRepeat(currentLed);
    }
    
}

void turnAllOn()
{
    redLed::high(); 
    blueLed::high(); 
    greenLed::high(); 
    orangeLed::high(); 
}
void turnAllOff()
{
    redLed::low(); 
    blueLed::low(); 
    greenLed::low(); 
    orangeLed::low(); 
}
void gameOver()
{
    for(int i=1; i<=3; i++)
    {
        turnAllOn();
        Thread::sleep(500);
        turnAllOff();
        Thread::sleep(500);
    }
}


//void interruptButton(void *argv)
//{
    //if(button::value()==1)
  //      action=true;
//}

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

