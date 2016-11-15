#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int ans[100][100];
void Display(int arr[][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]);	
		printf("\n");	
	}
	cout<<endl;
}
void FloydAlgo(int arr[][100],int n)
{
	
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			ans[i][j]=arr[i][j];
	}
	//Display(ans[0],n);
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(ans[i][j] > (ans[i][k]+ans[k][j]))
					ans[i][j]=ans[i][k]+ans[k][j];
				//ans[i][j] = ans[i][j] || (ans[i][k] && ans[k][j]);
				//Display(ans[k],n);
			}
		}
	}

}
int main()
{
	int arr[100][100],data;
	int n,a,b;
	int i,j;
	scanf("%d",&n);	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			arr[i][j]=99999;
			if(i == j)
				arr[i][j]=0;
		}
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
			cout<<"Enter Value of the Edge:\n";
			cin>>data;
			arr[a][b]=data;
		}
		else if(ch==2)
		{
			Display(arr,n);
		}
		else
			break;
	}
	FloydAlgo(arr,n);
	cout<<"Array after FloydAlgo is:\n";
	Display(ans,n);
	return 0;
}