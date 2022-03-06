/*
 * system.h
 *
 * Created: 21-02-2022 11:22:30
 *  Author: yatharth
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

//--Configuration
#define  maxModules  2

uint8_t moduleNum = 1; // indexed at 1

typedef struct dataBuffer
{
	uint8_t address;
	uint8_t operation;
	uint16_t value[maxModules];
} dataBuffer;// __attribute__((packed));


void low_power_init(void)
{
	//PORTA_DIR = 0xff; // all pins as output to save power
	
	//PORTA.PIN0CTRL = PORT_ISC_INPUT_DISABLE_gc; //UPDI
	//PORTA.PIN1CTRL = PORT_ISC_INPUT_DISABLE_gc; //Analog in
	PORTA.PIN2CTRL = PORT_ISC_INPUT_DISABLE_gc;   // digital out to adc
	PORTA.PIN3CTRL = PORT_ISC_INPUT_DISABLE_gc;
	PORTA.PIN4CTRL = PORT_ISC_INPUT_DISABLE_gc;	
	PORTA.PIN5CTRL = PORT_ISC_INPUT_DISABLE_gc;
	PORTA.PIN6CTRL = PORT_ISC_INPUT_DISABLE_gc;	
	PORTA.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc;	
	
	PORTB.PIN0CTRL = PORT_ISC_INPUT_DISABLE_gc;
	PORTB.PIN1CTRL = PORT_ISC_INPUT_DISABLE_gc;
	//PORTB.PIN2CTRL = PORT_ISC_INPUT_DISABLE_gc;  //RX
	//PORTB.PIN3CTRL = PORT_ISC_INPUT_DISABLE_gc;  //TX		
}



#endif /* SYSTEM_H_ */