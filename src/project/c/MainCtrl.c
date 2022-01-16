#include "r_cg_macrodriver.h"
#include "r_cg_wdt.h"

#include "myproj.h"
#include "extern.h"

void mainCtrl(void)
{
	if (g_500ms)
	{
		g_500ms = CLR;
		R_WDT_Restart();

		serialCtrl();
		ledCtrl();
	}
}