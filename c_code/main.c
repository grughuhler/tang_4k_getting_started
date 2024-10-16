/* Copyright 2024 Grug Huhler.  License SPDX BSD-2-Clause.
 *
 * Simple program for Cortex M3 on Tang Nano 4K
 */

#include "uart.h"
#include "gpio.h"

int main()
{
  unsigned char val = 1;
  char ch;
  
  gpio_init();
  gpio_set_dir(0, GPIO_OUT);
  gpio_out_set_val(0, val);

  uart_init(UART0, 234); /* 27e6 / 115200 */
  uart_puts(UART0, "Hello, world!\r\nCPUID: ");
  uart_print_hex(UART0, *(unsigned int *) 0xE000ED00);
  uart_puts(UART0, "\r\nType some characters\r\n");

  while (1) {
    ch = uart_getchar(UART0);
    uart_puts(UART0, "You pressed ");
    uart_putchar(UART0, ch);
    uart_puts(UART0, " and button is ");
    if (gpio_in_get_val(1)) uart_puts(UART0, "not ");
    uart_puts(UART0, "pressed\r\n");
    val = 1 - val;
    gpio_out_set_val(0, val);
  }
  
  return 0;
}
