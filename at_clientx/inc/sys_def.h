/*
* sys_def.h
*/

#ifndef SYS_DEF_H_
#define SYS_DEF_H_

#include "conventions.h"
#include <string.h>
#include "memory.h"

#define VERSION			"0.62"
#define PROMPT			"LTE"
#define MAX_PROMPT_SIZE	8

#define PROJ_OPT_FEATURE_GEN_DEBUG_CODE
#define PROJ_OPT_FEATURE_GEN_DEBUG_MENUS
#define PROJ_OPT_FEATURE_GEN_DEBUG_PRINTS
#define DBG_PRINT_MAX_LINE_SIZE			256
#define DBG_MENU_MAX_LINE_SIZE			512
#define DBG_MENU_MAX_ARGS				128
#define DBG_MENU_MAX_PATH_DEPTH			8
#define DBG_MENU_HISTORY_SIZE			32
#define DBG_PARSE_SPACE_PROTECT_CHAR	0xff
#define DBG_MENU_USE_AUTOCOMPLETE
#define DBG_PRINT_USE_COLORS
#define DBG_PRINT_LINUX_STYLE
#define MAX_NUM_POSSIBLE_ENTRIES		32
#define DEFAULT_TERMINAL_WIDTH			128

#define MEMCMP	memCmp
#define MEMCPY	memCpy
#define MEMSET	memSet
#define STRCPYN	strCpyN

#define ID()
#define IE()

#endif /* SYS_DEF_H_ */
