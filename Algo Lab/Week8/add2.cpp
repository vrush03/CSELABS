#include <bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i)
{
	int max=i;
	int ch1=2*i+1;
	int ch2=2*i+2;
	if(ch1<n && a[max]<a[ch1])
		max=ch1;
	if(ch2<n && a[max]<a[ch2])
		max=ch2;
	if(max!=i)
	{
		swap(a[max],a[i]);
		heapify(a,n,max);
	}
}
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
	cout<<"Enter The element to delete:\n";
	int item;
	cin>>item;
	for(i=0;i<n;i++)
		if(a[i]==item)
			break;

	swap(a[i],a[n-1]);
	n--;
	heapify(a,n,0);
	/*if(a[i]>a[2*i+1] && a[i]>a[2*i+2])
	{
		max_heap(a,i,n);
	}
	else
	{
		heapify(a,n,i);
	}*/	
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}