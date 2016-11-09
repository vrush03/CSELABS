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
	if(pid==0)
	{
		printf("Child process:%d\n",getpid() );
	}
	else
	{
		printf("Parent process:%d\n",getpid() );
	}
	return 0;
}