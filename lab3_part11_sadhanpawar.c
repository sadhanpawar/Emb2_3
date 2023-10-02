/*
 * lab3_part11_sadhanpawar.c
 *
 *  Created on: Feb 26, 2023
 *      Author: sadhan
 */

#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "clock.h"
#include "gpio.h"
#include "wait.h"
#include "nvic.h"
#include "main.h"

#define INPUT_PIN   PORTB,4
#define OUTPUT_PIN  PORTB,6

void lab3_part11_Init(void)
{
    enablePort(PORTB);
    selectPinPushPullOutput(OUTPUT_PIN);
    selectPinDigitalInput(INPUT_PIN);
    enablePinPullup(INPUT_PIN);
    enableNvicInterrupt(INT_GPIOB);
    selectPinInterruptFallingEdge(INPUT_PIN);
    enablePinInterrupt(INPUT_PIN);
    clearPinInterrupt(INPUT_PIN);


    setPinValue(OUTPUT_PIN,false);
}

void mcpGpioPortBIntHandler(void)
{
    /* set pin value to high */
    setPinValue(OUTPUT_PIN,true);

    /*clear the interrupt */
    clearPinInterrupt(INPUT_PIN);
}
