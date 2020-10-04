/*
 * Copyright (C) 2020 Ethan Faust
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include "types.h"
#include "uart.h"
#include "mbox.h"
#include "ssp.h"

uint8_t get_board_serial(uint64_t *serial) {
    // get the board's unique serial number with a mailbox call
    mbox[0] = 8*4;                  // length of the message
    mbox[1] = MBOX_REQUEST;         // this is a request message

    mbox[2] = MBOX_TAG_GETSERIAL;   // get serial number command
    mbox[3] = 8;                    // buffer size
    mbox[4] = 8;
    mbox[5] = 0;                    // clear output buffer
    mbox[6] = 0;

    mbox[7] = MBOX_TAG_LAST;

    // send the message to the GPU and receive answer
    if (mbox_call(MBOX_CH_PROP)) {
        *serial = mbox[6];
        *serial = *serial << 32;
        *serial += mbox[5];
        return 0;
    }
    return 1;
}

void main() {
    uart_init();

    //uart_puts("Press any key to continue\n");
    uart_getc();

    uart_puts("Hello, world!\n");

    uint64_t serial = 0;
    uint8_t error_getting_serial = get_board_serial(&serial);
    if (error_getting_serial) {
        uart_puts("Unable to query serial!\n");
    } else {
        uart_puts("My serial number is: ");
        uart_hex(serial >> 32);
        uart_hex(serial & 0xFFFFFFFF);
        uart_puts("\n");
    }

    while(1) {
        uart_send(uart_getc());
    }
}
