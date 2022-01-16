#ifndef _DEFINE_H
#define _DEFINE_H

typedef signed char CHAR;
typedef unsigned char BYTE;
typedef signed short SHORT;
typedef unsigned short WORD;
typedef signed long LONG;
typedef unsigned long DWORD;

#define ON 1
#define OFF 0
#define SET 1
#define CLR 0
#define LED_ON 0
#define LED_OFF 1

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

#define PO_LED1 P6_bit.no2
#define PO_LED2 P6_bit.no3

#endif