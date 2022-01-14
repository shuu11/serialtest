#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"

#include "myproj.h"
#include "extern.h"

static CHAR cTxStr[] = "Start UART";
static CHAR cRxStr[6];

void vSerialCtrl(void)
{
	R_UART0_Send((uint8_t *)&cTxStr[0], sizeof(cTxStr));

	if (g_bRx0_fin)
	{
		g_bRx0_fin = mCLR;

		R_UART0_Receive((uint8_t *)&cRxStr[0], sizeof(cRxStr));
	}
}

void vSerialCtrl_Init(void)
{
	R_UART0_Receive((uint8_t *)&cRxStr[0],sizeof(cRxStr));
}
