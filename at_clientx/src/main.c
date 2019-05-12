/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <sys_def.h>

#include <zephyr.h>
#include <stdio.h>
#include <uart.h>
#include <string.h>
#include <at_host.h>

void main(void)
{
	int err;

	printf("The AT Ready.\n");

	err = at_host_init(CONFIG_AT_HOST_UART, CONFIG_AT_HOST_TERMINATION);

	if (err != 0) {
		printf("ERROR: AT Host not initialized\r\n");
		return;
	}

	while (1) {
          at_host_process();
	}

        printf("ERROR: unexpected exit\r\n");
}
