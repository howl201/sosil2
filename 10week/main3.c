#include<pthread.h>
#include<stdio.h>
 void *myThread1(void *arg);
 void *myThread2(void *arg);
 void cleanupHandler(void *arg);

 pthread_mutex_t mutex;
 int sharedNum = 0;

 int main(int argc, char const *argv[])
{
	pthread_t tid1 = 0;
	pthread_t tid2 = 0;
	int *status;

	pthread_mutex_init(&mutex, NULL);// create mutex

	if(pthread_create(&tid1, NULL, myThread1, NULL))//create thread1 (myThread1 function)
	{
		perror("pthread)create error");
		goto END;
	}
	if(pthread_create(&tid2, NULL, myThread2, NULL))//create thread2 (myThread2 function)
	{
		perror("pthread_creat() error");
		goto END;
	}
	pthread_join(tid1, (void **)&status);//wait
	pthread_join(tid2, (void **)&status);//wait
END:
	pthread_mutex_destroy(&mutex);//destroy mutex

	return 0;
}
void *myThread1(void *arg)
{
	int i=0; 
	int status=0;
	pthread_cleanup_push(cleanupHandler, "Thread1");//unlock function push

	pthread_mutex_lock(&mutex);// lock
	puts("Thread 1");
	for(i = 0; i<5; ++i)
	{
		sharedNum -= i;
		printf("%d ", sharedNum);
	}
	puts("");

	pthread_cleanup_pop(1);//unlock function execute and pop
	pthread_exit((void *)&status);//exit
}
void *myThread2(void *arg)//same to myThread2
{
	int i=0; 
	int status=0;
	pthread_cleanup_push(cleanupHandler, "Thread2");

	pthread_mutex_lock(&mutex);
	puts("Thread 1");
	for(i = 0; i<5; ++i)
	{
		sharedNum += i;
		printf("%d ", sharedNum);
	}
	puts("");

	pthread_cleanup_pop(1);
	pthread_exit((void *)&status);
}
void cleanupHandler(void *arg)
{
	pthread_mutex_unlock(&mutex);//unlock
	printf("Cleanup: %s\n", (char *)arg);
}
