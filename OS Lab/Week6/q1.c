#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int total,left,size,n,j;
	printf("Enter Total Memory:\n");
	scanf("%d",&total);
	int ftotal=total;
	printf("Enter Block size:\n");
	scanf("%d",&size);
	printf("Enter Number of Processes:\n");
	scanf("%d",&n);
	int i=0,dat,mem[1000],frag[1000];
	char str[100][100];
	while(i<n)
	{
		printf("Enter Memory required for process %d:\n",i+1 );
		scanf(" %d",&dat);
		
		if (dat <= size)
		{
			ftotal-=size;
			if(ftotal <= 0)
				break;
			mem[i]=dat;
			frag[i]=size-dat;
			strcpy(str[i],"Yes");
		}
		else
		{
			strcpy(str[i],"No");
		}
		i++;
	}
	if(i<n)
	{
	printf("Cannot be Allocated Anymore\n");
	printf("Number of Blocks Allocated:%d\n",i );
	printf("\tId \tMemory \tAllocated \tFragmentation\n");
	for(j=0;j<n;j++)
		printf("\t%d \t%d \t%s\t\t%d\n",j+1,mem[j],str[j],frag[j] );

	int sum=0;
	for(j=0;j<i;j++)
		sum+=frag[j];
	printf("Total Internal Fragmentation:%d\n",sum);
	printf("Total External Fragmentation:%d\n",-1*ftotal);

	}
	else
	{
		printf("\tId \tMemory \tAllocated \tFragmentation\n");
	for(i=0;i<n;i++)
		printf("\t%d \t%d \t%s\t%d\n",i+1,mem[i],str[i],frag[i] );
	int sum=0;
	for(j=0;j<i;j++)
		sum+=frag[j];
	printf("Total Internal Fragmentation:%d\n",sum);
	printf("Total External Fragmentation:%d\n",-1*ftotal);

	}
	return 0;
}