#include <stdio.h>
#include <stdlib.h>

void Display(int arr[][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]);	
		printf("\n");	
	}
}
int main()
{
	int arr[100][100];
	int n,a,b;
	int i,j;
	scanf("%d",&n);	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=0;
	int ch;	
	while(1)
	{
		printf("1.Insert 2.Display 3.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter The vertex from where edge begins:\n");
			scanf("%d",&a);
			printf("Enter The vertex to where edge ends:\n");
			scanf("%d",&b);
			arr[a][b]=1;
		}
		else if(ch==2)
		{
			Display(arr,n);
		}
		else
			break;
	}
	return 0;
}
