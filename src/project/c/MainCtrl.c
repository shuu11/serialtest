#include "r_cg_macrodriver.h"
#include "r_cg_wdt.h"

#include "myproj.h"
#include "extern.h"

void vMainCtrl(void)
{
	if (g_b500ms)
	{
		g_b500ms = mCLR;
		R_WDT_Restart();

		vSerialCtrl();
	}
}