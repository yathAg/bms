/*
 * adc_414.h
 *
 * Created: 16-02-2022 16:28:24
 *  Author: yatharth
 */ 


#ifndef ADC_414_H_
#define ADC_414_H_

#define v_measure_pin (2)

uint16_t ADC0_read_sample(void)
{
	PORTA_OUT |= (1<<v_measure_pin);
	
	ADC0.COMMAND = ADC_STCONV_bm;
	
	while(!(ADC0.INTFLAGS & ADC_RESRDY_bm))
	{
		;
	}
	
	ADC0.INTFLAGS = ADC_RESRDY_bm;
	
	PORTA_OUT &= ~(1<<v_measure_pin);
	
	return ADC0.RES;
	
}

void ADC0_init_sample(void)
{
	PORTA_DIR = (1<<v_measure_pin);	
	
	PORTA.PIN1CTRL = PORT_ISC_INPUT_DISABLE_gc;  //disable input buffer
	PORTA.PIN1CTRL &= ~PORT_PULLUPEN_bm;   // re-disable pull up
	
	VREF.CTRLA = VREF_ADC0REFSEL_2V5_gc;   // internal reference to 2.50v
	
	ADC0.CTRLA = ADC_ENABLE_bm | ADC_RESSEL_10BIT_gc; /* ADC Enable: enabled */
	
	ADC0.CTRLC = ADC_REFSEL_INTREF_gc | ADC_PRESC_DIV4_gc ;    // internal reference and clock divided by 5
	
	ADC0.MUXPOS = ADC_MUXPOS_AIN1_gc; // on pin pa1
	
	ADC0.CTRLB = ADC_SAMPNUM_ACC16_gc; // 16 samples
	
}




#endif /* ADC_414_H_ */