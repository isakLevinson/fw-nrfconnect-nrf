/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <sys_def.h>
#include "dbgprint.h"
#include "dbgTree.h"
#include "dbgMenus.h"
#include "fifo.h"
#include "uart_drv.h"

#include <zephyr.h>
#include <stdio.h>
#include <uart.h>
#include <string.h>
#include <at_host.h>

FIFO          f1;
FIFO_CONFIG   cfg1;

void main(void)
{
        BOOLOP  retVal;
	int err;

        //UART_init(0);
        DBG_MENU_init();

	printf("The AT Ready.\n");

        UART_init(CONFIG_AT_HOST_UART);

	//err = at_host_init(CONFIG_AT_HOST_UART, CONFIG_AT_HOST_TERMINATION);

	while (1) {
          UINT8 c;
          //at_host_process();
          retVal = UART_get(&c);
          if (TRUE == retVal) {
            DBG_MENU_handler(c);
          }
	}

        printf("ERROR: unexpected exit\r\n");
}
