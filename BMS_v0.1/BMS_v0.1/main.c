/*
 * BMS_v0.1.cpp
 *
 * Created: 16-02-2022 15:35:56
 * Author : yatharth
 */ 

#define F_CPU 2666666UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "adc_414.h"
#include "uart_414.h"
#include "system.h"
#include "serial_processor.h"

FUSES = {
	.WDTCFG     = FUSE_WDTCFG_DEFAULT,
	.BODCFG     = FUSE_BODCFG_DEFAULT,
	.OSCCFG     = FREQSEL_16MHZ_gc,     //Select 16MHz OSC
	.TCD0CFG    = FUSE_TCD0CFG_DEFAULT,
	.SYSCFG0    = FUSE_SYSCFG0_DEFAULT,
	.SYSCFG1    = FUSE_SYSCFG1_DEFAULT,
	.APPEND     = FUSE_APPEND_DEFAULT,
	.BOOTEND    = FUSE_BOOTEND_DEFAULT,
};

//Global variables
uint16_t adcVal;
uint8_t SerialBuffer[4+ sizeof(dataBuffer)];





void makeStruct(dataBuffer *receivebuffer)
{
	uint8_t moduleIndex = moduleNum-1;
	receivebuffer->address =moduleNum;
	
	receivebuffer->value[moduleIndex] = adcVal;
	
	
}

int main(void)
{
	low_power_init();
  	USART0_init();
  	ADC0_init_sample();
	
	begin(sizeof(dataBuffer),SerialBuffer);
	
	
	while (1)
  	{
		
	  	adcVal = ADC0_read_sample();
	  	adcVal = adcVal >> 4;
		  
		makeStruct((dataBuffer*)SerialBuffer);
		
	  	sendBuffer(SerialBuffer);
	  	
		_delay_ms(1000);	
  	}
}

