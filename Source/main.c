#include <stdio.h>
#include<stdint.h>
#include <uart_rx.h>
#include<stm32f411xe.h>
#include <uart_rx.h>
#define GPIOAEN			(1U<<0)
#define SR_RXNE			(1U<<5)
void USART2_IRQHandler(void);
static void uart_callback();

char key;
int main(void)
{
	RCC->AHB1ENR|=(1U<<0);
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);
	uart2_rx_interrupt_init();
	while(1)
	{

	}
}

static void uart_callback()
{
		/*Do something*/
			key=USART2->DR;
			if(key=='1')
			{
				GPIOA->ODR|=(1U<<0);
			}
			else{GPIOA->ODR&=~(1U<<0);}
}

void USART2_IRQHandler(void)
{
	/*Check if RXNE is set */
	if(USART2->SR & SR_RXNE)
	{
		uart_callback();
	}

}
