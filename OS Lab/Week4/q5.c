#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int s;
	pid_t pid;
	pid=fork();
	if(pid!=0)
	{
		sleep(15);
		printf("Parent here:%d\n",getpid());
	}
	else
	{
		printf("Child here:%d\n",getpid());
		exit(20);
	}
	return 0;
}