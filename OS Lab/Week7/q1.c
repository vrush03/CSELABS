#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char const *argv[])
{
	int a,i,j,b,c,s,fid[2],arr[100],brr[100];
	pid_t p;
	pipe(fid);
	p=fork();
	if(p == 0)
	{
		a=-1;
		b=1;
		for(i=0;i<25;i++)
		{
			c=a+b;
			printf("%d ",c );
			a=b;
			b=c;
			arr[i]=c;
		}
		printf("\n");
		write(fid[1],arr,25*sizeof(int));
	
	}
	else
	{
		wait(NULL);
		read(fid[0],brr,25*sizeof(int));
		int flag=0;
		
		for(i=3;i<25;i++)
		{
			flag=0;
			for(j=2;j<=brr[i]/2;j++)
			{
				if(brr[i]%j == 0)
				{
					flag=1;
					break;
				}
			}
			if(flag == 0)
				printf("%d ",brr[i] );
		}
		printf("\n");
	
	}
	return 0;
}