#include <stdio.h>
#include <stdlib.h>

int count=0;
int c[1000][1000],n,ans[1000];
int ul[1000][1000];
int min=10000;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void getans(char a[],int c[][1000],int n)
{

	int b[1000];
	int i;
	for(i=0;i<n;i++)
	{
		b[i]=a[i]-'0';
	}
	int sum=0;
	for(i=0;i<n;i++)
		sum+=c[i][b[i]];
	if(min>sum)
	{	
		min=sum;
		for(i=0;i<n;i++)
			ans[i]=b[i]+1;
	}		
}
void permute(char a[], int l, int r,int c[][1000])

{
   int i;
   if (l == r)
     getans(a,c,n);
     //printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          count++;
          swap((a+l), (a+i));
          permute(a, l+1, r, c);
          swap((a+l), (a+i)); 
       }
   }
}

int main(int argc, char const *argv[])
{
	
	scanf("%d",&n);
	int i,j;
	char a[1000];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&c[i][j]);
	}
	int l=0,k=0;
	for(i=0;i<n;i++)
	{
		a[i]=i+'0';

	}
	//printf("%s\n",a );
	permute(a,0,n-1,c);
	printf("%d\n",min );
	for(i=0;i<n;i++)
	{
		printf("%d ",ans[i] );

	}
	printf("\n");
	printf("Count:%d\n",count);
	//printCombination(a,n,n);
	return 0;
}