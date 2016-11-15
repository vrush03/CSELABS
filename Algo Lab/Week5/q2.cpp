#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int visited[10000]={0};
stack<int> s;
struct Graph
{
	int n;
	list<int> adj[1000];
};
void addEdge(struct Graph *g,int v,int w)
{
	g->adj[v].push_back(w); //push to stack
}

void topological(struct Graph *g,int n)
{
	vector<int> in(n);
	int i,c=0,a[1000],k=0;
	for(i=0;i<n;i++)
		in[i]=0;
	for(i=0;i<n;i++)
	{
		list<int>::iterator j;
		for(j=g->adj[i].begin();j!=g->adj[i].end();j++)
		{
			in[*j]++;
		}
	}
	queue<int> q;
	//vector<int> ans;
	for(i=0;i<n;i++)
	{
		if(in[i]==0)
			q.push(i);
	}

	while(q.empty()==0)
	{
		a[k++]=q.front();
		int ad=q.front();
		//cout<<q.front()<<" ";
		q.pop();
		list<int>::iterator j;
		for(j=g->adj[ad].begin();j!=g->adj[ad].end();j++)
		{
			in[*j]--;
			if(in[*j]==0)
				q.push(*j);
		}
		c++;
	}
	if(c!=n)
		cout<<"A cycle\n";
	else
		for(i=0;i<k;i++)
			cout<<a[i]<<" ";
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
	//cout<<"Enter The Vertex to DFS:";
	//cin>>v;
	topological(g,n);
	cout<<endl;
	return 0;
}