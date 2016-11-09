#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fd,fd2;
	char buf[1000];
	scanf("%s",buf);
	fd=creat("vrushank.txt",O_RDWR);
	printf("%d\n",fd );
	write(fd,buf,strlen(buf));
	return 0;
}