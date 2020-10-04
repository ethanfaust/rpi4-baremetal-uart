#include "uart.h"

__attribute__((weak,noreturn)) void __stack_chk_fail(void)
{
    uart_puts("[PANIC] Stack overflow detected!\n");
    while (1);
}
