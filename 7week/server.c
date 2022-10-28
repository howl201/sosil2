#include "MyMsg.h"
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg,h>
#include<sys/tyoes.h>

void signalHandler(int signum);
int calculate(Calc calc);

key_t mykeyy=0;
int mian(int argc, char const *argv[])
{
	MsgCalc msgCalc;
	MsgRslt mseRslt;

	mykey = ftok("mymsgkey", 1);
	mspid = msgget(mykey, IPC_CREAT | 0600);

	signal(SIGINT, signalHandler);

