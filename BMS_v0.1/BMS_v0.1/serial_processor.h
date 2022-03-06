/*
 * serial_processor.h
 *
 * Created: 06-03-2022 20:00:08
 *  Author: yatharth
 */ 


#ifndef SERIAL_PROCESSOR_H_
#define SERIAL_PROCESSOR_H_

#include "uart_414.h"
#include <stddef.h>

uint8_t frameStart = 0b00001111;
uint8_t frameStop = 0b11110000;

uint8_t packetSize = 0;
uint8_t *receiveBufferPtr = NULL;

void begin(uint8_t _packetSize, uint8_t *_receiveBufferPtr)
{
	packetSize =_packetSize;
	receiveBufferPtr =_receiveBufferPtr;
}

void sendBuffer(uint8_t *str)
{

	USART0_sendChar(frameStart);
	
	for(size_t i = 0;i < packetSize; i++)
	{
		USART0_sendChar(str[i]);
	}
	
	USART0_sendChar(frameStop);
}



#endif /* SERIAL_PROCESSOR_H_ */