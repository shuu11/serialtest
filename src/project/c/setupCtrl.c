#include "r_cg_macrodriver.h"

#include "myproj.h"
#include "extern.h"

void setupCtrl(void)
{
	serialCtrl_init();

	PO_LED1 = LED_ON;
	PO_LED2 = LED_ON;
}