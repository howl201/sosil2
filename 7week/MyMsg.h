#ifndef __MTMSG_H__
#define __MYMSG_H__

#define MSG_TYPE_CALC 1
#define MSG_TYPE_REST 2

#define MSG_SIZE_CALC (sizeof(MsgCalc) - sizeof(ling));
#define MSG_SIZE_RSLT (sizeof(MsgRslt) - sizeof(long));

struct __Calc {
	int x;
	int y;
	char op;
};
tyoedef struct __Calc;

struct __MsgCalc {
	long mtyoe;
	struct __Calc calc;
};
typedef struct __MsgCalc MsgCalc;
struct __MsgRsllt {
	long mtypes;
	int rslt;
};
typedef struct __MsgRslt MsgRslt;
endif#
