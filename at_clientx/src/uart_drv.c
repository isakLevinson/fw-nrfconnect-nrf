/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <sys_def.h>
#include "uart_drv.h"
#include "fifo.h"


#include <logging/log.h>
#define LOG_DOMAIN at_host
#define LOG_LEVEL CONFIG_LOG_AT_HOST_LEVEL
LOG_MODULE_REGISTER(LOG_DOMAIN);

#include <at_host.h>
#include <zephyr.h>
#include <stdio.h>
#include <uart.h>
#include <net/socket.h>
#include <string.h>

#define INVALID_DESCRIPTOR -1

UINT8 fifoRxBuf[256];
FIFO  fifoRx;

static struct device *uart_dev;

static void isr(struct device *x)
{
    UINT16  size;
    UINT8   buf[32];
    
    uart_irq_update(x);

	if (uart_irq_rx_ready(x)) {
		size = uart_fifo_read(x, buf, sizeof(buf));
                FIFO_push(&fifoRx, buf, size);
	}
}

static int at_uart_init(char *uart_dev_name)
{
	int err;

	uart_dev = device_get_binding(uart_dev_name);
	if (uart_dev == NULL) {
		LOG_ERR("Cannot bind %s\n", uart_dev_name);
		return EINVAL;
	}
	err = uart_err_check(uart_dev);
	if (err) {
		LOG_ERR("UART check failed\n");
		return EINVAL;
	}

	uart_irq_rx_enable(uart_dev);
	uart_irq_callback_set(uart_dev, isr);
	return err;
}

BOOLOP  UART_get(UINT8* o_pCh)
{
  BOOLOP  retVal;
  UINT8   c;

  retVal = FIFO_pop(&fifoRx, &c, 1);
  if (FALSE == retVal) {
    return FALSE;
  }


  return TRUE;
}


BOOLOP UART_init(UINT8 uart_id)
{
	char *uart_dev_name;

        FIFO_CONFIG fifoRxCfg = {0};

	int err;
	/* Choosing the termination mode */

	/* Choose which UART to use */
	switch (uart_id) {
	case UART_0:
		uart_dev_name = "UART_0";
		break;
	case UART_1:
		uart_dev_name = "UART_1";
		break;
	case UART_2:
		uart_dev_name = "UART_2";
	default:
		LOG_ERR("Unknown UART instance %d", uart_id);
		return -EINVAL;
	}

        fifoRxCfg.type = FIFO_MSG_TYPE_STREAM;
        fifoRxCfg.pBuf = fifoRxBuf;
        fifoRxCfg.size = sizeof(fifoRxBuf);
        fifoRxCfg.erasePopped = FALSE;

        FIFO_init(&fifoRx, &fifoRxCfg);
        err = at_uart_init(uart_dev_name);
	return TRUE;
}
