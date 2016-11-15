#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int c=0;

int sumof(int a[],int n)
{
	int i=0,sum=0;
	for(i=0;i<n;i++)
	{
		//printf("%d ",a[i] );
		sum+=a[i];
		//c++;
	}
	return sum;
}
int disjoint(int a[],int b[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j] && a[i]!=0 && b[j]!=0)
				return 0;
			//c++;
		}
		c++;
	}
	return 1;
}
int main()
{
	int a[1000],n,temp,i,j;
	int ultra[1000][1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int p=pow(2,n);
	int k=0,l=0;
	for(i=0;i<p;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i & (1<<j))
			{
				
				ultra[k][l++]=a[j];
			}
			//c++;
		}
	
	k++;
	l=0;
	}
	
	/*for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",ultra[i][j] );
		printf("\n");
	}*/
	for(i=0;i<p;i++)
	{
		for(j=i+1;j<p;j++)
		{
			
			if(sumof(ultra[i],n)==sumof(ultra[j],n) && disjoint(ultra[i],ultra[j],n)==1)
			{
				printf("\n");
				for(k=0;k<n;k++)
				{
					if(ultra[i][k]!=0)
						printf("%d ",ultra[i][k] );
				}
				printf("\nand\n");
				for(k=0;k<n;k++)
				{	
					if(ultra[j][k]!=0)
						printf("%d ",ultra[j][k] );
				}
				printf("\n");
			}
			c++;
		}
		//printf("%d ",sumof(ultra[i],n)) ;
		//for(j=0;j<n;j++)
			//printf("%d ",ultra[i][j] );
		//printf("\n");
	}
	printf("%d \n",c);
	return 0;
}