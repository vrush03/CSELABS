#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

void Display(int arr[][100],int n,int W)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
			printf("%d ",arr[i][j]);	
		printf("\n");	
	}
	cout<<endl;
}
void printSub(int dp[][100],int n,int w,int weight[10])
{
	while(w!=0)
	{
		//cout<<n<<" ";
		if(dp[n][w] > dp[n-1][w])
		{
			cout<<n<<" "<<w<<" "<<endl;
			//cout<<dp[n][w]<<" ";
			w = w-weight[n-1];
			n--;
		}
		else
			n--;
	}
	cout<<"\n";
}

int knap(int dp[100][100],int val[100],int weight[100],int i,int j)
{
	int value;
	if ( weight[i-1] <= j)
		value = max(val[i-1] + knap(dp,val,weight,i-1,j-weight[i-1]),  knap(dp,val,weight,i-1,j));
	else
		value = knap(dp,val,weight,i-1,j);
	dp[i][j]=value;
	return dp[i][j];
}
int main(int argc, char const *argv[])
{
	int n,dp[100][100],W,w,weight[100],val[100];
	cout<<"Enter number of Items:";
	cin>>n;
	cout<<"Enter Capacity:";
	cin>>W;
	cout<<"Enter Weight:\n";
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=w;j++)
			dp[i][j]=-1;
	for(i=0;i<n;i++)
		cin>>weight[i];
	cout<<"Enter Cost:\n";
	for ( i = 0; i < n; ++i)
	{
		cin>>val[i];
	}
	for(i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(i=0;i<=W;i++)
		dp[0][W]=0;
	 // for (i = 0; i <= n; i++)
  //  	{
  //      for (w = 0; w <= W; w++)
  //      {
  //          if (i==0 || w==0)
  //              dp[i][w] = 0;
  //          else if (weight[i-1] <= w)
  //                dp[i][w] = max(val[i-1] + dp[i-1][w-weight[i-1]],  dp[i-1][w]);
  //          else
  //                dp[i][w] = dp[i-1][w];
  //      }
  //  	}
   cout<<knap(dp,val,weight,n,W)<<endl;
   Display(dp,n,W);
   //printSub(dp,n,W,weight);

	return 0;
}