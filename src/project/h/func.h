#ifndef FUNC_H
#define FUNC_H

void interrupt_timer(void);

void setupCtrl(void);

void mainCtrl(void);

void serialCtrl(void);
void serialCtrl_init(void);

static void serialCtrl_tx(void);
static void serialCtrl_rx(void);

void ledCtrl(void);
void ledCtrl_init(void);

#endif