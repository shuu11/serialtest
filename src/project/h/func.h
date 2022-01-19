#ifndef _FUNC_H
#define _FUNC_H

void interrupt_timer(void);

void setupCtrl(void);

void mainCtrl(void);

void serialCtrl(void);
void serialCtrl_init(void);

void ledCtrl(void);
void ledCtrl_init(void);

#endif