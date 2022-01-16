#ifndef _FUNC_H
#define _FUNC_H

void setupCtrl(void);

void mainCtrl(void);

void serialCtrl(void);
void serialCtrl_init(void);
static void serialCtrl_main(void);

void ledCtrl(void);
void ledCtrl_init(void);
static void ledCtrl_main(void);

#endif