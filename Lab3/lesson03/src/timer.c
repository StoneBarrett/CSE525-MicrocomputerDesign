#include "peripherals/timer.h"
#include "printf.h"
#include "utils.h"

const unsigned int interval = 200000;
unsigned int curVal = 0;

void timer_init(void) {
  // ? EXPLAIN WHAT THIS IS
  put32(TIMER_CTRL, ((1 << 28) | interval));
}

void handle_timer_irq(void) {
  curVal += interval;
  put32(TIMER_C1, curVal);
  put32(TIMER_CS, TIMER_CS_M1);

  printf("Timer interrupt received\n\r");
}
