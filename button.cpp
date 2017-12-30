/**
 * \file button.cpp
 * \author Federico Terraneo
 * \author Simon Mastrodicasa
 * \author Arne Vlietinck
 * \version 1.0
 * \date 30/12/2017
 */

#include "button.h"
#include <miosix.h>
#include <miosix/kernel/scheduler/scheduler.h>
#include <pthread.h>

using namespace miosix;
using namespace std;

typedef Gpio<GPIOA_BASE,0> button;

extern pthread_mutex_t mutex;
extern bool action;

static Thread *waiting=0;

void __attribute__((naked)) EXTI0_IRQHandler()
{
    saveContext();
    asm volatile("bl _Z16EXTI0HandlerImplv");
    {
      pthread_mutex_lock(&mutex);
      action=true;
      pthread_mutex_unlock(&mutex);
    }
    restoreContext();
}

void __attribute__((used)) EXTI0HandlerImpl()
{
    EXTI->PR=EXTI_PR_PR0;

    if(waiting==0) return;
    waiting->IRQwakeup();
    if(waiting->IRQgetPriority()>Thread::IRQgetCurrentThread()->IRQgetPriority())
		Scheduler::IRQfindNextThread();
    waiting=0;
}

void configureButtonInterrupt()
{
    button::mode(Mode::INPUT_PULL_DOWN);
    EXTI->IMR |= EXTI_IMR_MR0;
    EXTI->RTSR |= EXTI_RTSR_TR0;
    NVIC_EnableIRQ(EXTI0_IRQn);
    NVIC_SetPriority(EXTI0_IRQn,15); //Low priority
}

void waitForButton()
{
    FastInterruptDisableLock dLock;
    waiting=Thread::IRQgetCurrentThread();
    while(waiting)
    {
        Thread::IRQwait();
        FastInterruptEnableLock eLock(dLock);
        Thread::yield();
    }
}
