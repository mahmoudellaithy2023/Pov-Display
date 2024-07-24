#ifndef _MADC_INTERFACE_H
#define _MADC_INTERFACE_H


/* Available Voltage References */
enum ADC_Vrefs
{
    MADC_V_REF_AREF, 
    MADC_V_REF_AVCC ,
    RESERVED,
    MADC_V_REF_V2_65,
};

/* Status Definitions */
#define ON      1
#define OFF     0

/* Available Conversion Modes */
enum ADC_Modes
{
    MADC_SINGLE_CONV,
    MADC_AUTO_TRIGGER
};

/* Available Trigger Sources */
enum ADC_Triggers
{
    MADC_TRIG_MODE_FREE_RUNNING,
    MADC_TRIG_MODE_ANALOG_COMP,  
    MADC_TRIG_MODE_EXT_IRQ_0,      
    MADC_TRIG_MODE_TIM0_COMP_MATCH,
    MADC_TRIG_MODE_TIM0_OVF,
    RESERVED_1,
    MADC_TRIG_MODE_TIM1_OVF,      
    MADC_TRIG_MODE_TIM1_CAPTURE   
};

/* Available Prescaler Values */
enum ADC_Prescalers
{
    MADC_ADC_CLK_DIV_2, 
    MADC_ADC_CLK_DIV_4, 
    MADC_ADC_CLK_DIV_8,  
    MADC_ADC_CLK_DIV_16, 
    MADC_ADC_CLK_DIV_32, 
    MADC_ADC_CLK_DIV_64, 
    MADC_ADC_CLK_DIV_128
};

/*

Available Channel Combinations:

    MADC_SINGLE_ENDED_INPUT_ADC0        -> select channel ADC0
    MADC_SINGLE_ENDED_INPUT_ADC1        -> select channel ADC1
    MADC_SINGLE_ENDED_INPUT_ADC2        -> select channel ADC2
    MADC_SINGLE_ENDED_INPUT_ADC3        -> select channel ADC3
    MADC_SINGLE_ENDED_INPUT_ADC4        -> select channel ADC4
    MADC_SINGLE_ENDED_INPUT_ADC5        -> select channel ADC5
    MADC_SINGLE_ENDED_INPUT_ADC6        -> select channel ADC6
    MADC_SINGLE_ENDED_INPUT_ADC7        -> select channel ADC7

    MADC_DIFF_INPUT_A0_A0_X10           -> Differential Input with Positive Differential at ADC0 and Negative Differential Input at ADC0 with gain 10x
    MADC_DIFF_INPUT_A1_A0_X10           -> Differential Input with Positive Differential at ADC1 and Negative Differential Input at ADC0 with gain 10x
    MADC_DIFF_INPUT_A0_A0_X200          -> Differential Input with Positive Differential at ADC0 and Negative Differential Input at ADC0 with gain 200x
    MADC_DIFF_INPUT_A1_A0_X200          -> Differential Input with Positive Differential at ADC1 and Negative Differential Input at ADC0 with gain 200x
    MADC_DIFF_INPUT_A2_A2_X10           -> Differential Input with Positive Differential at ADC2 and Negative Differential Input at ADC2 with gain 10x
    MADC_DIFF_INPUT_A3_A2_X10           -> Differential Input with Positive Differential at ADC3 and Negative Differential Input at ADC2 with gain 10x
    MADC_DIFF_INPUT_A2_A2_X200          -> Differential Input with Positive Differential at ADC2 and Negative Differential Input at ADC2 with gain 200x
    MADC_DIFF_INPUT_A3_A2_X200          -> Differential Input with Positive Differential at ADC3 and Negative Differential Input at ADC2 with gain 200x
    
    MADC_DIFF_INPUT_A0_A1_X1            -> Differential Input with Positive Differential at ADC0 and Negative Differential Input at ADC1 with gain 1x
    MADC_DIFF_INPUT_A1_A1_X1            -> Differential Input with Positive Differential at ADC1 and Negative Differential Input at ADC1 with gain 1x
    MADC_DIFF_INPUT_A2_A1_X1            -> Differential Input with Positive Differential at ADC2 and Negative Differential Input at ADC1 with gain 1x
    MADC_DIFF_INPUT_A3_A1_X1            -> Differential Input with Positive Differential at ADC3 and Negative Differential Input at ADC1 with gain 1x
    MADC_DIFF_INPUT_A4_A1_X1            -> Differential Input with Positive Differential at ADC4 and Negative Differential Input at ADC1 with gain 1x
    MADC_DIFF_INPUT_A5_A1_X1            -> Differential Input with Positive Differential at ADC5 and Negative Differential Input at ADC1 with gain 1x
    MADC_DIFF_INPUT_A6_A1_X1            -> Differential Input with Positive Differential at ADC6 and Negative Differential Input at ADC1 with gain 1x
    MADC_DIFF_INPUT_A7_A1_X1            -> Differential Input with Positive Differential at ADC7 and Negative Differential Input at ADC1 with gain 1x

    MADC_DIFF_INPUT_A0_A2_X1            -> Differential Input with Positive Differential at ADC0 and Negative Differential Input at ADC2 with gain 1x
    MADC_DIFF_INPUT_A1_A2_X1            -> Differential Input with Positive Differential at ADC1 and Negative Differential Input at ADC2 with gain 1x
    MADC_DIFF_INPUT_A2_A2_X1            -> Differential Input with Positive Differential at ADC2 and Negative Differential Input at ADC2 with gain 1x
    MADC_DIFF_INPUT_A3_A2_X1            -> Differential Input with Positive Differential at ADC3 and Negative Differential Input at ADC2 with gain 1x
    MADC_DIFF_INPUT_A4_A2_X1            -> Differential Input with Positive Differential at ADC4 and Negative Differential Input at ADC2 with gain 1x
    MADC_DIFF_INPUT_A5_A2_X1            -> Differential Input with Positive Differential at ADC5 and Negative Differential Input at ADC2 with gain 1x

    MADC_SINGLE_ENDED_INPUT_1_22_V      -> Single ended input with read value 1.22v fixed
    MADC_SINGLE_ENDED_INPUT_GND         -> Single ended input with read value GND fixed

*/

