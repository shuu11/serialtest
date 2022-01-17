#include <string.h>

#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"

#include "myproj.h"
#include "extern.h"

static void serialfunc01(void);
static void serialfunc02(void);
static void serialfunc03(void);

static BYTE serialSts;
static CHAR txStr[] = "Start UART";
static CHAR rxStr[6];

FUNCPTR fpSerial[eSERIAL_STS_MAX] = {
		// デフォルト
		serialfunc01, //	デフォルト
		serialfunc02, //	送信
		serialfunc03, //	受信
};

void serialCtrl(void)
{
	fpSerial[serialSts]();
}

static void serialfunc01(void)
{
	serialSts = eSERIAL_STS_SEND;
}

static void serialfunc02(void)
{
	R_UART0_Send((uint8_t *)&txStr[0], (uint16_t)mARRAY_LENGTH(txStr));

	serialSts = eSERIAL_STS_RECEIVE;
}

static void serialfunc03(void)
{
	if (g_rx0_fin)
	{
		g_rx0_fin = mCLR;

		R_UART0_Receive((uint8_t *)&rxStr[0], (uint16_t)mARRAY_LENGTH(rxStr));

		serialSts = eSERIAL_STS_DEFAULT;
	}
}

void serialCtrl_init(void)
{
	memset(rxStr, 0, mARRAY_LENGTH(rxStr));

	R_UART0_Receive((uint8_t *)&rxStr[0], (uint16_t)mARRAY_LENGTH(rxStr));

	serialSts = eSERIAL_STS_DEFAULT;
}
