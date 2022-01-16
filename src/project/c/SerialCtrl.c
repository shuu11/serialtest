#include <string.h>

#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"

#include "myproj.h"
#include "extern.h"

static CHAR txStr[] = "Start UART";
static CHAR rxStr[6];

void serialCtrl(void)
{
	serialCtrl_main();
}

static void serialCtrl_main(void)
{
	R_UART0_Send((uint8_t *)&txStr[0], (uint16_t)ARRAY_LENGTH(txStr));

	if (g_rx0_fin)
	{
		g_rx0_fin = CLR;

		R_UART0_Receive((uint8_t *)&rxStr[0], (uint16_t)ARRAY_LENGTH(rxStr));
	}
}

void serialCtrl_init(void)
{
	memset(rxStr, 0, ARRAY_LENGTH(rxStr));
	R_UART0_Receive((uint8_t *)&rxStr[0], (uint16_t)ARRAY_LENGTH(rxStr));
}
