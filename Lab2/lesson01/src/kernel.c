#include "mini_uart.h"

void kernel_main(void) {
  // Question 1
  // mini_uart_init();
  // Question 2
  uart_init();
  uart_send_string("Hello, UART world!\r\n");

  while (1) {
    uart_send(uart_recv());
  }
}
