#include<sys/ipc.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
	key_t key = ftok("/home/user/sosil2", 2);
	printf("%d\n", key);
	return 0;
}
