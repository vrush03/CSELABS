#include <bits/stdc++.h>
using namespace std;

int parent[20],v,e;
typedef struct edge
{
	int src,dest,w;
}edges;

edges arr[100],ans[100];
int find(int i)
{
	return parent[i];
}

int unionf(int a, int b)
{
	for(int i = 1; i <=v; i++)
	{
		if(parent[i] == b)
			parent[i] = a;
	}
}

int kruskal()
{
	int a, b, n1 =1;
	for(int i = 1; i<= e; i++)
	{
		a = find(arr[i].src);
		b = find(arr[i].dest);

		if(a!=b)
		{
			ans[n1].src = arr[i].src;
			ans[n1].dest = arr[i].dest;
			ans[n1].w = arr[i].w;
			n1 ++;
			unionf(a,b);

		}
	}

	printf("Kruskals edges:\n");
	for (int i = 1; i <n1 ; ++i)
	{
		printf("Edge :%d source %d dest %d weight %d \n",i,ans[i].src,ans[i].dest,ans[i].w );
	}


}

int main()
{
	cout << "Enter the number of vertices \n";
	cin >> v;
	cout << "Enter the number of edges \n";
	cin >> e;

	for(int i = 1; i <= e; i++)
	{
		cin >> arr[i].src >> arr[i].dest >> arr[i].w;
	}
	

	for(int i = 1; i <= e; i++)
	{
		edges temp;
		for(int j = i+1; j<=e; j++)
		{
			if(arr[i].w > arr[j].w)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for(int i = 1;i <= e; i++)
	{
		parent[i] = i;
	}

	kruskal();


	return 0;
	
}