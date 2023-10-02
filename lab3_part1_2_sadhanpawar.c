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


/* uncomment these macros to enable functionality */
#define TG_RMW
//#define TG_BB
//#define TG_RMW_ASM
//#define TG_BB_ASM
//-----------------------------------------------------------------------------
// Subroutines
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Subroutines
//-----------------------------------------------------------------------------

// Initialize Hardware
void initHw()
{
    // Initialize system clock to 40 MHz
    initSystemClockTo40Mhz();

    // Enable clocks
    enablePort(PORTF);

    // Configure LED and pushbutton pins
    selectPinPushPullOutput(GREEN_LED_PORT);

    lab3_part11_Init();
}

#ifdef TG_RMW
void toggleBitRMW(void)
{
    uint32_t port = GPIO_PORTF_DATA_R;

    while(true){
        port ^= GREEN_LED_MASK;
        GPIO_PORTF_DATA_R = port;
    }
}
#endif
//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------

int main(void)
{
    // Initialize hardware
    initHw();

    //toggleBitRMW();
    //toggleBitBBand();
    //toggleBitasmBBand();
    toggleBitasmRMW();

    // Endless loop
    while(true);
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

#if 0
void mcpGpioPortBIntHandler(void)
{
    /* set pin value to high */
    setPinValue(OUTPUT_PIN,true);

    /*clear the interrupt */
    clearPinInterrupt(INPUT_PIN);
}
#endif
