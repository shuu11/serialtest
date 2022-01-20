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
//  define
//----------------------------------------------------------------------
#define mSERIAL_CNT 500

//----------------------------------------------------------------------
//  static variable
//----------------------------------------------------------------------
static CHAR txStr[] = "Start UART";
static CHAR rxStr[6];

static WORD serialCnt;

//----------------------------------------------------------------------
//  function
//----------------------------------------------------------------------
void serialCtrl(void)
{
	serialCtrl_tx();
	serialCtrl_rx();
}

static void serialCtrl_tx(void)
{
	serialCnt++;

	if (serialCnt >= mSERIAL_CNT)
	{
		serialCnt = 0;

		R_UART0_Send((uint8_t *)&txStr[0], (uint16_t)mARRAY_LENGTH(txStr));
	}
}

static void serialCtrl_rx(void)
{
	if (g_rx0_fin)
	{
		g_rx0_fin = mCLR;

		R_UART0_Receive((uint8_t *)&rxStr[0], (uint16_t)mARRAY_LENGTH(rxStr));
	}
}

void serialCtrl_init(void)
{
	R_UART0_Receive((uint8_t *)&rxStr[0], (uint16_t)mARRAY_LENGTH(rxStr));
}

/************************************************************************/
/*  END OF FILE																													*/
/************************************************************************/
