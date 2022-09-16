#include<fcntl.h>
#include<pwd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

void myError(const char *msg);
void fileType(const struct stat *fileInfo);
void fileMode(const struct stat *fileInfo);

int main(int argc, char const *argv[])
{
	struct stat fileInfo;
	struct passwd *userInfo;

	if(argc !=2)
	{
		printf("Usage: %s [pathname]\n", argv[0]);
		exit(-1);
	}
	printf("File name of path: %s\n", argv[1]);
	if(stat(argv[1], &fileInfo)==-1)
		myError("stat() error!");
	printf("File type: ");
	fileType(&fileInfo);

	printf("File permission: ");
	fileMode(&fileInfo);

	printf("File size: %ld\n", fileInfo.st_size);

	userInfo=getpwuid(fileInfo.st_uid);
	printf("Owner name: %s\n", userInfo->pw_name);

	return 0;
}
void myError(const char *msg)
{
	perror(msg);
	exit(-1);
}
void fileType(const struct stat *fileInfo)
{
	if (S_ISREG(fileInfo->st_mode))
		printf("Regular File");
	else if(S_ISDIR(fileInfo->st_mode))
		printf("Dir");
	else if (S_ISLNK(fileInfo->st_mode))
		printf("link");
	else if(S_ISSOCK(fileInfo->st_mode))
		printf("socket");
	else if(S_ISFIFO(fileInfo->st_mode))
		printf("fifo");
	else if(S_ISCHR(fileInfo->st_mode))
		printf("character");
	else if(S_ISBLK(fileInfo->st_mode))
		printf("block");
	else if(S_TYPEISMQ(fileInfo))
		printf("message queue");
	else if(S_TYPEISSEM(fileInfo))
		printf("semaphore");
	else if(S_TYPEISSHM(fileInfo))
		printf("shared meory");
	puts("");
}

void fileMode(const struct stat *fileInfo)
{
		if (S_IRUSR & fileInfo->st_mode)
				printf("r");
		else 
			printf("-");
		if (S_IWUSR & fileInfo->st_mode)
				printf("w");
		else 
				printf("-");
		if (S_IXUSR & fileInfo->st_mode)
				printf("x");
		else 
				printf("-");
		
		if (S_IRGRP & fileInfo->st_mode)
				printf("r");
		else 
				printf("-");
		if (S_IWGRP & fileInfo->st_mode)
				printf("w");
		else 
				printf("-");
		if (S_IXGRP & fileInfo->st_mode)
				printf("x");
		else 
				printf("-");
		
		if (S_IROTH & fileInfo->st_mode)
				printf("r");
		else 
				printf("-");
		if (S_IWOTH & fileInfo->st_mode)
				printf("w");
		else 
				printf("-");
		if (S_IXOTH & fileInfo->st_mode)
				printf("x");
		else 
				printf("-");
		puts("");
}
