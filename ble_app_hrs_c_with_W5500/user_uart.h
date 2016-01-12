#ifndef USER_UART_H__
#define USER_UART_H__

#include "app_uart.h"

void uart_error_handle(app_uart_evt_t * p_event);
void uart_init(void);


#endif
