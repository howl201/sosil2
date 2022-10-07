#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int var = 10;
	pid_t pid = 0;
	int status = 0;
	
	printf("pid: %d\n", getpid());

	pid = fork();

	if(pid == -1)
	{
		perror("fork error");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("im child my pid : %d\n", getpid());
		printf("im child my parent pid: %d\n", getppid());
		var += 1;
	}
	else
	{
			printf("im parent my child pid: %d\n ", pid);

			wait(&status);
			printf("im parent my child is exited\n");
	}
	printf("my pid is %d, var is %d\n", getpid(), var);

	return 0;
}
