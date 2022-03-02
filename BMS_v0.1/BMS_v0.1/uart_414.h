/*
 * uart_414.h
 *
 * Created: 16-02-2022 16:22:48
 *  Author: yatharth
 */ 


#ifndef UART_414_H_
#define UART_414_H_

#define USART0_BAUD_RATE(BAUD_RATE) (   (float)(F_CPU * 64)/ (16 * (float)BAUD_RATE)      )

void USART0_init(void)
{
	PORTB_DIR |= PIN2_bm;       // Tx - Output(1)
	//PORTB_DIR &= ~PIN3_bm;	// Rx - Input(0)
	
	USART0.BAUD =(uint16_t)USART0_BAUD_RATE(9600);
	
	USART0.CTRLB |= USART_TXEN_bm; //enabling the transmit line
	
}

void USART0_sendChar(char c)
{
	while(!(USART0.STATUS & USART_DREIE_bm))
	{
		;
	}
	USART0.TXDATAL = c;
}

void USART0_sendString(char *str)
{
	for(size_t i = 0;i <strlen(str); i++)
	{
		USART0_sendChar(str[i]);
	}
}




#endif /* UART_414_H_ */