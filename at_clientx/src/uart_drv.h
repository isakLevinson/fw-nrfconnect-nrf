#ifndef _UART_H_
#define _UART_H_

#include <sys_def.h>

BOOLOP    UART_init(UINT8 uart_id);
BOOLOP    UART_get(UINT8* o_pCh);


#endif // _UART_H_