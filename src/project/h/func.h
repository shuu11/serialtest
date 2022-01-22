#ifndef FUNC_H
#define FUNC_H

// interrupt_timer
void interrupt_timer(void);

// ledCtrl
void ledCtrl(void);
void ledCtrl_init(void);

// mainCtrl
void mainCtrl(void);

// serialCtrl
void serialCtrl(void);
void serialCtrl_init(void);
static void serialCtrl_tx(void);
static void serialCtrl_rx(void);

// setupCtrl
void setupCtrl(void);




#endif