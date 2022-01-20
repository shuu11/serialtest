#ifndef DEFINE_H
#define DEFINE_H

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

#define mTIMER_EVE_MAX 4

enum
{
	eLED_STS_DEFAULT,
	eLED_STS_ERR,
	eLED_STS_MAX,
};

enum {
	eMAIN_MODE_DEFAULT,
	eMAIN_MODE_NORMAL,
	eMAIN_MODE_ERR,
	eMAIN_MODE_FUNCTION,
	eMAIN_MODE_MAX,
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