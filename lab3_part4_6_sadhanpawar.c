/*
 * lab3_part4_6_sadhanpawar.c
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

#define GREEN_LED_BB (*((volatile uint32_t *) (0x42000000 + (0x400253FC - 0x40000000)*32 + 3*4)))

void toggleBitBBand(void)
{
    while(true){
        GREEN_LED_BB ^= 1;
    }
}


void toggleBitasmBBand(void)
{
    __asm("GREENLEDASM: .field      0x424A7F8C  ");
    __asm("TOGGLEBITASM:                        ");
    __asm("             LDR R0, GREENLEDASM     ");
    __asm("             LDR R13, GREENLEDASM   ");
    __asm("             LDR R0, [R0]            ");
    __asm("             EOR R0, R0, #0x1        "); //3rd bit
    __asm("             STR R0, [R13]           ");
    __asm("             B TOGGLEBITASM          ");
}


