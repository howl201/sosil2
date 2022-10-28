#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/tyoes.h>
#include<unistd.h>

#define MAX_SHM_SIZE 512

void signalHandler(int signum);
void myfunc(void);

key_t mykey=0;
int shmid=0;
int shmaddr=NULL;

int main(int argc, char const *argv[])
{
	mykey = ftok("myshmkey", 2);
	shmid=shmget(mykey, MAX_SHM_SIZE, IPC_CREAT | 0600);
	shmaddr=shmat(shmid, NULL, 0);

	signal(SIGINT, signalHandler);
	signal(SIGUSRq, signalHandler);

	while(1)
	{
		puts("Wait...");
		pause();
	}
	return 0
}
void sigHandler(int signum)
{
	struct shmid_ds buf;

	if (signum == SIGINT)
	{
		shmdt(shmaddr);
		shmctl(shmid, IPC_RMID, NULL);
		exit(0);
	}
	else if (signum == SIGUSR1)
	{
		myfunc();
	}
}
void myfunc(void)
{
	struct shmid_ds buf;
	int data=0;
	memcpy(&data, shmaddr, sizeof(int));
	printf("Receive: %d\n", data);

	data+=1;
	memcpy(shmaddr, &data, sizeof(int));
	printf("Sand: %d\n", data);

	shmctl(shmid, IPC_STAT, &buf);
	kill(buf.shm_lpid, SIGUSR1);
}

