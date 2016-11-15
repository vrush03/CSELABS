#include <bits/stdc++.h>
using namespace std;
int c=0;
void max_heap(int a[],int i,int n)
{
	if(i<=0)
		return;
	int p;
	//int ch2;
	if(i%2==1)
		p=i/2;
	else
		p=(i/2)-1;
	if(a[p]>a[i])
		return;
	else
	{
		swap(a[p],a[i]);
		c++;
		max_heap(a,p,n);
	}
}
int main(int argc, char const *argv[])
{
	int a[1000],i;
	int n;
	cin>>n;
	for(i=0;i<n;i++)
	{	
		cin>>a[i];
		max_heap(a,i,n);
	}
	
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"Count:"<<c;
	cout<<endl;
	
	return 0;
}