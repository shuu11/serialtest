#ifndef _DEFINE_H
#define _DEFINE_H

typedef signed char CHAR;
typedef unsigned char BYTE;
typedef signed short SHORT;
typedef unsigned short WORD;
typedef signed long LONG;
typedef unsigned long DWORD;
typedef void (*FUNCPTR)(void);

#define mON 1
#define mOFF 0
#define mSET 1
#define mCLR 0
#define mLED_ON 0
#define mLED_OFF 1

#define mARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

enum
{
	eLED_STS_DEFAULT,
	eLED_STS_ERR,
	eLED_STS_MAX,
};

enum
{
	eSERIAL_STS_DEFAULT,
	eSERIAL_STS_SEND,
	eSERIAL_STS_RECEIVE,
	eSERIAL_STS_MAX,
};

#define mPO_LED1 P6_bit.no2
#define mPO_LED2 P6_bit.no3

#endif