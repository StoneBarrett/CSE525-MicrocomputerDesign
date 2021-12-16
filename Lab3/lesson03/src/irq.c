#include "peripherals/irq.h"
#include "entry.h"
#include "peripherals/mini_uart.h"
#include "peripherals/timer.h"
#include "printf.h"
#include "timer.h"
#include "utils.h"

const char *entry_error_messages[] = {
    "SYNC_INVALID_EL1t",   "IRQ_INVALID_EL1t",
    "FIQ_INVALID_EL1t",    "ERROR_INVALID_EL1T",

    "SYNC_INVALID_EL1h",   "IRQ_INVALID_EL1h",
    "FIQ_INVALID_EL1h",    "ERROR_INVALID_EL1h",

    "SYNC_INVALID_EL0_64", "IRQ_INVALID_EL0_64",
    "FIQ_INVALID_EL0_64",  "ERROR_INVALID_EL0_64",

    "SYNC_INVALID_EL0_32", "IRQ_INVALID_EL0_32",
    "FIQ_INVALID_EL0_32",  "ERROR_INVALID_EL0_32"};

void enable_interrupt_controller() {
  // ? EXPLAIN WHAT THIS IS
  signed int interrupt_enable = get32(TIMER_CTRL);
  put32(TIMER_CTRL, (interrupt_enable | (1 << 29)));
}

void show_invalid_entry_message(int type, unsigned long esr,
                                unsigned long address) {
  printf("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr,
         address);
}

void handle_irq(void) {
  unsigned int irq_uart = get32(AUX_IRQ);
  if (irq_uart & (1 << 0))
    handle_uart_irq();
}
