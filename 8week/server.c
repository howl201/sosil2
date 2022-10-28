#include"MySem.h"
#include"MyShm.h"
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/types.h>

void signalHandler(int signum);

int shmid = 0;
int *shmaddr = NULL;

int semidServ = 0;
int semidClnt = 0;
int main(int argc, char const *argv[])
{
	int req=0;
	int res=0;
	union semun semunBuf;
	shmid = creatShm(MY_SHM_KEY);//creat shared memory
	shmaddr = shmat(shmid, NULL, 0);//attach
	semidServ = creatSem(MY_SEM_SERV_KEY);//creat semapore 1
	semunBuf.val = 0;
	semctl(semidServ, 0, SETVAL, semunBuf);//save semunBuf index 0 server (val 1)
	semClnt = creatSem(MY_SEM_CLNT_KEY);
	semunBuf.val = 1;
	semctl(semidClnt, 0, SETVAL, semunBuf);//save semunBuf index 0 client (val 0)
	signal(SIGINT, signalHandler);
	while(1)
	{
		puts("Wait...");

		lockSem(semidServ);//lock server
		memcpy(&req, shmaddr, sizeof(int));//pull value at shared memory
		res = req + 1;
		memcpy(shmaddr, &res, sizeof(int));//push value at shared memory
		unlockSem(semidClnt);//unlock client

		printf("Request: %d\n", req);
		printf("response: %d\n", res);
		fflush(stdout);
	}
	return 0;
}
void signalHandler(int signum)
{
	if (signum == SIGINT)
	{
		closeSem(semidClnt);
		closeSem(semidServ);

		shmdt(shmaddr);
		closeShm(shmid);

		exit(0);
	}
}
