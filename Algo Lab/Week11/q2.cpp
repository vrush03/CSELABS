#include <bits/stdc++.h>
using namespace std;
int inc[1000]={0};

int minDistance(int dist[],int n)
{
   // Initialize min value
   int min = 99999, min_index;
  
   for (int v = 0; v < n; v++)
     if (inc[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
void findAns(int graph[][100],int n,int s){
	
	int min=999;
	int ans[1000],i;
	for(i=0;i<n;i++)
		ans[i]=9999;
	ans[s]=0;
	for(i=0;i<n-1;i++){
		min=minDistance(ans,n);
		inc[min]=1;
		for (int v = 0; v < n; v++)
  				if (!inc[v] && graph[min][v] && ans[min] != 9999 
                                       && ans[min]+graph[min][v] < ans[v])
            ans[v] = ans[min] + graph[min][v];	
	}

	for(i=0;i<n;i++)
	{
		cout<<i<<"->"<<ans[i]<<endl;
	}
}
int main(int argc, char const *argv[])
{
	int graph[100][100],source;
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			graph[i][j]=9999;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin>>graph[i][j];
	}
	cin>>source;
	findAns(graph,n,source);
	return 0;
}