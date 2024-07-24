/*
 * main.c
 *
 *  Created on: Feb 17, 2024
 *      Author: muham
 */
#include "avr/interrupt.h"
#include "LIB/STD_TYPES.h"
#include "util/delay.h"
#include "MCAL/DIO/MDIO_interface.h"
#include "MCAL/TIM1/MTIM1_interface.h"

#define F_CPU	16e6U

/* Space Value */
#define POV_LETTER_SPACE_TIME		0.1


volatile f64 ticks = 0;
volatile f64 t1 = 0;
volatile f64 t2 = 0;
volatile f64 dt = 0;
volatile f64 tmp = 0;

void main (void)
{
	MDIO_voidSetPortDirection(C, OUTPUT);
	MDIO_voidSetPinDirection(D,7,OUTPUT);

	MTIM1_voidTimer1Init();

	MDIO_voidSetPinDirection(D,6, INPUT);
	while(1)
	{
		tmp = dt;
		if (tmp  < 0)
		{
			continue;
		}

		MDIO_voidSetPortValue(C, 255);
		_delay_us(0.005*tmp *1e6);

		MDIO_voidSetPortValue(C, 0);
		tmp  -= 0.005*tmp;
		_delay_us (tmp * 1e6);

	}
}

ISR(TIMER1_CAPT_vect)
{

	t2 = ((f32)MTIM1_voidTimer1GetInputCaptureRegister1()*(4e-6)) + (ticks * 262.14e-3);		// 1 tick time on clk prescaler 64
	dt = t2 - t1;
	t1 = t2;



}

ISR(TIMER1_OVF_vect)
{
	ticks += 1;
}


//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include "MCAL/DIO/MDIO_interface.h"

//volatile uint32_t overflowCount = 0;
//volatile uint16_t lastCapturedTime = 0;
//volatile uint32_t elapsedTime = 0;
//
//void Timer1_Init()
//{
//    // Set Timer1 in normal mode with prescaler of 64
//    TCCR1B |= (1 << CS11) | (1 << CS10);
//
//    // Enable Input Capture Noise Canceler and Input Capture Edge Select (rising edge)
//    TCCR1B |= (1 << ICNC1) | (1 << ICES1);
//
//    // Enable Timer1 Input Capture Interrupt
//    TIMSK |= (1 << TICIE1);
//}
//
//void IO_Init()
//{
//    // Set Input Capture pin (ICP1) as input
//    DDRD &= ~(1 << PIND6);
//
//    // Enable global interrupts
//    sei();
//}
//
//ISR(TIMER1_CAPT_vect)
//{
//    uint16_t currentTime = ICR1;
//    PORTC = 255;
//    if (TCCR1B & (1 << ICES1)) // Rising edge captured
//    {
//        lastCapturedTime = currentTime;
//        // Change edge detection to falling edge
//        TCCR1B &= ~(1 << ICES1);
//    }
//    else // Falling edge captured
//    {
//        uint32_t timeDiff;
//
//        if (currentTime >= lastCapturedTime) {
//            timeDiff = currentTime - lastCapturedTime;
//        } else {
//            timeDiff = (UINT16_MAX - lastCapturedTime) + currentTime + 1;
//        }
//
//        // Add the overflow count
//        timeDiff += overflowCount * ((uint32_t) (UINT16_MAX) + 1);
//
//        // Calculate elapsed time in milliseconds
//        elapsedTime = timeDiff * 64 / F_CPU * 1000;
//
//        // Change edge detection to rising edge
//        TCCR1B |= (1 << ICES1);
//    }
//}
//
//ISR(TIMER1_OVF_vect)
//{
//    // Increment overflow count
//    overflowCount++;
//}
//
//int main()
//{
//	DDRC = 255;
//    Timer1_Init();
//    IO_Init();
//
//    while (1)
//    {
//        // Your main code here
//    }
//
//    return 0;
//}
//
