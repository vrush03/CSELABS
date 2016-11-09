#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char const *argv[])
{
	int fid[2];
	pipe(fid);
	if(fork() == 0)
	{
		close(1);
		dup(fid[1]);
		close(fid[0]);
		execlp("who","who",NULL);

	}
	else
	{
		close(0);
		dup(fid[0]);
		close(fid[1]);
		execlp("wc","wc","-l",NULL);
	}
	return 0;
}