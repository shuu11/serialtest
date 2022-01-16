#include "r_cg_macrodriver.h"

#include "myproj.h"
#include "extern.h"

void ledCtrl(void)
{
	ledCtrl_main();
}

static void ledCtrl_main(void)
{
	PO_LED1 = LED_ON;
	PO_LED2 = LED_ON;
}

void ledCtrl_init(void)
{
	PO_LED1 = LED_ON;
	PO_LED2 = LED_ON;
}
