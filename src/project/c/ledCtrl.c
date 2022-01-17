#include "r_cg_macrodriver.h"

#include "myproj.h"
#include "extern.h"

static void ledfunc__(void);
static void ledfunc01(void);

static BYTE ledSts;

FUNCPTR fpLED[eLED_STS_MAX] = {
		// イベント
		ledfunc01, //	0.デフォルト
		ledfunc__, //	1.エラー
};

void ledCtrl(void)
{
	fpLED[ledSts]();
}

static void ledfunc__(void)
{
	__nop();
}

static void ledfunc01(void)
{
	mPO_LED1 = mLED_ON;
	mPO_LED2 = mLED_ON;
}

void ledCtrl_init(void)
{
	ledSts = eLED_STS_DEFAULT;

	mPO_LED1 = mLED_ON;
	mPO_LED2 = mLED_ON;
}
