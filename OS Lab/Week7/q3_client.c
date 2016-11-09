#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesgq{
	long mtype;
	char mtext[100];
};

int main()
{
	int qt;
	struct mesgq m;
	qt = msgget(1902,IPC_CREAT | IPC_EXCL | 0600);
	if(qt < 0)
	{
		perror("Error in getting message \n");
	}
	printf("Message Queue Created \n");
	if(msgrcv(qt,&m,sizeof(struct mesgq),0,0) < 0)
	{
		perror("error in receiving \n");
	}
	printf("Message received %s \n",m.mtext);

	return 0;
}


