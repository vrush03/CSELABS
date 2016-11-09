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
	if(pid==-1)
		printf("Child Not created\n");
	else if(pid==0)
		printf("\nI am the Child\n");
	else
		{
			wait(&s);
			printf("\nParent\n");
			printf("\nChild returned:%d\n",s );
		}
	return 0;
}