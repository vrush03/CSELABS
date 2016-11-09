#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,f,k,blocks[1000],files[1000],i,j,visited[1000]={0},min=999,mem[1000],indbl[1000],p=0;
	printf("Enter Number of Block:\n");
	scanf("%d",&n);
	printf("Enter Number of Files:\n");
	scanf("%d",&f);
	//printf("Enter Size of Blocks:\n");
	for (i = 0; i < n; ++i)
	{
		printf("Enter Size of Block %d:\n",i+1);
		scanf("%d",&blocks[i]);
		mem[i]=blocks[i];
	}
	for ( i = 0; i < f; ++i)
	{
		printf("Enter Size of File %d:\n",i+1);
		scanf("%d",&files[i]);
	}
	for(i=0;i<f;i++)
	{
		for(j=0;j<n;j++)
		{
			int ans=blocks[j]-files[i];
			if(visited[j]!=1 && min>=ans && min>0)
			{
				k=j;
				min=ans;
			}
		}
		visited[k]=1;
		indbl[p++]=k;
		mem[k]-=files[i];
	}
	printf("\tFile No.\tFile Size\tBlock no\tBlock size\tFragment\n");
	for(i=0;i<f;i++)
	{
		printf("\t%d \t\t%d \t\t%d \t\t%d \t\t%d\n",i+1,files[i],indbl[i]+1,blocks[indbl[i]],mem[i] );
	}
	return 0;
}