enum ADMUX_Channels
{
    MADC_SINGLE_ENDED_INPUT_ADC0,
    MADC_SINGLE_ENDED_INPUT_ADC1,  
    MADC_SINGLE_ENDED_INPUT_ADC2, 
    MADC_SINGLE_ENDED_INPUT_ADC3, 
    MADC_SINGLE_ENDED_INPUT_ADC4, 
    MADC_SINGLE_ENDED_INPUT_ADC5, 
    MADC_SINGLE_ENDED_INPUT_ADC6, 
    MADC_SINGLE_ENDED_INPUT_ADC7, 
    MADC_DIFF_INPUT_A0_A0_X10, 
    MADC_DIFF_INPUT_A1_A0_X10,    
    MADC_DIFF_INPUT_A0_A0_X200,    
    MADC_DIFF_INPUT_A1_A0_X200,   
    MADC_DIFF_INPUT_A2_A2_X10,     
    MADC_DIFF_INPUT_A3_A2_X10,     
    MADC_DIFF_INPUT_A2_A2_X200,    
    MADC_DIFF_INPUT_A3_A2_X200,   
    MADC_DIFF_INPUT_A0_A1_X1,      
    MADC_DIFF_INPUT_A1_A1_X1,     
    MADC_DIFF_INPUT_A2_A1_X1,     
    MADC_DIFF_INPUT_A3_A1_X1,     
    MADC_DIFF_INPUT_A4_A1_X1,     
    MADC_DIFF_INPUT_A5_A1_X1,     
    MADC_DIFF_INPUT_A6_A1_X1,     
    MADC_DIFF_INPUT_A7_A1_X1,     
    MADC_DIFF_INPUT_A0_A2_X1,     
    MADC_DIFF_INPUT_A1_A2_X1,     
    MADC_DIFF_INPUT_A2_A2_X1,     
    MADC_DIFF_INPUT_A3_A2_X1,     
    MADC_DIFF_INPUT_A4_A2_X1,     
    MADC_DIFF_INPUT_A5_A2_X1,     
    MADC_SINGLE_ENDED_INPUT_1_22_V,
    MADC_SINGLE_ENDED_INPUT_GND   
};

/*

    Function: MADC_voidADCInit

    Initialize ADC with initial configs

*/

void MADC_voidADCInit(void);

/*

    Function: MADC_voidStart

    Configures ADC

*/

void MADC_voidStartConversion (void);

/*

    Function: MADC_voidStop()

    Starts Conversion

*/

void MADC_voidStopConversion(void);

/*

    Function: MADC_u16GetConversion

    return conversion Result

*/

u16 MADC_u16GetConversion (u8 channel);

#endif
