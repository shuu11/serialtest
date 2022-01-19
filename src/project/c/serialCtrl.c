//----------------------------------------------------------------------
//  pragma
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//  include
//----------------------------------------------------------------------
#include <string.h>

#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"

#include "myproj.h"
#include "extern.h"

//----------------------------------------------------------------------
//  static variable
//----------------------------------------------------------------------
static BYTE serialSts;
static CHAR txStr[] = "Start UART";
static CHAR rxStr[6];

//----------------------------------------------------------------------
//  function table
//----------------------------------------------------------------------
static void fpFunc01(void);
static void fpFunc02(void);
static void fpFunc03(void);

static FUNCPTR fpTable[eSERIAL_STS_MAX] = {
		// イベント
		fpFunc01, //	デフォルト
		fpFunc02, //	送信
		fpFunc03, //	受信
};


//----------------------------------------------------------------------
//  function
//----------------------------------------------------------------------
void serialCtrl(void)
{
	fpTable[serialSts]();
}

static void fpFunc01(void)
{
	serialSts = eSERIAL_STS_SEND;
}

static void fpFunc02(void)
{
	R_UART0_Send((uint8_t *)&txStr[0], (uint16_t)mARRAY_LENGTH(txStr));

	serialSts = eSERIAL_STS_RECEIVE;
}

static void fpFunc03(void)
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

/************************************************************************/
/*  END OF FILE																													*/
/************************************************************************/
