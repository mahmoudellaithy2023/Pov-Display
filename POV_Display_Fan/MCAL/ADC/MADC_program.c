#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "MADC_private.h"
#include "MADC_interface.h"
#include "MADC_config.h"


/*

    Function: MADC_voidADCInit

    Initialize ADC with initial configs

*/

void MADC_voidADCInit(void)
{
    /* Initialize Clock Prescaler */
    ADCSRA |= MADC_ADC_CLK;

    /* Initialize Voltage Reference */
    ADMUX |= MADC_V_REF << 6;

    /* Configure Left Adjsutment */
    SET_BIT(ADMUX, ADLAR);

    /* Configure auto Trigger */
    SET_BIT(ADCSRA, ADATE);

    /* Configure Interrupt */
//    SET_BIT(ADCSRA, ADIE);

    /* Confugre ADC Trigger Source */
    SFIOR |= MADC_TRIG_MODE << 5;

    /* Enable ADC */
    SET_BIT(ADCSRA, ADEN);
}

/*

    Function: MADC_voidStart

    Enables ADC

*/

void MADC_voidStartConversion (void)
{
    SET_BIT(ADCSRA, ADSC);
}

/*

    Function: MADC_voidStop()

    Disables ADC

*/

void MADC_voidStopConversion(void)
{
    RESET_BIT(ADCSRA, ADSC);
}

/*

    Function: MADC_u16GetConversion

    return conversion Result

*/

u16 MADC_u16GetConversion (u8 channel)
{
    /* Select Channel */
    ADMUX |= channel;
    
    /* Wait Until Conversion Complete */
//    while (!GET_BIT(ADCSRA, ADIF));

    /* Return Result */
    return ADC;
}
