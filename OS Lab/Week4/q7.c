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
	fd=open("vrushank.txt",O_RDWR);
	read(fd,buf,sizeof(buf));
	close(fd);
	fd2=creat("lelel.txt",O_RDWR);
	int i=0;
	while(buf[i]>='a' && buf[i]<='z')
	{
		i++;
	}
	buf[i]='\0';
	write(fd2,buf,strlen(buf));
	close(fd2);
	return 0;
}