#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int s;
	pid_t pid;
	//printf("\n");
	pid=fork();
	if(pid==0)
	{
		printf("Child here:\n");
		execvp(argv[1],&argv[1]);
		exit(15);
	}
	else
	{
		wait(&s);
		printf("Parent after child is dead\n");
	}
	//perror("exec fail\n");
	//exit(1);
	return 0;
}