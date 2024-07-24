#ifndef _MADC_CONFIG_H

#define _MADC_CONFIG_H


/* Available Voltage References:

    MADC_V_REF_AREF     ->  Internal VREF is off
    MADC_V_REF_AVCC     ->  AVCC with external capacitor at AREF pin
    MADC_V_REF_V2_65    -> Internal 2.65 Voltage with cap at AREF pin 

*/

#define  MADC_V_REF     MADC_V_REF_AVCC

/*

    Allow Left Adjustment of result

    ON      -> Allow Left Adjustment
    OFF     -> Default Result Adjustment

*/

#define MADC_LEFT_ADJUST_RESULT     OFF

/*

    Select Free Running or Single Conversion Mode:

    MADC_SINGLE_CONV    ->  Single Conversion Mode
    MADC_AUTO_TRIGGER   ->  Convert on selected trigger

*/

#define MADC_CONVERSION_MODE    MADC_AUTO_TRIGGER


/*

    Available Trigger Sources:

    MADC_TRIG_MODE_FREE_RUNNING       -> Free Running Mode
    MADC_TRIG_MODE_ANALOG_COMP        -> Trigger on Analog Comparator Result
    MADC_TRIG_MODE_EXT_IRQ_0          -> Trigger on External Interrupt Request
    MADC_TRIG_MODE_TIM0_COMP_MATCH    -> Trigger on Timer 0 Compare match
    MADC_TRIG_MODE_TIM0_OVF           -> Trigger on Timer 0 Overflow
    MADC_TRIG_MODE_TIM1_OVF           -> Trigger on Timer 1 Compare Match
    MADC_TRIG_MODE_TIM1_CAPTURE       -> Trigger on Time 1 Input Capture
    
*/

#define MADC_TRIG_MODE  MADC_TRIG_MODE_FREE_RUNNING



/*

    Enable ADC Conversion Complete Interrupt

    ON               -> Interrupt Enabled
    OFF              -> Interrupt Disabled

*/

#define MADC_ENABLE_IRQ     OFF

/*

    Available ADC Prescaler values:

    MADC_ADC_CLK_DIV_2              -> Prescaler Value 2
    MADC_ADC_CLK_DIV_4              -> Prescaler Value 4
    MADC_ADC_CLK_DIV_8              -> Prescaler Value 8
    MADC_ADC_CLK_DIV_16             -> Prescaler Value 16
    MADC_ADC_CLK_DIV_32             -> Prescaler Value 32
    MADC_ADC_CLK_DIV_64             -> Prescaler Value 64
    MADC_ADC_CLK_DIV_128            -> Prescaler Value 128

*/

#define MADC_ADC_CLK    MADC_ADC_CLK_DIV_2




#endif
