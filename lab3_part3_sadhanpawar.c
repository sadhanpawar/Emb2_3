/*
 * lab3_part3_sadhanpawar.c
 *
 *  Created on: Feb 26, 2023
 *      Author: sadhan
 */




// Stop Go C Example (Basic)
// Jason Losh

//-----------------------------------------------------------------------------
// Hardware Target
//-----------------------------------------------------------------------------

// Target Platform: EK-TM4C123GXL Evaluation Board
// Target uC:       TM4C123GH6PM
// System Clock:    40 MHz

// Hardware configuration:
// Red LED:
//   PF1 drives an NPN transistor that powers the red LED
// Green LED:
//   PF3 drives an NPN transistor that powers the green LED
// Pushbutton:
//   SW1 pulls pin PF4 low (internal pull-up is used)

//-----------------------------------------------------------------------------
// Device includes, defines, and assembler directives
//-----------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "clock.h"
#include "gpio.h"
#include "wait.h"
#include "nvic.h"
#include "main.h"

// Pins

#define GREEN_LED_BB (*((volatile uint32_t *) (0x42000000 + (0x400253FC - 0x40000000)*32 + 3*4)))
#define GREEN_LED_PORT PORTF, 3
#define GREEN_LED_MASK (1<<3)


//-----------------------------------------------------------------------------
// Subroutines
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Subroutines
//-----------------------------------------------------------------------------

void toggleBitasmRMW(void)
{
    __asm("GREEN_LED: .field    0x400253FC  ");
    __asm("TOGGLEBIT:                       ");
    __asm("             LDR R0, GREEN_LED   ");
    __asm("             LDR R13, GREEN_LED   ");
    __asm("             LDR R0, [R0]        ");
    __asm("             EOR R0, R0, #0x08   "); //3rd bit
    __asm("             STR R0, [R13]       ");
    __asm("             B TOGGLEBIT         ");
}

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------
