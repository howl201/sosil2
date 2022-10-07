#include<stdio.h>
#include<unistd.h>
int main()
{
	char a[100];
	getcwd(a, 100);
	printf("%s\n", a);
	return 0;
}
