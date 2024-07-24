#ifndef _MADC_PRIVATE_H
#define _MADC_PRIVATE_H

/* ADMUX Bits */
#define ADLAR   5

/* ADCSTA Bits */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3

#define ACSR    *((volatile u8 *)0x28)
#define ADMUX   *((volatile u8 *)0x27)
#define ADCSRA  *((volatile u8 *)0x26)

#define ADC     *((volatile u16 *)0x24)
#define ADCH    *((volatile u8 *)0x25)
#define ADCL    *((volatile u8 *)0x24)

#define SFIOR   *((volatile u8 *)0x50)

#endif