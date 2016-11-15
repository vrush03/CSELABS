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
void BFS(struct Graph *g,int v)
{
	list<int> qu;
	visited[v]=1;
	qu.push_back(v);
	while(qu.empty()==0)
	{
		v=qu.front();
		cout<<v<<" ";
		qu.pop_front();
		list<int>::iterator i;
		for(i=g->adj[v].begin();i!=g->adj[v].end();i++)
		{
			if(visited[*i]==0)
				{
					visited[*i]=1;
					qu.push_back(*i);
					//DFSut(g,visited,*i);
				}
		}
	}
}
int main()
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
	cout<<"Enter The Vertex to BFS:";
	cin>>v;
	BFS(g,v);
	cout<<endl;
	return 0;
}