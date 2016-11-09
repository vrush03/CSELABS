#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>

struct mesgq{
	long mtype;
	char mtext[100];
};

int main()
{
	int qt;
	struct mesgq m;
	qt = msgget(1902,0);
	if(qt < 0)
	{
		perror("Error in creating queue");

	}
	printf("Enter a message \n");
	gets(m.mtext);
	m.mtype = 1;
	if(msgsnd(qt,&m,sizeof(struct mesgq),0) < 0)
	{
		perror("Message send error \n");
	}
	printf("Message sent \n");
	return 0;
}