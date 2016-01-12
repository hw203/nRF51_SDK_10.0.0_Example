#include "user_uart.h"
#include "app_trace.h"

#define UART_TX_BUF_SIZE           256                                /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE           1                                  /**< UART RX buffer size. */


void uart_error_handle(app_uart_evt_t * p_event)
{
    if (p_event->evt_type == APP_UART_COMMUNICATION_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_communication);
    }
    else if (p_event->evt_type == APP_UART_FIFO_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_code);
    }
}

/**@brief Function for initializing the UART.
 */
void uart_init(void)
{
    uint32_t err_code;

    const app_uart_comm_params_t comm_params =
       {
           11,
           9,
           8,
           1,
		   APP_UART_FLOW_CONTROL_DISABLED,
           false,
           UART_BAUDRATE_BAUDRATE_Baud38400
       };

    APP_UART_FIFO_INIT(&comm_params,
                          UART_RX_BUF_SIZE,
                          UART_TX_BUF_SIZE,
                          uart_error_handle,
                          APP_IRQ_PRIORITY_LOW,
                          err_code);

    APP_ERROR_CHECK(err_code);

    app_trace_init();
}
