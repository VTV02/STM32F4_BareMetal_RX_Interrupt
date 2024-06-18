
#ifndef UART_RX_H_
#define UART_RX_H_

void uart2_txrx_init(void);
void uart2_write(int ch);
void write_string(char* word);
char uart2_read(void);
void uart2_rx_interrupt_init(void);

#endif /* UART_RX_H_ */
