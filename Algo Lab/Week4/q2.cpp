#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int visited[10000]={0};
struct Graph
{
	int n;
	list<int> adj[1000];
};
void addEdge(struct Graph *g,int v,int w)
{
	g->adj[v].push_back(w); //push to stack
}
void DFSut(struct Graph *g,int visited[],int v)
{
	visited[v]=1;
	cout<<v<<" "; //popback
	list<int>::iterator i;
	for(i=g->adj[v].begin();i!=g->adj[v].end();i++)
	{
		if(visited[*i]==0)
			DFSut(g,visited,*i);
	}
}
void DFS(struct Graph *g,int v)
{
	DFSut(g,visited,v);
}
int main(int argc, char const *argv[])
{
	struct Graph *g=new Graph();
	cout<<"Enter Number of Vertices:\n";
	int n;
	int a,b;
	list<int>::iterator i;
	cin>>n;
	g->n=n;
	int ch,v;
	while(1)
	{
		cout<<"1.Enter 2.Exit\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter Source and Destination of the edge:";
			cin>>a>>b;
			//cout<"Enter Destination of the edge:";
			//cin>>b;
			addEdge(g,a,b);
		}
		else
			break;
	}
	cout<<"Enter The Vertex to DFS:";
	cin>>v;
	DFS(g,v);
	cout<<endl;
	return 0;
}