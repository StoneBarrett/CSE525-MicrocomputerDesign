#include "peripherals/uart.h"
#include "peripherals/gpio.h"
#include "utils.h"

void uart_send(char c) {
  while (get32(UART_FR) & 0x20) {
  }                  // wait if TX is full
  put32(UART_DR, c); // when TX is empty, send next char
}

char uart_recv(void) {
  while (get32(UART_FR) & 0x10) {
  }                               // wait if RX is empty
  return (get32(UART_DR) & 0xFF); // get recived char
}

void uart_send_string(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    uart_send((char)str[i]);
  }
}

void uart_init(void) {
  unsigned int selector;

  // selector |= 4 for alt0 (uart)

  selector = get32(GPFSEL1);
  selector &= ~(7 << 12); // clean gpio14
  selector |= 4 << 12;    // set alt0 for gpio14
  selector &= ~(7 << 15); // clean gpio15
  selector |= 4 << 15;    // set alt0 for gpio15
  put32(GPFSEL1, selector);

  put32(GPPUD, 0);
  delay(150);
  put32(GPPUDCLK0, (1 << 14) | (1 << 15));
  delay(150);
  put32(GPPUDCLK0, 0);

  put32(UART_CR, 0); // Disable TX and RX so we can setup

  put32(UART_IBRD,
        26); // Set integer baud rate to 115200 given uart clock of 48Mhz
  put32(UART_FBRD, 3);       // Set baud rate decimal precision
  put32(UARTLCR_LCRH, 0x60); // Set 8 bit word length

  put32(UART_CR, 0x301); // Enable TX and RX
}
