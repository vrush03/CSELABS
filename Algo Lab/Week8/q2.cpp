#include <bits/stdc++.h>
using namespace std;
int c=0;
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
		c++;
		heapify(a,n,max);
	}
}
void buildheap(int a[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		heapify(a,n,i);
	}
}
void heapsort(int a[],int n)
{
	int i=0;
	for(i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		c++;
		heapify(a,i,0);
	}

}
int main(int argc, char const *argv[])
{
	int a[1000],i;
	int n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	//sort(a,0,n-1);
	buildheap(a,n);
	heapsort(a,n);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"Count:";
	cout<<c<<endl;
	
	return 0;
}