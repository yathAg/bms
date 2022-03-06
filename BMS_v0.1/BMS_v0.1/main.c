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

uint16_t adcVal;
char adcStr[6] ;

typedef struct dataBuffer 
{
	uint8_t address;
	uint8_t test;
	uint16_t value[2];
} dataBuffer;// __attribute__((packed));

//struct dataBuffer data;

//uint8_t test = sizeof(data);

uint8_t SerialPacketReceiveBuffer[8+ sizeof(dataBuffer)];

void onPacketReceived(dataBuffer *receivebuffer)
{
	receivebuffer->address =2;
	//receivebuffer->test =2;
	receivebuffer->value[1] = 900;
}

int main(void)
{
	
	low_power_init();
  	USART0_init();
  	ADC0_init_sample();
	
	while (1)
  	{
		
	  	adcVal = ADC0_read_sample();
	  	
	  	adcVal = adcVal >> 4;
		  
		  //data.address = 1;
		  //data.value = adcVal;
	  	
		  //temp = adcdata;
		  
		  //*adcdata = adcVal;
		  
		 // adcdata +=1;
		  
		 // *adcdata = 5;
		//sprintf("%i\r\n" , adcVal);  //takes up huge chunk of code space.
		onPacketReceived((dataBuffer*)SerialPacketReceiveBuffer);
		
	  	USART0_sendString(SerialPacketReceiveBuffer);
	  	
		_delay_ms(1000);
		
		
  	}
}

